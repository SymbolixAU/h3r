//
// // #define R_NO_REMAP
// #include <R.h>
// #include <Rinternals.h>
// #include <Rdefines.h>
//
// #include "h3libapi.h"
//
// #include "h3rUtils.h"
//
// SEXP h3rCellToParent(SEXP h3, SEXP parentResolution) {
//
//   R_xlen_t n = Rf_xlength(h3);
//   R_xlen_t i;
//
//   SEXP out = PROTECT(Rf_allocVector(STRSXP, n));
//   for(i = 0; i < n; i++) {
//     int res = INTEGER_ELT(parentResolution, i);
//     H3Index index = sexpStringToH3(h3, i);
//     H3Index parent;
//     cellToParent(index, res, &parent);
//     SET_STRING_ELT(out, i, h3ToSexpString(parent));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
//
//
//
// SEXP h3rCellToChildren(SEXP h3, SEXP childResolution) {
//   R_xlen_t n = Rf_xlength(h3);
//   R_xlen_t i;
//
//   SEXP names = PROTECT(Rf_allocVector(STRSXP, n));
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, n)); // store he results in a list
//   // where each element be named as per the cell, and the values will be the child indexes
//
//   for( i = 0; i < n; i++ ) {
//
//     H3Index index = sexpStringToH3(h3, i);
//
//     int res = INTEGER_ELT(childResolution, i);
//
//     int64_t childrenSize;
//     cellToChildrenSize(index, res, &childrenSize);
//
//     H3Index children[ childrenSize ];
//     cellToChildren(index, res, children);
//
//     SEXP childIndexes = h3VecToSexpString(children, childrenSize);
//
//     SET_VECTOR_ELT(out, i, childIndexes);
//     SET_STRING_ELT(names, i, STRING_ELT(h3, i));
//   }
//
//   Rf_setAttrib(out, R_NamesSymbol, names);
//
//   UNPROTECT(2);
//   return out;
//
// }
