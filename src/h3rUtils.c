
#include "h3rUtils.h"

void sexpToLatLng(LatLng *latLng, SEXP lat, SEXP lon, R_xlen_t idx) {
  latLng->lat = degsToRads(REAL(lat)[idx]);
  latLng->lng = degsToRads(REAL(lon)[idx]);
}

H3Index sexpStringToH3(SEXP h3, R_xlen_t idx) {
  H3Index index;
  h3error(stringToH3(CHAR(STRING_ELT(h3, idx)), &index), idx);
  return index;
}

SEXP h3ToSexpString(H3Index h3) {
  char str[17];
  h3ToString(h3, str, sizeof(str));
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
  double lon = radsToDegs(latLng->lng);

  SET_REAL_ELT(lats, idx, lat);
  SET_REAL_ELT(lons, idx, lon);
}

SEXP latLngList(SEXP lats, SEXP lons) {
  const char *names[] = {"lat","lng",""};
  SEXP res = PROTECT(mkNamed(VECSXP, names));

  SET_VECTOR_ELT(res, 0, lats);
  SET_VECTOR_ELT(res, 1, lons);
  UNPROTECT(1);
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


SEXP cellBoundaryToList(CellBoundary *cb) {
  SEXP lats = PROTECT(Rf_allocVector(REALSXP, cb->numVerts));
  SEXP lons = PROTECT(Rf_allocVector(REALSXP, cb->numVerts));
  for( int i = 0; i < cb->numVerts; i++) {
    SET_REAL_ELT(lats, i, radsToDegs(cb->verts[i].lat));
    SET_REAL_ELT(lons, i, radsToDegs(cb->verts[i].lng));
  }
  UNPROTECT(2);
  return latLngList(lats, lons);
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

char* h3errorToString(int err) {
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

void h3error(int err, R_xlen_t i) {
  if (err) {
    const char* errStr = h3errorToString(err);
    error("h3r - Error at item number %td: %s\n", i + 1, errStr);
  }
}
