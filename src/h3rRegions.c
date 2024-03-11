// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"


void destroyGeoPolygon(GeoPolygon *geoPolygon) {
  free(geoPolygon->geoloop.verts);

  int numHoles = geoPolygon->numHoles;
  if (numHoles > 0) {
    GeoLoop *holes = geoPolygon->holes;
    for (int i = 0; i < numHoles; i++) {
      free(holes[i].verts);
    }
    free(holes);
  }
}


void h3rPolygonArrayToGeoLoop(LatLng *polygonArray, int length, GeoLoop *geoLoop){
  R_xlen_t i;
  geoLoop->numVerts = length;
  geoLoop->verts = (LatLng *)malloc(length * sizeof(LatLng));
  for (i = 0; i < length; i++){
    geoLoop->verts[i] = polygonArray[i];
  }
}

/**
 * H3r Matrix To Lat Lng
 *
 * Converts a SEXP (REAL) matrix to an array of `LatLng`
 */
void h3rMatrixToLatLng(SEXP matrix, LatLng *latLng, int reverseCoordinates, int nrow) {
  // A SEXP matrix is a vector with dimensions.

  // SEXP dim = Rf_getAttrib(matrix, R_DimSymbol);
  // int nrow = INTEGER(dim)[0];
  // int ncol = INTEGER(dim)[1];

  R_xlen_t i;
  double * p = REAL(matrix);
  for( i = 0; i < nrow; i++) {
    double lat = p[ i ];
    double lng = p[ i + nrow ];

    if( reverseCoordinates ) {
      doubleToLatLng(&latLng[i], lat, lng);
    } else {
      doubleToLatLng(&latLng[i], lng, lat);
    }
  }
}

