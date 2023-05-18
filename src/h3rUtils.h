
#include "h3libapi.h"
#include <Rinternals.h>


#ifndef R_H3R_UTILS
#define R_H3R_UTILS

 //' Fill Lat Lng
 //'
 //' fills the `latLng` object with the contents of SEXP lat/lon vectors
 void sexpToLatLng(LatLng *latLng, SEXP lat, SEXP lng, R_xlen_t idx);


 //' Fill Lat Lng
 //'
 //' fills the `latLng` object with the contents of doubles
 void doubleToLatLng(LatLng *latLng, double lat, double lng);

 //' H3 To Sexp String
 //'
 //' converts an h3 index to a SEXP string (`Rf_mkChar()`)
 SEXP h3ToSexpString(H3Index h3);

 //' H3 Vec To Sexp String
 //'
 //' Converts an array of H3 indexes to a SEXP (STRSXP) vector
 SEXP h3VecToSexpString(H3Index *h3, R_xlen_t n);

 //' SEXP String to H3
 //'
 //' Converts an R String (SEXP) to an `H3Index`
 H3Index sexpStringToH3(SEXP h3, R_xlen_t idx);

 //' LatLng to SEXP
 //'
 //' Fills vectos of SEXP lat/lon objects with the contents of a LatLng
 void latLngToSexp(LatLng *latLng, SEXP lats, SEXP lons, R_xlen_t idx);

 //' LatLngList
 //'
 //' Creates a list of lat/lon elements
 SEXP latLngList(SEXP lats, SEXP lons);

 //' OrigDestList
 //'
 //' Creates a list of origin and destination cells
 SEXP origDestList(SEXP orig, SEXP dest);

 //' gridDistList
 //'
 //' Creates a list of cells and distances
SEXP gridDistList(SEXP grid, SEXP dist);

 //' coordIJList
 //'
 //' Creates a list of coord i and j
SEXP coordIJList(SEXP i, SEXP j);

 //' CellBoundaryToList
 //'
 //' Creates a list of lon/lats from a CellBoundary
 SEXP cellBoundaryToList(CellBoundary *cb);

 //' Int To SEXP ARray
 //'
 //' Converts an integer array to a SEXP (INTSXP) array
 SEXP intToSexpArray(int *arr, R_xlen_t n);

 //' h3Error to error message
 //'
 //' Converts an H3Error to error message
 char* h3rErrorToString(int err);

 //' h3rError call R API error
 //'
 //' Throw a R error is there is an error
 void h3rError(int err, R_xlen_t i);

 //' H3r vector length error
 //'
 //' Throw a R error is the input vector length is not all the same
 void h3rVectorError(R_xlen_t *n, int size);
#endif
