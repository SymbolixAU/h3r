

#include <stdlib.h> // for NULL

#include <R.h>
#include <Rconfig.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>

// #include "h3libapi.h"
#include "h3r.h"

/* Define .Call functions */
static const R_CallMethodDef callMethods[] = {

  // Indexing
  {"h3rLatLngToCell",   (DL_FUNC) &h3rLatLngToCell,   3},
  // {"h3rCellToLatLng",   (DL_FUNC) &h3rCellToLatLng,   1},
  // {"h3rCellToBoundary", (DL_FUNC) &h3rCellToBoundary, 1},

  // // Inspection
  // {"h3rGetResolution",       (DL_FUNC) &h3rGetResolution,       1},
  // {"h3rGetBaseCellNumber",   (DL_FUNC) &h3rGetBaseCellNumber,   1},
  // {"h3rIsValidCell",         (DL_FUNC) &h3rIsValidCell,         1},
  // {"h3rIsResClassIII",       (DL_FUNC) &h3rIsResClassIII,       1},
  // {"h3rIsPentagon",          (DL_FUNC) &h3rIsPentagon,          1},
  // {"h3rGetIcosahedronFaces", (DL_FUNC) &h3rGetIcosahedronFaces, 1},
  // {"h3rMaxFaceCount",        (DL_FUNC) &h3rMaxFaceCount,        1},
  //
  // // Traversal
  //
  // // Hierarchy
  // {"h3rCellToParent",        (DL_FUNC) &h3rCellToParent,       2},
  // {"h3rCellToChildren",      (DL_FUNC) &h3rCellToChildren,     2},
  //
  // // Regions
  //
  //
  // // Directed Edges
  //
  //
  // // Vertexes
  // {"h3rCellToVertex",      (DL_FUNC) &h3rCellToVertex,   1},
  // {"h3rCellToVertexes",    (DL_FUNC) &h3rCellToVertexes, 1},
  // {"h3rVertexToLatLng",    (DL_FUNC) &h3rVertexToLatLng, 1},
  // {"h3rIsValidVertex",     (DL_FUNC) &h3rIsValidVertex,  1},
  //
  //
  // // Miscellaneous
  // {"h3rDegsToRads",              (DL_FUNC) &h3rDegsToRads,              1},     // H3 Internal
  // {"h3rRadsToDegs",              (DL_FUNC) &h3rRadsToDegs,              1},
  //
  // {"h3rGreatCircleDistanceRads", (DL_FUNC) &h3rGreatCircleDistanceRads, 4},
  // {"h3rGreatCircleDistanceM",    (DL_FUNC) &h3rGreatCircleDistanceM,    4},
  // {"h3rGreatCircleDistanceKm",   (DL_FUNC) &h3rGreatCircleDistanceKm,   4},

  {NULL,                NULL,                        0}
};

/* Imports from h3lib */
double (*degsToRads)(double);
double (*radsToDegs)(double);
// int (*h3ToString)(H3Index, char, size_t);

void attribute_visible R_init_h3r(DllInfo *info)
{
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);

  R_useDynamicSymbols(info, FALSE);

  /* Imports from h3lib */
  degsToRads = (double(*)(double degrees)) R_GetCCallable("h3lib", "degsToRads");
  radsToDegs = (double(*)(double radians)) R_GetCCallable("h3lib", "radsToDegs");

  // Indexing
  R_RegisterCCallable("h3r", "h3rLatLngToCell",    (DL_FUNC) &h3rLatLngToCell);
  // R_RegisterCCallable("h3r", "h3rCellToLatLng",    (DL_FUNC) &h3rCellToLatLng);
  // R_RegisterCCallable("h3r", "h3rCellToBoundary",  (DL_FUNC) &h3rCellToBoundary);

  // Inspection
  // R_RegisterCCallable("h3r", "h3rGetResolution",       (DL_FUNC) &h3rGetResolution);
  // R_RegisterCCallable("h3r", "h3rGetBaseCellNumber",   (DL_FUNC) &h3rGetBaseCellNumber);
  // R_RegisterCCallable("h3r", "h3rIsValidCell",         (DL_FUNC) &h3rIsValidCell);
  // R_RegisterCCallable("h3r", "h3rIsResClassIII",       (DL_FUNC) &h3rIsResClassIII);
  // R_RegisterCCallable("h3r", "h3rIsPentagon",          (DL_FUNC) &h3rIsPentagon);
  // R_RegisterCCallable("h3r", "h3rGetIcosahedronFaces", (DL_FUNC) &h3rGetIcosahedronFaces);
  // R_RegisterCCallable("h3r", "h3rMaxFaceCount",        (DL_FUNC) &h3rMaxFaceCount);

  // Traversal

  // Hierarchy
  // R_RegisterCCallable("h3r", "h3rCellToParent",          (DL_FUNC) &h3rCellToParent);
  // R_RegisterCCallable("h3r", "h3rCellToChildren",        (DL_FUNC) &h3rCellToChildren);

  // Regions


  // Directed Edges


  // Vertexes
  // R_RegisterCCallable("h3r", "h3rCellToVertex",     (DL_FUNC) &h3rCellToVertex);
  // R_RegisterCCallable("h3r", "h3rCellToVertexes",   (DL_FUNC) &h3rCellToVertexes);
  // R_RegisterCCallable("h3r", "h3rVertexToLatLng",   (DL_FUNC) &h3rVertexToLatLng);
  // R_RegisterCCallable("h3r", "h3rIsValidVertex",    (DL_FUNC) &h3rIsValidVertex);


  // Miscellaneous
  // R_RegisterCCallable("h3r", "h3rDegsToRads",              (DL_FUNC) &h3rDegsToRads);
  // R_RegisterCCallable("h3r", "h3rRadsToDegs",              (DL_FUNC) &h3rRadsToDegs);
  //
  // R_RegisterCCallable("h3r", "h3rGreatCircleDistanceRads", (DL_FUNC) &h3rGreatCircleDistanceRads);
  // R_RegisterCCallable("h3r", "h3rGreatCircleDistanceM",    (DL_FUNC) &h3rGreatCircleDistanceM);
  // R_RegisterCCallable("h3r", "h3rGreatCircleDistanceKm",   (DL_FUNC) &h3rGreatCircleDistanceKm);


  R_forceSymbols(info, TRUE);  // controls visibility


}

void R_unload_h3r(DllInfo *info)
{
  // TODO:
  /* Release Resources */
}
