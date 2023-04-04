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

    h3error(gridDisk(h, distance, result), i);

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

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n));

  int distance;
  int64_t num;

  for( i = 0; i < n; i++ ) {
    distance = INTEGER(k)[i];
    h3error(maxGridDiskSize(distance, &num), i);

    SET_REAL_ELT(out, i, (double)num);
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
    h3error(maxGridDiskSize(distance, &maxSize), i);
    H3Index result[maxSize];
    int distances[maxSize];
    SEXP cell = PROTECT(Rf_allocVector(STRSXP, maxSize));
    SEXP dist = PROTECT(Rf_allocVector(INTSXP, maxSize)); 

    h3error(gridDiskDistances(h, distance, result, distances), i);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(cell, j, h3ToSexpString(result[j]));
      SET_INTEGER_ELT(dist, j, distances[j]);
    }
    SEXP group = gridDistList(cell, dist);
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(2);
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

    h3error(maxGridDiskSize(distance, &maxSize), i);
    H3Index result[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    h3error(gridDiskUnsafe(h, distance, result), i);

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
    h3error(maxGridDiskSize(distance, &maxSize), i);
    H3Index result[maxSize];
    int distances[maxSize];
    SEXP cell = PROTECT(Rf_allocVector(STRSXP, maxSize));
    SEXP dist = PROTECT(Rf_allocVector(INTSXP, maxSize)); 

    h3error(gridDiskDistancesUnsafe(h, distance, result, distances), i);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(cell, j, h3ToSexpString(result[j]));
      SET_INTEGER_ELT(dist, j, distances[j]);
    }
    SEXP group = gridDistList(cell, dist);
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(2);
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
    h3error(maxGridDiskSize(distance, &maxSize), i);
    H3Index result[maxSize];
    int distances[maxSize];
    SEXP cell = PROTECT(Rf_allocVector(STRSXP, maxSize));
    SEXP dist = PROTECT(Rf_allocVector(INTSXP, maxSize)); 

    h3error(gridDiskDistancesSafe(h, distance, result, distances), i);

    for( j = 0; j < maxSize; j++){
      SET_STRING_ELT(cell, j, h3ToSexpString(result[j]));
      SET_INTEGER_ELT(dist, j, distances[j]);
    }
    SEXP group = gridDistList(cell, dist);
    SET_VECTOR_ELT(out, i, group);

    UNPROTECT(2);
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

    h3error(maxGridDiskSize(length, &maxSize), i);
    H3Index result[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    h3error(gridRingUnsafe(h, length, result), i);

    for( j = 0; j < maxSize; j++){
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

    h3error(gridPathCellsSize(origin, destination, &maxSize), i);
    H3Index result[maxSize];
    SEXP group = PROTECT(Rf_allocVector(STRSXP, maxSize));

    h3error(gridPathCells(origin, destination, result), i);

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

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n));

  H3Index origin, destination;
  int64_t num;

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);
    h3error(gridPathCellsSize(origin, destination, &num), i);
    SET_REAL_ELT(out, i, (double)num);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rGridDistance(SEXP origH3, SEXP destH3) {
  R_xlen_t n = Rf_xlength(origH3);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n));

  H3Index origin, destination;
  int64_t num;

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(origH3, i);
    destination = sexpStringToH3(destH3, i);
    h3error(gridDistance(origin, destination, &num), i);

    SET_REAL_ELT(out, i, (double)num);
  }

  UNPROTECT(1);
  return out;
}

SEXP h3rCellToLocalIj(SEXP orig, SEXP h3) {
  R_xlen_t n = Rf_xlength(orig);
  R_xlen_t i;

  SEXP coordI = PROTECT(Rf_allocVector(INTSXP, n));
  SEXP coordJ = PROTECT(Rf_allocVector(INTSXP, n));

  H3Index origin, h;
  CoordIJ ij;
  uint32_t mode = 0;

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(orig, i);
    h = sexpStringToH3(h3, i);
    h3error(cellToLocalIj(origin, h, mode, &ij), i);
    SET_INTEGER_ELT(coordI, i, ij.i);
    SET_INTEGER_ELT(coordJ, i, ij.j);
  }

  SEXP out = coordIJList(coordI, coordJ);

  UNPROTECT(2);
  return out;
}

SEXP h3rLocalIjToCell(SEXP orig, SEXP coordI, SEXP coordJ) {
  R_xlen_t n = Rf_xlength(coordI);
  R_xlen_t i;

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  H3Index origin, h;
  CoordIJ ij;
  uint32_t mode = 0;

  for( i = 0; i < n; i++ ) {
    origin = sexpStringToH3(orig, i);
    ij.i = INTEGER(coordI)[i];
    ij.j = INTEGER(coordJ)[i];
    h3error(localIjToCell(origin, &ij, mode, &h), i);
    SET_STRING_ELT(out, i,h3ToSexpString(h));
  }

  UNPROTECT(1);
  return out;
}
