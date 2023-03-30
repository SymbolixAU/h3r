// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#include "h3rUtils.h"

SEXP h3rGridDisk(SEXP h3, SEXP k) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  H3Index h;
  int distance;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(h3, i);
    distance = INTEGER(k)[i];

    maxGridDiskSize(distance, &maxSize);
    H3Index result[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    gridDisk(h, distance, result);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rMaxGridDiskSize(SEXP k) {
  R_xlen_t n = Rf_xlength(k);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  int distance;
  int64_t num;
  char buffer[21];

  for( i = 0; i < n; i++ ) {
    distance = INTEGER(k)[i];
    maxGridDiskSize(distance, &num);

    sprintf(buffer, "%lld", (long long int)num);

    SET_STRING_ELT(out, i, Rf_mkChar(buffer));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rGridDiskDistances(SEXP h3, SEXP k) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  H3Index h;
  int distance;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(h3, i);
    distance = INTEGER(k)[i];

    maxGridDiskSize(distance, &maxSize);
    H3Index result[maxSize];
    // TODO: figure out what this distances is doing
    int distances[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    gridDiskDistances(h, distance, result, distances);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rGridDiskUnsafe(SEXP h3, SEXP k) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  H3Index h;
  int distance;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(h3, i);
    distance = INTEGER(k)[i];

    maxGridDiskSize(distance, &maxSize);
    H3Index result[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    gridDiskUnsafe(h, distance, result);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rGridDiskDistancesUnsafe(SEXP h3, SEXP k) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  H3Index h;
  int distance;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(h3, i);
    distance = INTEGER(k)[i];

    maxGridDiskSize(distance, &maxSize);
    H3Index result[maxSize];
    // TODO: figure out what this distances is doing
    int distances[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    gridDiskDistancesUnsafe(h, distance, result, distances);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rGridDiskDistancesSafe(SEXP h3, SEXP k) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  H3Index h;
  int distance;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(h3, i);
    distance = INTEGER(k)[i];

    maxGridDiskSize(distance, &maxSize);
    H3Index result[maxSize];
    // TODO: figure out what this distances is doing
    int distances[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    gridDiskDistancesSafe(h, distance, result, distances);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rGridRingUnsafe(SEXP h3, SEXP k) {
  R_xlen_t n = Rf_xlength(h3);
  R_xlen_t i;

  H3Index h;
  int length;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    h = sexpStringToH3(h3, i);
    length = INTEGER(k)[i];

    maxGridDiskSize(length, &maxSize);
    H3Index result[maxSize - 1];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize - 1));

    gridRingUnsafe(h, length, result);

    for( j = 0; j < maxSize - 1; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rGridPathCells(SEXP origH3, SEXP destH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;

  H3Index origin, destination;
  int64_t maxSize, j;

  SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);

    gridPathCellsSize(origin, destination, &maxSize);
    H3Index result[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    gridPathCells(origin, destination, result);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(group, j, h3ToSexpString(result[j]));
    }
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(1);
  }


  UNPROTECT(1);
  return out;

}

SEXP h3rGridPathCellsSize(SEXP origH3, SEXP destH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index origin, destination;
  int64_t num;
  char buffer[21];

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);
    gridPathCellsSize(origin, destination, &num);

    sprintf(buffer, "%lld", (long long int)num);

    SET_STRING_ELT(out, i, Rf_mkChar(buffer));
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rGridDistance(SEXP origH3, SEXP destH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index origin, destination;
  int64_t num;
  char buffer[21];

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);
    gridDistance(origin, destination, &num);

    sprintf(buffer, "%lld", (long long int)num);

    SET_STRING_ELT(out, i, Rf_mkChar(buffer));
  }

  UNPROTECT(1);
  return out;
}
