
// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

SEXP h3rLatLngToCell(SEXP lat, SEXP lon, SEXP res) {

  R_xlen_t n = Rf_xlength(lat);
  R_xlen_t i;
  SEXP cells = PROTECT(Rf_allocVector(STRSXP, n));

  LatLng latLng;
  H3Index h3Index;
  // char str[17];

  for( i = 0; i < n; i++ ) {
    int ires = INTEGER(res)[i];

    sexpToLatLng(&latLng, lat, lon, i);

    h3rError(latLngToCell(&latLng, ires, &h3Index), i);
    // h3ToString(h3Index, str, 17);

    SET_STRING_ELT(cells, i, h3ToSexpString(h3Index));
  }

  UNPROTECT(1);
  return cells;
}


SEXP h3rCellToLatLng(SEXP h3) {

  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  LatLng ll;

  SEXP lats = PROTECT(Rf_allocVector(REALSXP, n));
  SEXP lons = PROTECT(Rf_allocVector(REALSXP, n));

  for( i = 0; i < n; i++ ) {
    H3Index index = sexpStringToH3(h3, i);
    //int isValid = isValidCell(index);
    //if( !isValid ) {
    //  fprintf(stderr, "Invlaid H3");
    //}
    h3rError(cellToLatLng(index, &ll), i);
    latLngToSexp(&ll, lats, lons, i);
  }

  SEXP res = latLngList(lats, lons);
  UNPROTECT(2);

  return res;
}


SEXP h3rCellToBoundary(SEXP h3) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;
  SEXP names = PROTECT(Rf_allocVector(STRSXP, n));

  // TODO:
  // what structure should be returned?
  // - list of named-lists ?
  // - data.frame with h3, lat, lng columns?
  //H3Index index;
  CellBoundary cb;
  //LatLng ll;

  SEXP res = PROTECT(Rf_allocVector(VECSXP, n)); // store he results in a list
  // where each element be named as per the cell, adn the valeus will be the lon/lat

  for( i = 0; i < n; i++ ) {

    H3Index index = sexpStringToH3(h3, i);

    h3rError(cellToBoundary(index, &cb), i);
    SEXP lst = cellBoundaryToList(&cb);

    SET_STRING_ELT(names, i, STRING_ELT(h3, i));
    SET_VECTOR_ELT(res, i, lst);
  }

  Rf_setAttrib(res, R_NamesSymbol, names);

  UNPROTECT(2);
  return res;
}
