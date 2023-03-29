// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

SEXP h3rAreNeighborCells(SEXP origH3, SEXP destH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(INTSXP, n));

  H3Index origin, destination;
  int result;

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);
    areNeighborCells(origin, destination, &result);
    SET_INTEGER_ELT(out, i, result);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rCellsToDirectedEdge(SEXP origH3, SEXP destH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index origin, destination, edge;

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);
    cellsToDirectedEdge(origin, destination, &edge);
    SET_STRING_ELT(out, i,h3ToSexpString(edge));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rIsValidDirectedEdge(SEXP edge) {
  R_xlen_t n = Rf_xlength(edge);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(INTSXP, n));
  H3Index h;

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(edge, i);
    SET_INTEGER_ELT(out, i, isValidDirectedEdge(h));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rGetDirectedEdgeOrigin(SEXP edge) {
  R_xlen_t n = Rf_xlength(edge);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, origin;

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(edge, i);
    getDirectedEdgeOrigin(h, &origin);
    SET_STRING_ELT(out, i, h3ToSexpString(origin));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rGetDirectedEdgeDestination(SEXP edge) {
  R_xlen_t n = Rf_xlength(edge);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, destination;

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(edge, i);
    getDirectedEdgeDestination(h, &destination);
    SET_STRING_ELT(out, i, h3ToSexpString(destination));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rDirectedEdgeToCells(SEXP edge) {
  R_xlen_t n = Rf_xlength(edge);
  R_xlen_t i;

  SEXP orig = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP dest = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index h, origDest[2];

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(edge, i);
    directedEdgeToCells(h, origDest);
    SET_STRING_ELT(orig, i, h3ToSexpString(origDest[0]));
    SET_STRING_ELT(dest, i, h3ToSexpString(origDest[1]));
  }

  SEXP out = origDestList(orig, dest);

  UNPROTECT(2);
  return out;
}


SEXP h3rOriginToDirectedEdges(SEXP origH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;
  int j;
  int m = 6;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  H3Index origin, edges[m];

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    originToDirectedEdges(origin, edges);

    SEXP group = PROTECT(Rf_allocVector(STRSXP, m));

    for( j = 0; j < m; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(edges[j]));
    }

    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }

  UNPROTECT(1);
  return out;
}

// TODO:
// SEXP h3rDirectedEdgeToBoundary(SEXP edge)
