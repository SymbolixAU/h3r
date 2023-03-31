
// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

SEXP h3rCellToParent(SEXP h3, SEXP parentResolution) {

  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));
  for(i = 0; i < n; i++) {
    int res = INTEGER_ELT(parentResolution, i);
    H3Index index = sexpStringToH3(h3, i);
    H3Index parent;
    h3error(cellToParent(index, res, &parent), i);
    SET_STRING_ELT(out, i, h3ToSexpString(parent));
  }

  UNPROTECT(1);
  return out;
}



SEXP h3rCellToChildren(SEXP h3, SEXP childResolution) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  SEXP names = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP out = PROTECT(Rf_allocVector(VECSXP, n)); // store the results in a list
  // where each element be named as per the cell, and the values will be the child indexes

  for( i = 0; i < n; i++ ) {

    H3Index index = sexpStringToH3(h3, i);

    int res = INTEGER_ELT(childResolution, i);

    int64_t childrenSize;
    h3error(cellToChildrenSize(index, res, &childrenSize), i);

    H3Index children[ childrenSize ];
    h3error(cellToChildren(index, res, children), i);

    SEXP childIndexes = h3VecToSexpString(children, childrenSize);

    SET_VECTOR_ELT(out, i, childIndexes);
    SET_STRING_ELT(names, i, STRING_ELT(h3, i));
  }

  Rf_setAttrib(out, R_NamesSymbol, names);

  UNPROTECT(2);
  return out;

}

SEXP h3rCellToCenterChild(SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, child;
  int ires;

  for( i = 0; i < n; i++ ) {
    ires = INTEGER(res)[i];
    h = sexpStringToH3(h3, i);
    h3error(cellToCenterChild(h, ires, &child), i);
    SET_STRING_ELT(out, i, h3ToSexpString(child));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rCellToChildPos(SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n));

  H3Index h;
  int ires;
  int64_t num;

  for( i = 0; i < n; i++ ) {
    ires = INTEGER(res)[i];
    h = sexpStringToH3(h3, i);
    h3error(cellToChildPos(h, ires, &num), i);

    SET_REAL_ELT(out, i, (double)num);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rChildPosToCell(SEXP pos, SEXP h3, SEXP res) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, child;
  int ires;
  int64_t childPos;

  for( i = 0; i < n; i++ ) {
    ires = INTEGER(res)[i];
    h = sexpStringToH3(h3, i);
    childPos = (int64_t)REAL(pos)[i];
    h3error(childPosToCell(childPos, h, ires, &child), i);
    SET_STRING_ELT(out, i, h3ToSexpString(child));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rCompactCells(SEXP h3Sets) {
  R_xlen_t n = Rf_xlength(h3Sets);
  R_xlen_t i;
  int64_t j, setSize;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for (i = 0; i < n; i++) {
    SEXP h3Set = VECTOR_ELT(h3Sets, i);
    setSize = Rf_xlength(h3Set);

    H3Index cellSet[setSize];
    H3Index compactedSet[setSize];

    for (j = 0; j < setSize; j++) {
      cellSet[j] = sexpStringToH3(h3Set, j);
    }

    h3error(compactCells(cellSet, compactedSet, setSize), i);

    SEXP compactedGroup = PROTECT(Rf_allocVector(STRSXP, setSize));

    for (j = 0; j < setSize; j++) {
      SET_STRING_ELT(compactedGroup, j, h3ToSexpString(compactedSet[j]));
    }

    SET_VECTOR_ELT(out, i, compactedGroup);
    UNPROTECT(1);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rUncompactCells(SEXP h3Sets, SEXP res) {
  R_xlen_t n = Rf_xlength(h3Sets);
  R_xlen_t i;
  int64_t j, setSize, maxCells;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  int ires;

  for (i = 0; i < n; i++) {
    SEXP h3Set = VECTOR_ELT(h3Sets, i);
    setSize = Rf_xlength(h3Set);

    H3Index compactedSet[setSize];
    ires = INTEGER(res)[i];
    
    for (j = 0; j < setSize; j++) {
      compactedSet[j] = sexpStringToH3(h3Set, j);
    }

    h3error(uncompactCellsSize(compactedSet, setSize, ires, &maxCells), i);
    H3Index cellSet[maxCells];

    h3error(uncompactCells(compactedSet, setSize, cellSet, maxCells, ires), i);

    SEXP uncompactedGroup = PROTECT(Rf_allocVector(STRSXP, maxCells));

    for (j = 0; j < maxCells; j++) {
      SET_STRING_ELT(uncompactedGroup, j, h3ToSexpString(cellSet[j]));
    }

    SET_VECTOR_ELT(out, i, uncompactedGroup);
    UNPROTECT(1);
  }

  UNPROTECT(1);
  return out;
}
