
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include "h3rapi.h"
#include "h3rc.h"

SEXP h3rcLatLngToCell(SEXP lat, SEXP lon, SEXP res) {
  return h3rLatLngToCell(lat, lon, res);
}


// SEXP h3rcDirectionForNeighbour(SEXP origin, SEXP destination) {
//
//   H3Index o;
//   stringToH3(CHAR(STRING_ELT(origin, 0)), &o);
//   H3Index d;
//   stringToH3(CHAR(STRING_ELT(destination, 0)), &d);
//
//   // Direction dir = directionForNeighbor(o, d);
//   SEXP direction = PROTECT(Rf_allocVector(INTSXP, 1));
//   //
//   // SET_INTEGER_ELT(direction, 0, dir);
//
//   UNPROTECT(1);
//   return direction;
// }
