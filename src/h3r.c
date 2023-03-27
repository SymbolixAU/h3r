
// // #define R_NO_REMAP
// #include <R.h>
// #include <Rinternals.h>
// #include <Rdefines.h>
//
// #include "h3api.h"
// #include "algos.h"
//
// #include "h3rUtils.h"
//
// SEXP h3StringToH3(SEXP h) {
//   R_xlen_t n = Rf_xlength(h);
//
//   SEXP h3 = PROTECT(Rf_allocVector(REALSXP, n));
//   H3Index* h3Index = (H3Index*) REAL(h3);
//
//   R_xlen_t i;
//   // SEXP h3;
//   for( i = 0; i < n; i++ ) {
//     stringToH3(CHAR(STRING_ELT(h, i)), &h3Index[i]);
//   }
//
//   UNPROTECT(1);
//   return h3;
// }
//
// SEXP h3H3ToString(SEXP h) {
//
//   R_xlen_t n = Rf_xlength(h);
//   H3Index* h3 = (H3Index*) REAL(h);
//
//   SEXP result = PROTECT(Rf_allocVector(STRSXP, n));
//
//   char str[17];
//
//   R_xlen_t i;
//   for( i = 0; i < n; i++ ) {
//     h3ToString(h3[i], str, sizeof(str));
//     SET_STRING_ELT(result, i, Rf_mkChar(str));
//   }
//
//   UNPROTECT(1);
//   return result;
// }

// SEXP h3DirectionForNeighbor(SEXP origin, SEXP destination) {
//
//     // TODO:
//     // origin && destination to H3Index;
//     // call directionForNeighbor
//     // convert direction to SEXP
//     // return
//     R_xlen_t n = Rf_xlength(origin);
//     H3Index* h3Origin = (H3Index*) REAL(origin);
//     H3Index* h3Destination = (H3Index*) REAL(destination);
//
//     SEXP result = PROTECT(Rf_allocVector(INTSXP, n));
//
//     R_xlen_t i;
//     for( i = 0; i < n; i++ ) {
//       Direction d = directionForNeighbor(h3Origin[i], h3Destination[i]);
//       SET_INTEGER_ELT(result, i, d);
//     }
//
//     UNPROTECT(1);
//     return result;
// }

// TODO:
// forward the H3-C calls as-is
// provide vectorised SEXP versions




// SEXP h3maxGridDiskSize(SEXP k) {
//
//   R_xlen_t n = Rf_length(k);
//   R_xlen_t i;
//
//   SEXP out = PROTECT(Rf_allocVector(INTSXP, n));
//
//   for( i = 0; i < n; i++) {
//     int kRing = INTEGER_ELT(k, i);
//
//
//   }
//
//   UNPROTECT(1);
//   return out;
//
// }

// SEXP h3gridDiskUnsafe(SEXP origins, SEXP k) {
//
//   R_xlen_t n = Rf_length(origins);
//   R_xlen_t i;
//
//   SEXP result = PROTECT(Rf_allocVector(STRSXP, n));
//   int64_t outSize;
//
//   for(i = 0; i < n; i++) {
//
//     H3Index origin = sexpStringToH3(origins, i);
//
//     int this_k = INTEGER_ELT(k, i);
//     maxGridDiskSize(this_k, &outSize);
//
//     H3Index out[outSize];
//     gridDiskUnsafe(origin, this_k, &out);
//
//
//   }
//
//   unprotect(1);
//   return result;
//
// }
