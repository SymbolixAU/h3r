
#include "h3libapi.h"
#include "h3rUtils.h"

void sexpToLatLng(LatLng *latLng, SEXP lat, SEXP lon, R_xlen_t idx) {
  latLng->lat = degsToRads(REAL(lat)[idx]);
  latLng->lng = degsToRads(REAL(lon)[idx]);
}

H3Index sexpStringToH3(SEXP h3, R_xlen_t idx) {
  H3Index index;
  stringToH3(CHAR(STRING_ELT(h3, idx)), &index);
  return index;
}

SEXP h3ToSexpString(H3Index h3) {
  char str[17];
  h3ToString(h3, str, sizeof(str));
  return Rf_mkChar(str);
}

//
// SEXP h3VecToSexpString(H3Index *h3, R_xlen_t n) {
//   SEXP out = PROTECT(Rf_allocVector(STRSXP, n));
//   R_xlen_t i;
//   for( i = 0; i < n; i++ ) {
//     H3Index index = h3[ i ];
//     SET_STRING_ELT(out, i, h3ToSexpString(index));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
//
// void latLngToSexp(LatLng *latLng, SEXP lats, SEXP lons, R_xlen_t idx) {
//   double lat = radsToDegs(latLng->lat);
//   double lon = radsToDegs(latLng->lng);
//
//   SET_REAL_ELT(lats, idx, lat);
//   SET_REAL_ELT(lons, idx, lon);
// }
//
// SEXP latLngList(SEXP lats, SEXP lons) {
//   const char *names[] = {"lat","lng",""};
//   SEXP res = PROTECT(mkNamed(VECSXP, names));
//
//   SET_VECTOR_ELT(res, 0, lats);
//   SET_VECTOR_ELT(res, 1, lons);
//   UNPROTECT(1);
//   return res;
// }
//
//
// SEXP cellBoundaryToList(CellBoundary *cb) {
//    SEXP lats = PROTECT(Rf_allocVector(REALSXP, cb->numVerts));
//    SEXP lons = PROTECT(Rf_allocVector(REALSXP, cb->numVerts));
//    for( int i = 0; i < cb->numVerts; i++) {
//      SET_REAL_ELT(lats, i, radsToDegs(cb->verts[i].lat));
//      SET_REAL_ELT(lons, i, radsToDegs(cb->verts[i].lng));
//    }
//    UNPROTECT(2);
//    return latLngList(lats, lons);
// }
//
// SEXP intToSexpArray(int *arr, R_xlen_t n) {
//
//   SEXP out = PROTECT(Rf_allocVector(INTSXP, n));
//   R_xlen_t i;
//   for(i = 0; i < n; i++) {
//     SET_INTEGER_ELT(out, i, arr[i]);
//   }
//   UNPROTECT(1);
//   return out;
// }