void h3rCoordinatesToGeoPolygon(SEXP polygons, GeoPolygon *geoPolygon, int isLatLng){
  R_xlen_t n = Rf_xlength(polygons);
  R_xlen_t i, numVerts[n], numHoles;

  numHoles = n - 1;

  LatLng **polygonArray = (LatLng **)malloc(n * sizeof(LatLng*));

  // Convert the SEXP polygon[][][lat, lng] to LatLng[][]
  for (i = 0; i < n; i++) {
    SEXP polygon = VECTOR_ELT(polygons, i);
    SEXP dim = Rf_getAttrib(polygon, R_DimSymbol);
    int nrow = INTEGER(dim)[0];
    numVerts[i] = nrow;

    polygonArray[i] = (LatLng *)malloc(numVerts[i] * sizeof(LatLng));

    h3rMatrixToLatLng(polygon, polygonArray[i], isLatLng, nrow);
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

SEXP singlePolygonToCells(SEXP polygon, int res, SEXP isLatLng, R_xlen_t idx) {
  uint32_t flags = 0;
  int64_t numHexagons, i;
  int64_t validCount = 0;
  int64_t j = 0;

  GeoPolygon geoPolygon;

  int reverseCoordinates = INTEGER(isLatLng)[0];

  h3rCoordinatesToGeoPolygon(polygon, &geoPolygon, reverseCoordinates);

  h3rError(maxPolygonToCellsSize(&geoPolygon, res, flags, &numHexagons), idx);

  H3Index *result = (H3Index *)calloc(numHexagons, sizeof(H3Index));

  h3rError(polygonToCells(&geoPolygon, res, flags, result), idx);

  for (i = 0; i < numHexagons; i++){
    if( isValidCell(result[i])){
      validCount++;
    }
  }

  H3Index out[validCount];

  for (i = 0; i < numHexagons; i++){
    if( isValidCell(result[i])){
      out[j] = result[i];
      j++;
    }
  }

  free(result);
  destroyGeoPolygon(&geoPolygon);

  SEXP group = h3VecToSexpString(out, validCount);

  return group;
}

// TODO:
// this needs to work on a vector of polygonArray (i.e.., list(list(matrix)) )
SEXP h3rPolygonToCells(SEXP polygonArray, SEXP res, SEXP isLatLng) {

  R_xlen_t nPolygons = Rf_xlength(polygonArray);
  R_xlen_t i;

  R_xlen_t optionalLengths[1];
  optionalLengths[0] = Rf_xlength(res);
  h3rVectorLengthCheck(nPolygons, optionalLengths, 1, true);

  SEXP out = PROTECT(Rf_allocVector(VECSXP, nPolygons));

  for(i = 0; i < nPolygons; i++) {
    SEXP polygon = VECTOR_ELT(polygonArray, i);
    int ires = _getResolution(res, i);
    SEXP cells = singlePolygonToCells(polygon, ires, isLatLng, i);
    SET_VECTOR_ELT(out, i, cells);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rReadMultiPolygon(LinkedGeoPolygon *polygon, int isLatLng) {
    SEXP output, loops, coords;
    R_xlen_t polygonCount = 0, loopCount, coordCount;
    R_xlen_t pIdx, lIdx, cIdx;

    LinkedGeoPolygon *currentPolygon = polygon;
    while (currentPolygon) {
        polygonCount++;
        currentPolygon = currentPolygon->next;
    }

    PROTECT(output = Rf_allocVector(VECSXP, polygonCount));

    pIdx = 0;
    while (polygon) {
        loopCount = 0;

        LinkedGeoLoop *loop = polygon->first;
        while (loop) {
            loopCount++;
            loop = loop->next;
        }

        PROTECT(loops = Rf_allocVector(VECSXP, loopCount));

        loop = polygon->first;
        lIdx = 0;
        while (loop) {
            coordCount = 0;

            LinkedLatLng *coord = loop->first;
            while (coord) {
                coordCount++;
                coord = coord->next;
            }

            PROTECT(coords = Rf_allocVector(REALSXP, coordCount * 2)); // *2 because `coord` is a LatLng obj (2 coords per struct)

            coord = loop->first;
            cIdx = 0;
            while (coord) {
                if (isLatLng) {
                  SET_REAL_ELT(coords, cIdx, radsToDegs(coord->vertex.lat));
                  SET_REAL_ELT(coords, cIdx + coordCount, radsToDegs(coord->vertex.lng));
                } else {
                  SET_REAL_ELT(coords, cIdx, radsToDegs(coord->vertex.lng));
                  SET_REAL_ELT(coords, cIdx + coordCount, radsToDegs(coord->vertex.lat));
                }
                coord = coord->next;
                cIdx++;
            }

            // set matrix DIM attributes
            SEXP dim = PROTECT(Rf_allocVector(INTSXP, 2));
            INTEGER(dim)[0] = cIdx; // rows
            INTEGER(dim)[1] = 2;    // cols
            Rf_setAttrib(coords, R_DimSymbol, dim);
            UNPROTECT(1);  // dim

            SET_VECTOR_ELT(loops, lIdx, coords);
            UNPROTECT(1);  // coords

            loop = loop->next;
            lIdx++;
        }

        SET_VECTOR_ELT(output, pIdx, loops);
        UNPROTECT(1);

        polygon = polygon->next;
        pIdx++;
    }

    destroyLinkedMultiPolygon(currentPolygon);

    UNPROTECT(1);

    return output;
}


// SEXP singleCellsToMultiPolygon(SEXP h3Sets, int geojson, R_xlen_t idx) {
//   R_xlen_t n = Rf_xlength(h3Sets);
//   R_xlen_t i;
//   int64_t j, setSize;
//
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, n));
//
//   for (i = 0; i < n; i++) {
//     SEXP h3Set = VECTOR_ELT(h3Sets, i);
//     setSize = Rf_xlength(h3Set);
//
//     H3Index cellSet[setSize];
//     memset(cellSet, -1, sizeof(cellSet));
//
//     for (j = 0; j < setSize; j++) {
//       cellSet[j] = sexpStringToH3(h3Set, j);
//     }
//
//     LinkedGeoPolygon geoPolygon;
//
//     h3rError(cellsToLinkedMultiPolygon(cellSet, setSize, &geoPolygon), idx);
//
//     SET_VECTOR_ELT(out, i, h3rReadMultiPolygon(&geoPolygon, geojson));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
//
// SEXP h3rCellsToMultiPolygon(SEXP h3Sets, SEXP isLatLng) {
//   R_xlen_t n = Rf_xlength(h3Sets);
//   R_xlen_t i ;
//
//   int geojson = INTEGER(isLatLng)[0];
//
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, n));
//
//   for (i = 0; i < n; i++) {
//     SEXP h3Set = VECTOR_ELT(h3Sets, i);
//     SEXP multiPolygon = singleCellsToMultiPolygon(h3Set, geojson, i);
//     SET_VECTOR_ELT(out, i, multiPolygon);
//   }
//
//   UNPROTECT(1);
//   return out;
// }
