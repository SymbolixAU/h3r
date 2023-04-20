# C++ API

{h3rcpp} is a demo package showing how to include the C++ code from {h3r} into another package.


## DESCRIPTION

Link to {h3r} and {Rcpp}

```
Depends: 
  h3r,
LinkingTo:
  h3r,
  Rcpp
```

Inclue the `h3rapi.h` header, and use the `h3r` namespace (see example in `/src/h3rcpp.cpp`)

```c++
#include <Rcpp.h>
#include "h3rapi.h"

// [[Rcpp::export]]
SEXP h3rcppLatLngToCell(SEXP lat, SEXP lon, SEXP res) {
  return h3r::latLngToCell(lat, lon, res);
}

```

Call your C++ function within R (see example in `/R/h3rr.R`)

```r
ll2Cell <- function(lat, lon, res) {
  return( h3rcppLatLngToCell(lat, lon, res))
}
```


