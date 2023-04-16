// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

void h3rPolygonArrayToGeoLoop(LatLng *polygonArray, int length, GeoLoop *geoLoop){
  R_xlen_t i;
  geoLoop->numVerts = length;
  geoLoop->verts = (LatLng *)malloc(length * sizeof(LatLng));
  for (i = 0; i < length; i++){
    geoLoop->verts[i] = polygonArray[i];
  }
}

void h3rCoordinatesToGeoPolygon(SEXP polygons, GeoPolygon *geoPolygon, SEXP isGeoJson){
  R_xlen_t n = Rf_xlength(polygons);
  R_xlen_t i, j, numVerts[n], numHoles;

  numHoles = n - 1;

  int geoJson = INTEGER(isGeoJson)[0];

  LatLng **polygonArray = (LatLng **)malloc(n * sizeof(LatLng*));

  // Convert the SEXP polygon[][][lat, lng] to LatLng[][]
  for (i = 0; i < n; i++) {
      SEXP polygon = VECTOR_ELT(polygons, i);
      numVerts[i] = Rf_xlength(polygon);

      polygonArray[i] = (LatLng *)malloc(numVerts[i] * sizeof(LatLng));

      for (j = 0; j < numVerts[i]; j++) {
        SEXP vertex = VECTOR_ELT(polygon, j);
        if (geoJson){
          doubleToLatLng(&polygonArray[i][j], REAL(vertex)[1], REAL(vertex)[0]);
        } else {
          doubleToLatLng(&polygonArray[i][j], REAL(vertex)[0], REAL(vertex)[1]);
        }
      }
  }

  // Convert the outer loop
  h3rPolygonArrayToGeoLoop(polygonArray[0], numVerts[0], &geoPolygon->geoloop);

  // Allocate memory for holes and convert inner loops (holes)
  if (numHoles > 0) {
      geoPolygon->holes = (GeoLoop *)malloc(numHoles * sizeof(GeoLoop));

      for (int i = 0; i < numHoles; i++) {
          h3rPolygonArrayToGeoLoop(polygonArray[i + 1], numVerts[i + 1], &geoPolygon->holes[i]);
      }
  } else {
      geoPolygon->holes = NULL;
  }

  geoPolygon->numHoles = numHoles;

  // Free allocated memory
  for (R_xlen_t i = 0; i < n; i++) {
      free(polygonArray[i]);
  }
  free(polygonArray);
}

SEXP h3rPolygonToCells(SEXP polygonArray, SEXP res, SEXP isGeoJson) {
    int ires = INTEGER(res)[0];
    uint32_t flags = 0;
    int64_t numHexagons, i, k;
    int64_t validCount = 0;
    int64_t j = 0;

    GeoPolygon geoPolygon;
    h3rCoordinatesToGeoPolygon(polygonArray, &geoPolygon, isGeoJson);

    // for (i = 0; i < geoPolygon.geoloop.numVerts; i++){
    //   fprintf(stdout, "geoloop.verts[%lld].lat: %f \n", i, geoPolygon.geoloop.verts[i].lat);
    //   fprintf(stdout, "geoloop.verts[%lld].lng: %f \n", i, geoPolygon.geoloop.verts[i].lng);
    // }
    // for (i = 0; i < geoPolygon.numHoles; i++){
    //   for (k = 0; k < geoPolygon.holes[i].numVerts; k++){
    //     fprintf(stdout, "holes[%lld].verts[%lld].lat: %f \n", i, k, geoPolygon.holes[i].verts[k].lat);
    //     fprintf(stdout, "holes[%lld].verts[%lld].lng: %f \n", i, k, geoPolygon.holes[i].verts[k].lng);
    //   }
    // }

    h3error(maxPolygonToCellsSize(&geoPolygon, ires, flags, &numHexagons), 0);
    // fprintf(stdout, "numHexagons %lld \n", numHexagons);

    // H3Index result[numHexagons];

    H3Index *result = (H3Index *)calloc(numHexagons, sizeof(H3Index));

    h3error(polygonToCells(&geoPolygon, ires, flags, result), 0);

    for (i = 0; i < numHexagons; i++){
     if( isValidCell(result[i])){
      validCount++;
     }
    }
    // fprintf(stdout, "validCount %lld \n", validCount);

    H3Index out[validCount];

    for (i = 0; i < numHexagons; i++){
     if( isValidCell(result[i])){
      out[j] = result[i];
      j++;
     }
    }

    // fprintf(stdout, "j valid: %lld \n", j);

    SEXP group = h3VecToSexpString(out, validCount);

    return group;
}

SEXP h3rReadMultiPolygon(LinkedGeoPolygon *polygon, int formatAsGeoJson) {
    SEXP output, loops, coords, coordPair;
    R_xlen_t polygonCount = 0, loopCount, coordCount;
    R_xlen_t pIdx, lIdx, cIdx;

    LinkedGeoPolygon *currentPolygon = polygon;
    while (currentPolygon) {
        polygonCount++;
        currentPolygon = currentPolygon->next;
    }
    PROTECT(output = allocVector(VECSXP, polygonCount));

    pIdx = 0;
    while (polygon) {
        loopCount = 0;

        LinkedGeoLoop *loop = polygon->first;
        while (loop) {
            loopCount++;
            loop = loop->next;
        }

        PROTECT(loops = allocVector(VECSXP, loopCount));

        loop = polygon->first;
        lIdx = 0;
        while (loop) {
            coordCount = 0;

            LinkedLatLng *coord = loop->first;
            while (coord) {
                coordCount++;
                coord = coord->next;
            }

            PROTECT(coords = allocVector(VECSXP, coordCount));

            coord = loop->first;
            cIdx = 0;
            while (coord) {
              PROTECT(coordPair = allocVector(REALSXP, 2));
                if (formatAsGeoJson) {
                    SET_REAL_ELT(coordPair, 0, radsToDegs(coord->vertex.lng));
                    SET_REAL_ELT(coordPair, 1, radsToDegs(coord->vertex.lat));
                } else {
                    SET_REAL_ELT(coordPair, 0, radsToDegs(coord->vertex.lat));
                    SET_REAL_ELT(coordPair, 1, radsToDegs(coord->vertex.lng));
                }

                SET_VECTOR_ELT(coords, cIdx, coordPair);
                UNPROTECT(1);

                coord = coord->next;
                cIdx++;
            }
            SET_VECTOR_ELT(loops, lIdx, coords);
            UNPROTECT(1);

            loop = loop->next;
            lIdx++;
        }

        SET_VECTOR_ELT(output, pIdx, loops);
        UNPROTECT(1);

        polygon = polygon->next;
        pIdx++;
    }

    UNPROTECT(1);

    return output;
}


SEXP h3rCellsToMultiPolygon(SEXP h3Sets, SEXP isGeoJson) {
  R_xlen_t n = Rf_xlength(h3Sets);
  R_xlen_t i;
  int64_t j, setSize;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for (i = 0; i < n; i++) {
    int geoJson = INTEGER(isGeoJson)[i];
    SEXP h3Set = VECTOR_ELT(h3Sets, i);
    setSize = Rf_xlength(h3Set);

    H3Index cellSet[setSize];

    for (j = 0; j < setSize; j++) {
      cellSet[j] = sexpStringToH3(h3Set, j);
    }

    LinkedGeoPolygon geoPolygon;

    h3error(cellsToLinkedMultiPolygon(cellSet, setSize, &geoPolygon), i);

    SET_VECTOR_ELT(out, i, h3rReadMultiPolygon(&geoPolygon, geoJson));

    UNPROTECT(1);
  }

  UNPROTECT(1);
  return out;
}
