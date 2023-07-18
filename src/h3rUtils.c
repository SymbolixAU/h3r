
#include "h3rUtils.h"

#include <inttypes.h>

#include <stdbool.h>

bool isSingleLength(SEXP x) {
  return Rf_xlength(x) == 1;
}


int _getResolution(SEXP resolution, R_xlen_t idx) {
  R_xlen_t i = isSingleLength(resolution) ? 0 : idx;
  return INTEGER_ELT(resolution, i);
}

void sexpToLatLng(LatLng *latLng, SEXP lat, SEXP lng, R_xlen_t idx) {
  latLng->lat = degsToRads(REAL(lat)[idx]);
  latLng->lng = degsToRads(REAL(lng)[idx]);
}

void doubleToLatLng(LatLng *latLng, double lat, double lng) {
  latLng->lat = degsToRads(lat);
  latLng->lng = degsToRads(lng);
}


H3Index sexpStringToH3(SEXP h3, R_xlen_t idx) {
  H3Index index;
  h3rError(stringToH3(CHAR(STRING_ELT(h3, idx)), &index), idx);
  return index;
}

SEXP h3ToSexpString(H3Index h3) {
  char str[17];
  //h3ToString(h3, str, sizeof(str));
  snprintf(str, sizeof(str), "%" PRIx64, h3);
  return Rf_mkChar(str);
}

SEXP h3VecToSexpString(H3Index *h3, R_xlen_t n) {
  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));
  R_xlen_t i;
  for( i = 0; i < n; i++ ) {
    H3Index index = h3[ i ];
    SET_STRING_ELT(out, i, h3ToSexpString(index));
  }

  UNPROTECT(1);
  return out;
}

void latLngToSexp(LatLng *latLng, SEXP lats, SEXP lons, R_xlen_t idx) {
  double lat = radsToDegs(latLng->lat);
  double lng = radsToDegs(latLng->lng);

  SET_REAL_ELT(lats, idx, lat);
  SET_REAL_ELT(lons, idx, lng);
}

SEXP latLngList(SEXP lats, SEXP lons, SEXP rowNames) {
  const char *names[] = {"lat","lng",""};
  SEXP res = PROTECT(mkNamed(VECSXP, names));

  SET_VECTOR_ELT(res, 0, lats);
  SET_VECTOR_ELT(res, 1, lons);

    // Class
  SEXP cls = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(cls, 0, Rf_mkChar("data.frame"));

  Rf_setAttrib(res, R_ClassSymbol, cls);
  Rf_setAttrib(res, R_RowNamesSymbol, rowNames);

  UNPROTECT(2);
  return res;
}

SEXP origDestList(SEXP orig, SEXP dest) {
  const char *names[] = {"origin","destination",""};
  SEXP res = PROTECT(mkNamed(VECSXP, names));

  SET_VECTOR_ELT(res, 0, orig);
  SET_VECTOR_ELT(res, 1, dest);
  UNPROTECT(1);
  return res;
}

SEXP gridDistList(SEXP grid, SEXP dist) {
  const char *names[] = {"cell","distance",""};
  SEXP res = PROTECT(mkNamed(VECSXP, names));

  SET_VECTOR_ELT(res, 0, grid);
  SET_VECTOR_ELT(res, 1, dist);
  UNPROTECT(1);
  return res;
}

SEXP coordIJList(SEXP i, SEXP j) {
  const char *names[] = {"i","j",""};
  SEXP res = PROTECT(mkNamed(VECSXP, names));

  SET_VECTOR_ELT(res, 0, i);
  SET_VECTOR_ELT(res, 1, j);
  UNPROTECT(1);
  return res;
}

SEXP cellBoundaryToList(CellBoundary *cb) {
  SEXP lats = PROTECT(Rf_allocVector(REALSXP, cb->numVerts));
  SEXP lons = PROTECT(Rf_allocVector(REALSXP, cb->numVerts));
  SEXP rowNames = PROTECT(Rf_allocVector(INTSXP, cb->numVerts));
  for( int i = 0; i < cb->numVerts; i++) {
    SET_INTEGER_ELT(rowNames, i, i + 1);
    SET_REAL_ELT(lats, i, radsToDegs(cb->verts[i].lat));
    SET_REAL_ELT(lons, i, radsToDegs(cb->verts[i].lng));
  }
  UNPROTECT(3);
  return latLngList(lats, lons, rowNames);
}

SEXP intToSexpArray(int *arr, R_xlen_t n) {

  SEXP out = PROTECT(Rf_allocVector(INTSXP, n));
  R_xlen_t i;
  for(i = 0; i < n; i++) {
    SET_INTEGER_ELT(out, i, arr[i]);
  }
  UNPROTECT(1);
  return out;
}

char* h3rErrorToString(int err) {
    switch (err) {
        case 0:
            return "E_SUCCESS: Success (no error)";
        case 1:
            return "E_FAILED: The operation failed but a more specific error is not available";
        case 2:
            return "E_DOMAIN: Argument was outside of acceptable range (when a more specific error code is not available)";
        case 3:
            return "E_LATLNG_DOMAIN: Latitude or longitude arguments were outside of acceptable range";
        case 4:
            return "E_RES_DOMAIN: Resolution argument was outside of acceptable range";
        case 5:
            return "E_CELL_INVALID: H3Index cell argument was not valid";
        case 6:
            return "E_DIR_EDGE_INVALID: H3Index directed edge argument was not valid";
        case 7:
            return "E_UNDIR_EDGE_INVALID: H3Index undirected edge argument was not valid";
        case 8:
            return "E_VERTEX_INVALID: H3Index vertex argument was not valid";
        case 9:
            return "E_PENTAGON: Pentagon distortion was encountered which the algorithm could not handle it";
        case 10:
            return "E_DUPLICATE_INPUT: Duplicate input was encountered in the arguments and the algorithm could not handle it";
        case 11:
            return "E_NOT_NEIGHBORS: H3Index cell arguments were not neighbors";
        case 12:
            return "E_RES_MISMATCH: H3Index cell arguments had incompatible resolutions";
        case 13:
            return "E_MEMORY_ALLOC: Necessary memory allocation failed";
        case 14:
            return "E_MEMORY_BOUNDS: Bounds of provided memory were not large enough";
        case 15:
            return "E_OPTION_INVALID: Mode or flags argument was not valid";
        default:
            return "Unknown error code";
    }
}

void h3rError(int err, R_xlen_t i) {
  if (err) {
    const char* errStr = h3rErrorToString(err);
    error("h3r - Error at item number %td: %s\n", i + 1, errStr);
  }
}

void h3rVectorLengthCheck(R_xlen_t checkValue, R_xlen_t *lengthVectors, R_xlen_t n, bool canBeSingle) {
  R_xlen_t i;
  for(i = 0; i < n; i++) {
    R_xlen_t l = lengthVectors[i];
    if(canBeSingle && l == 1) {
      continue;
    }
    if(l != checkValue) {
      error("h3r - Error: Input vectors do not have consistent length\n");
    }
  }
}

