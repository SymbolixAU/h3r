
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

#include "h3rapi.h"
#include "h3rc.h"

SEXP h3rcLatLngToCell(SEXP lat, SEXP lon, SEXP res) {
  return h3rLatLngToCell(lat, lon, res);
}
