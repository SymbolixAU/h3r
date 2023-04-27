
#ifndef R_H3RC_H
#define R_H3RC_H

#include <Rinternals.h>

#include "h3rapi.h"

SEXP h3rcLatLngToCell(SEXP lat, SEXP lon, SEXP res);

// SEXP h3rcDirectionForNeighbour(H3Index origin, H3Index destination);


#endif
