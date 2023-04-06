// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

void h3rPolygonArrayToGeoLoop(LatLng **polygonArray, int length, GeoLoop *geoLoop){
  geoLoop->numVerts = length;
  geoLoop->verts = *polygonArray;
}

void h3rCoordinatesToGeoPolygon(SEXP polygons, GeoPolygon *geoPolygon, SEXP isGeoJson){
  R_xlen_t n = Rf_xlength(polygons);
  R_xlen_t i, j, numVerts[n], numHoles;

  numHoles = n - 1;

  int geoJson = INTEGER(isGeoJson)[0];

  LatLng **polygonArray = (LatLng **)malloc(n * sizeof(LatLng*));

  // Convert the SEXP polhygon[][][lat, lng] to LatLng[][]
  for (i = 0; i < n; i++) {
      SEXP polygon = VECTOR_ELT(polygons, i);
      numVerts[i] = Rf_xlength(polygon);

      polygonArray[i] = (LatLng *)malloc(numVerts[i] * sizeof(LatLng));

      for (j = 0; j < numVerts[i]; j++) {
        SEXP vertex = VECTOR_ELT(polygon, j);
        if (geoJson){
        SEXP vertex = VECTOR_ELT(polygon, i);
          doubleToLatLng(&polygonArray[i][j], REAL_ELT(vertex, 1), REAL_ELT(vertex, 0));
        } else {
          doubleToLatLng(&polygonArray[i][j], REAL_ELT(vertex, 0), REAL_ELT(vertex, 1));
        }
      }
  }

  // Convert the outer loop
  h3rPolygonArrayToGeoLoop(&polygonArray[0], numVerts[0], &geoPolygon->geoloop);

  // Allocate memory for holes and convert inner loops (holes)
  if (numHoles > 0) {
      geoPolygon->holes = (GeoLoop *)calloc(numHoles, sizeof(GeoLoop));

      for (int i = 0; i < numHoles; i++) {
          h3rPolygonArrayToGeoLoop(&polygonArray[i + 1], numVerts[i + 1], &geoPolygon->holes[i]);
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

    h3error(maxPolygonToCellsSize(&geoPolygon, ires, flags, &count), 0);

    H3Index result[count];

    h3error(polygonToCells(&geoPolygon, ires, flags, result), 0);

    SEXP group = h3VecToSexpString(result, count);

    return group;
}
