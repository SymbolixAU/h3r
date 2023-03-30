// // #define R_NO_REMAP
// #include <R.h>
// #include <Rinternals.h>
// #include <Rdefines.h>
//
// #include "h3libapi.h"
//
// #include "h3rUtils.h"
//
// SEXP h3rCellToVertex(SEXP h3, SEXP vertexNum) {
//   R_xlen_t n = Rf_xlength(h3);
//   R_xlen_t i;
//
//   SEXP out = PROTECT(Rf_allocVector(STRSXP, n));
//
//   for( i = 0; i < n; i++ ) {
//     H3Index index = sexpStringToH3(h3, i);
//     H3Index vertex;
//     int v = INTEGER(vertexNum)[i];
//     cellToVertex(index, v, &vertex);
//     SET_STRING_ELT(out, i, h3ToSexpString(vertex));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
//
// SEXP h3rCellToVertexes(SEXP h3) {
//   R_xlen_t n = Rf_xlength(h3);
//   R_xlen_t i;
//
//   SEXP names = PROTECT(Rf_allocVector(STRSXP, n));
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, n));
//
//   for( i = 0; i < n; i++ ) {
//     H3Index index = sexpStringToH3(h3, i);
//     H3Index v[6];
//     cellToVertexes(index, v);
//
//     SET_VECTOR_ELT(out, i, h3VecToSexpString(v, 6));
//     SET_STRING_ELT(names, i, STRING_ELT(h3, i));
//
//   }
//
//   Rf_setAttrib(out, R_NamesSymbol, names);
//
//   UNPROTECT(2);
//   return out;
// }
//
//
// SEXP h3rVertexToLatLng(SEXP h3) {
//
//   R_xlen_t n = Rf_xlength(h3);
//   R_xlen_t i;
//
//   SEXP lats = PROTECT(Rf_allocVector(REALSXP, n));
//   SEXP lons = PROTECT(Rf_allocVector(REALSXP, n));
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, 2));
//
//   LatLng point;
//   for( i = 0; i < n; i++ ) {
//     H3Index index = sexpStringToH3(h3, i);
//
//     vertexToLatLng(index, &point);
//     latLngToSexp(&point, lats, lons, i);
//   }
//   SET_VECTOR_ELT(out, 0, lats);
//   SET_VECTOR_ELT(out, 1, lons);
//
//   UNPROTECT(3);
//   return out;
// }
//
// SEXP h3rIsValidVertex(SEXP h3) {
//   R_xlen_t n = Rf_xlength(h3);
//   R_xlen_t i;
//
//   SEXP out = PROTECT(Rf_allocVector(INTSXP, n));
//   for( i = 0; i < n; i++ ) {
//     SET_INTEGER_ELT(out, i, isValidVertex(sexpStringToH3(h3, i)));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
//
