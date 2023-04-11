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
      geoPolygon->holes = (GeoLoop *)calloc(numHoles, sizeof(GeoLoop));

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
    int64_t count;

    GeoPolygon geoPolygon;
    h3rCoordinatesToGeoPolygon(polygonArray, &geoPolygon, isGeoJson);

    warning("geoloop.verts[0].lat: %f", geoPolygon.geoloop.verts[0].lat);
    warning("geoloop.verts[1].lng: %f", geoPolygon.geoloop.verts[1].lng);
    warning("geoloop.verts[2].lat: %f", geoPolygon.geoloop.verts[2].lat);
    warning("geoPolygon.numHoles: %d", geoPolygon.numHoles);


    h3error(maxPolygonToCellsSize(&geoPolygon, ires, flags, &count), 0);

    warning("count: %d", count);
    warning("ires: %d", ires);

    H3Index result[count];

    h3error(polygonToCells(&geoPolygon, ires, flags, result), 0);

    SEXP group = h3VecToSexpString(result, count);

    return group;
}
