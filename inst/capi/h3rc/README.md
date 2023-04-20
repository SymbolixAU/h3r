# C API

{h3rc} is a demo package showing how to include the C code from {h3r} into another package.



---


## DESCRIPTION

Depend & Link to {h3r}

```
Depends:
  h3r
LinkingTo:
  h3r
```

## src/init.c

Define the functions you want to import from {h3r}

```
SEXP (*h3rLatLngToCell)(SEXP,SEXP,SEXP);

void R_init_h3rc(DllInfo *info)

{
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(info, FALSE);

  /* Imports from h3r */
  h3rLatLngToCell = (SEXP(*)(SEXP,SEXP,SEXP)) R_GetCCallable("h3r", "h3rLatLngToCell");
}
```

## src/h3rc.c

Include the "h3rapi.h" header, then you can call the functions you've registered in `src/init.c`

```
#include "h3rapi.h"

SEXP h3rcLatLngToCell(SEXP lat, SEXP lon, SEXP res) {
  return h3rLatLngToCell(lat, lon, res);
}

```

## R/h3rr.R

Call the function you've defined in `h3rc.c` from within an R function

```
#' @export
ll2Cell <- function(lat, lon, res) {
  .Call(h3rcLatLngToCell, lat, lon, res)
}

```


## R/<somewhere.R>

Register your dynamic routines. If using Roxygen to build and document your pacakge you can specify

```
#' @useDynLib h3rc, .registration = TRUE
NULL
```

and it will be built and added to your NAMESPACE automatically
