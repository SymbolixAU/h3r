
// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include <stdbool.h>

#include "h3libapi.h"

#include "h3rUtils.h"

SEXP h3rCellToParent(SEXP h3, SEXP parentResolution) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  R_xlen_t optionalLength[1];
  optionalLength[0] = Rf_xlength(parentResolution);
  h3rVectorLengthCheck(n, optionalLength, 1, true);

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));
  for(i = 0; i < n; i++) {
    int res = _getResolution(parentResolution, i);
    H3Index index = sexpStringToH3(h3, i);
    H3Index parent;
    h3rError(cellToParent(index, res, &parent), i);
    SET_STRING_ELT(out, i, h3ToSexpString(parent));
  }

  UNPROTECT(1);
  return out;
}



SEXP h3rCellToChildren(SEXP h3, SEXP childResolution) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  R_xlen_t optionalLength[1];
  optionalLength[0] = Rf_xlength(childResolution);
  h3rVectorLengthCheck(n, optionalLength, 1, true);

  SEXP names = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP out = PROTECT(Rf_allocVector(VECSXP, n)); // store the results in a list
  // where each element be named as per the cell, and the values will be the child indexes

  for( i = 0; i < n; i++ ) {

    H3Index index = sexpStringToH3(h3, i);
    int res = _getResolution(childResolution, i);

    int64_t childrenSize;
    h3rError(cellToChildrenSize(index, res, &childrenSize), i);

    if (childrenSize > 282000000){
      error("h3r - Error at item number %td: children size is too large to process \n", i);
    }

    H3Index* children = (H3Index*) malloc(childrenSize * sizeof(H3Index));
    h3rError(cellToChildren(index, res, children), i);

    SEXP childIndexes = h3VecToSexpString(children, childrenSize);

    free(children);

    SET_VECTOR_ELT(out, i, childIndexes);
    SET_STRING_ELT(names, i, STRING_ELT(h3, i));
  }

  Rf_setAttrib(out, R_NamesSymbol, names);

  UNPROTECT(2);
  return out;

}

SEXP h3rCellToChildrenSize(SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  R_xlen_t optionalLength[1];
  optionalLength[0] = Rf_xlength(res);
  h3rVectorLengthCheck(n, optionalLength, 1, true);

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n));

  H3Index h;
  int64_t num;
  int ires;

  for( i = 0; i < n; i++ ) {
    ires = _getResolution(res, i);

    h = sexpStringToH3(h3, i);
    h3rError(cellToChildrenSize(h, ires, &num), i);

    SET_REAL_ELT(out, i, (double)num);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rCellToCenterChild(SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  R_xlen_t optionalLength[1];
  optionalLength[0] = Rf_xlength(res);
  h3rVectorLengthCheck(n, optionalLength, 1, true);

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, child;
  int ires;

  for( i = 0; i < n; i++ ) {
    ires = _getResolution(res, i);
    h = sexpStringToH3(h3, i);
    h3rError(cellToCenterChild(h, ires, &child), i);
    SET_STRING_ELT(out, i, h3ToSexpString(child));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rCellToChildPos(SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  R_xlen_t optionalLength[1];
  optionalLength[0] = Rf_xlength(res);
  h3rVectorLengthCheck(n, optionalLength, 1, true);

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n));

  H3Index h;
  int ires;
  int64_t num;

  for( i = 0; i < n; i++ ) {
    ires = _getResolution(res, i);
    h = sexpStringToH3(h3, i);
    h3rError(cellToChildPos(h, ires, &num), i);

    SET_REAL_ELT(out, i, (double)num);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rChildPosToCell(SEXP pos, SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  R_xlen_t vectorLength[2];
  vectorLength[0] = n;
  vectorLength[1] = Rf_xlength(pos);
  h3rVectorLengthCheck(n, vectorLength, 2, false);

  R_xlen_t optionalLength[1];
  optionalLength[0] = Rf_xlength(res);
  h3rVectorLengthCheck(n, optionalLength, 1, true);

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, child;
  int ires;
  int64_t childPos;

  for( i = 0; i < n; i++ ) {
    ires = _getResolution(res, i);
    h = sexpStringToH3(h3, i);
    childPos = (int64_t)REAL(pos)[i];
    h3rError(childPosToCell(childPos, h, ires, &child), i);
    SET_STRING_ELT(out, i, h3ToSexpString(child));
  }

  UNPROTECT(1);
  return out;
}

// SEXP h3rCompactCells(SEXP h3Sets) {
//   R_xlen_t n = Rf_xlength(h3Sets);
//   R_xlen_t i;
//   int64_t j, setSize, outputSize;
//
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, n));
//
//   for (i = 0; i < n; i++) {
//     SEXP h3Set = VECTOR_ELT(h3Sets, i);
//     setSize = Rf_xlength(h3Set);
//
//     H3Index cellSet[setSize];
//     H3Index compactedSet[setSize];
//
//     for (j = 0; j < setSize; j++) {
//       cellSet[j] = sexpStringToH3(h3Set, j);
//     }
//
//     h3rError(compactCells(cellSet, compactedSet, setSize), i);
//
//     j = 0;
//     while (j < setSize && isValidCell(compactedSet[j])) {
//       j++;
//     }
//     outputSize = j;
//
//     SET_VECTOR_ELT(out, i, h3VecToSexpString(compactedSet, outputSize));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
//
// SEXP h3rUncompactCells(SEXP h3Sets, SEXP res) {
//   R_xlen_t n = Rf_xlength(h3Sets);
//   R_xlen_t i;
//
//   R_xlen_t optionalLength[1];
//   optionalLength[0] = Rf_xlength(res);
//   h3rVectorLengthCheck(n, optionalLength, 1, true);
//
//   int64_t j, setSize, cellSize;
//
//   SEXP out = PROTECT(Rf_allocVector(VECSXP, n));
//
//   int ires;
//
//   for (i = 0; i < n; i++) {
//     SEXP h3Set = VECTOR_ELT(h3Sets, i);
//     setSize = Rf_xlength(h3Set);
//
//     H3Index compactedSet[setSize];
//     ires = _getResolution(res, i);
//
//     for (j = 0; j < setSize; j++) {
//       compactedSet[j] = sexpStringToH3(h3Set, j);
//     }
//
//     h3rError(uncompactCellsSize(compactedSet, setSize, ires, &cellSize), i);
//     H3Index cellSet[cellSize];
//
//     h3rError(uncompactCells(compactedSet, setSize, cellSet, cellSize, ires), i);
//
//     SET_VECTOR_ELT(out, i, h3VecToSexpString(cellSet, cellSize));
//   }
//
//   UNPROTECT(1);
//   return out;
// }
