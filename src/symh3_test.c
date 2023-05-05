
// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

Direction sexp_string_to_direction(SEXP str) {
  const char *inputStr = CHAR(str);

  if (strcmp(inputStr, "K") == 0) {
    return K_AXES_DIGIT;
  } else if (strcmp(inputStr, "J") == 0) {
    return J_AXES_DIGIT;
  } else if (strcmp(inputStr, "JK") == 0) {
    return JK_AXES_DIGIT;
  } else if (strcmp(inputStr, "I") == 0) {
    return I_AXES_DIGIT;
  } else if (strcmp(inputStr, "IK") == 0) {
    return IK_AXES_DIGIT;
  } else if (strcmp(inputStr, "IJ") == 0) {
    return IJ_AXES_DIGIT;
  } else {
    error("Invalid Direction!");
    return INVALID_DIGIT;
  }
}

SEXP symh3_directions_cell(SEXP origin_vector, SEXP distance_vector, SEXP direction_vector) {
  R_xlen_t n = Rf_xlength(origin_vector);
  R_xlen_t i;

  H3Index origin, h;
  int distance, j, flag;
  int64_t maxSize, k;
  Direction direction, d;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));
  SEXP names = PROTECT(Rf_allocVector(STRSXP, n));

  maxGridDiskSize(1, &maxSize);
  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origin_vector, i);
    h = origin;
    distance = INTEGER(distance_vector)[i];
    direction = sexp_string_to_direction(STRING_ELT(direction_vector, i));
    SEXP group = PROTECT(Rf_allocVector(STRSXP, distance));


    for( j = 0; j < distance; j++){
      H3Index result[maxSize];
      h3rError(gridDisk(origin, 1, result), i);

      k = 0;
      flag = 0;
      while( k < maxSize && !flag){
        d = directionForNeighbor(origin, result[k]);
        if (d == direction){
          if(k > 0 && result[k] == h){
            error("symh3 - Error at item number %td: %s\n", i + 1, "Crossed faces");
          }
          h = origin;
          origin = result[k];
          flag = 1;
          break;
        }
        k++;
      }

      if(!flag){
        error("symh3 - Error at item number %td: %s\n", i + 1, "Crossed a pentagon");
      }

      SET_STRING_ELT(group, j, h3ToSexpString(origin));
    }

    SET_STRING_ELT(names, i, STRING_ELT(origin_vector, i));
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }

  Rf_setAttrib(out, R_NamesSymbol, names);




  UNPROTECT(2);
  return out;

}
