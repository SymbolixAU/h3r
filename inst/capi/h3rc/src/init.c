
#include "h3rc.h"

// #include <h3rapi.h>
// #include <h3api.h>

#include <Rconfig.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* Function Definitions for {h3rc} */
static const R_CallMethodDef callMethods[] = {
  {"h3rcLatLngToCell",    (DL_FUNC) &h3rcLatLngToCell,  3},
  // {"h3rcDirectionForNeighbour", (DL_FUNC) &h3rcDirectionForNeighbour},
  {NULL, NULL, 0}
};

/* Imports from h3r */
// int (*directionForNeighbor)(H3Index, H3Index);
// SEXP (*h3rLatLngToCell)(SEXP,SEXP,SEXP);
// void (*h3LatLngToCell)(const LatLng *g, int res, H3Index *out);

void R_init_h3rc(DllInfo *info)

{
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(info, FALSE);

  /* Imports from h3r */
  // directionForNeighbor = (int(*)(H3Index origin, H3Index destination)) R_GetCCallable("h3r","directionForNeighbor") ;
  // h3LatLngToCell = ((*)const LatLng *g, int res, H3Index *out)
  // h3rLatLngToCell = (SEXP(*)(SEXP,SEXP,SEXP)) R_GetCCallable("h3r", "h3rLatLngToCell");
}
