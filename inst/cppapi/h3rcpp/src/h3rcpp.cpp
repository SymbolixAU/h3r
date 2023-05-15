
#include <Rcpp.h>
#include "h3rapi.h"

// [[Rcpp::export]]
SEXP h3rcppLatLngToCell(SEXP lat, SEXP lon, SEXP res) {
  return h3r::latLngToCell(lat, lng, res);
}
