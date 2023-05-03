
#include <R.h>
#include <Rconfig.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>

#include "h3rc.h"

/* Function Definitions for {h3rc} */
static const R_CallMethodDef callMethods[] = {
  {"h3rcLatLngToCell",    (DL_FUNC) &h3rcLatLngToCell,  3},
  {NULL, NULL, 0}
};

/* Imports from h3r */
SEXP (*h3rLatLngToCell);

void R_init_h3rc(DllInfo *info)

{
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(info, FALSE);

  R_RegisterCCallable("h3rc", "h3rcLatLngToCell",   (DL_FUNC) &h3rcLatLngToCell);

  R_forceSymbols(info, TRUE);  // controls visibility
}
