

#include <stdlib.h> // for NULL

#include <R.h>
#include <Rconfig.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>

#include "h3r.h"

/* Define .Call functions */
static const R_CallMethodDef callMethods[] = {

  // Indexing
  {"h3rLatLngToCell",   (DL_FUNC) &h3rLatLngToCell,   3},
  {"h3rCellToLatLng",   (DL_FUNC) &h3rCellToLatLng,   1},
  {"h3rCellToBoundary", (DL_FUNC) &h3rCellToBoundary, 1},

  // Inspection
  {"h3rGetResolution",       (DL_FUNC) &h3rGetResolution,       1},
  {"h3rGetBaseCellNumber",   (DL_FUNC) &h3rGetBaseCellNumber,   1},
  {"h3rIsValidCell",         (DL_FUNC) &h3rIsValidCell,         1},
  {"h3rIsResClassIII",       (DL_FUNC) &h3rIsResClassIII,       1},
  {"h3rIsPentagon",          (DL_FUNC) &h3rIsPentagon,          1},
  {"h3rGetIcosahedronFaces", (DL_FUNC) &h3rGetIcosahedronFaces, 1},
  {"h3rMaxFaceCount",        (DL_FUNC) &h3rMaxFaceCount,        1},

  // Traversal
  {"h3rGridDisk",                 (DL_FUNC) &h3rGridDisk, 2},
  {"h3rMaxGridDiskSize",          (DL_FUNC) &h3rMaxGridDiskSize, 1},
  {"h3rGridDiskDistances",        (DL_FUNC) &h3rGridDiskDistances, 2},
  {"h3rGridDiskUnsafe",           (DL_FUNC) &h3rGridDiskUnsafe, 2},
  {"h3rGridDiskDistancesUnsafe",  (DL_FUNC) &h3rGridDiskDistancesUnsafe, 2},
  {"h3rGridDiskDistancesSafe",    (DL_FUNC) &h3rGridDiskDistancesSafe, 2},
  {"h3rGridRingUnsafe",           (DL_FUNC) &h3rGridRingUnsafe, 2},
  {"h3rGridPathCells",            (DL_FUNC) &h3rGridPathCells, 2},
  {"h3rGridPathCellsSize",        (DL_FUNC) &h3rGridPathCellsSize, 2},
  {"h3rGridDistance",             (DL_FUNC) &h3rGridDistance, 2},
  {"h3rCellToLocalIj",            (DL_FUNC) &h3rCellToLocalIj, 2},
  {"h3rLocalIjToCell",            (DL_FUNC) &h3rLocalIjToCell, 3},
  {"h3rDirectedEdgeToBoundary",   (DL_FUNC) &h3rDirectedEdgeToBoundary, 1},

  // Hierarchy
  {"h3rCellToParent",        (DL_FUNC) &h3rCellToParent,       2},
  {"h3rCellToChildren",      (DL_FUNC) &h3rCellToChildren,     2},
  {"h3rCellToChildrenSize",  (DL_FUNC) &h3rCellToChildrenSize, 2},
  {"h3rCellToCenterChild", (DL_FUNC) &h3rCellToCenterChild, 2},
  {"h3rCellToChildPos", (DL_FUNC) &h3rCellToChildPos, 2},
  {"h3rChildPosToCell", (DL_FUNC) &h3rChildPosToCell, 3},
  // {"h3rCompactCells", (DL_FUNC) &h3rCompactCells, 1},
  {"h3rUncompactCells", (DL_FUNC) &h3rUncompactCells, 2},

  // Regions
  {"h3rPolygonToCells",                 (DL_FUNC) &h3rPolygonToCells,   3},
  {"h3rCellsToMultiPolygon",                 (DL_FUNC) &h3rCellsToMultiPolygon,   2},

  // Directed Edges
  {"h3rAreNeighborCells",                 (DL_FUNC) &h3rAreNeighborCells,   2},
  {"h3rCellsToDirectedEdge",              (DL_FUNC) &h3rCellsToDirectedEdge,   2},
  {"h3rIsValidDirectedEdge",              (DL_FUNC) &h3rIsValidDirectedEdge,   1},
  {"h3rGetDirectedEdgeOrigin",            (DL_FUNC) &h3rGetDirectedEdgeOrigin,   1},
  {"h3rGetDirectedEdgeDestination",       (DL_FUNC) &h3rGetDirectedEdgeDestination,   1},
  {"h3rDirectedEdgeToCells",              (DL_FUNC) &h3rDirectedEdgeToCells,   1},
  {"h3rOriginToDirectedEdges",            (DL_FUNC) &h3rOriginToDirectedEdges,   1},


  // Vertexes
  {"h3rCellToVertex",      (DL_FUNC) &h3rCellToVertex,   2},
  {"h3rCellToVertexes",    (DL_FUNC) &h3rCellToVertexes, 1},
  {"h3rVertexToLatLng",    (DL_FUNC) &h3rVertexToLatLng, 1},
  {"h3rIsValidVertex",     (DL_FUNC) &h3rIsValidVertex,  1},


  // Miscellaneous
  {"h3rDegsToRads",              (DL_FUNC) &h3rDegsToRads,              1},     // H3 Internal
  {"h3rRadsToDegs",              (DL_FUNC) &h3rRadsToDegs,              1},


  {"h3rGetHexagonAreaAvgM2",   (DL_FUNC) &h3rGetHexagonAreaAvgM2,    1},
  {"h3rGetHexagonAreaAvgKm2",   (DL_FUNC) &h3rGetHexagonAreaAvgKm2,   1},

  {"h3rCellAreaRads2", (DL_FUNC) &h3rCellAreaRads2, 1},
  {"h3rCellAreaM2",    (DL_FUNC) &h3rCellAreaM2,    1},
  {"h3rCellAreaKm2",   (DL_FUNC) &h3rCellAreaKm2,   1},

  {"h3rGetHexagonEdgeLengthAvgM",    (DL_FUNC) &h3rGetHexagonEdgeLengthAvgM,    1},
  {"h3rGetHexagonEdgeLengthAvgKm",   (DL_FUNC) &h3rGetHexagonEdgeLengthAvgKm,   1},

  {"h3rEdgeLengthRads", (DL_FUNC) &h3rEdgeLengthRads, 1},
  {"h3rEdgeLengthM",    (DL_FUNC) &h3rEdgeLengthM,    1},
  {"h3rEdgeLengthKm",   (DL_FUNC) &h3rEdgeLengthKm,   1},


  {"h3rGetNumCells", (DL_FUNC) &h3rGetNumCells, 1},
  {"h3rGetRes0Cells",    (DL_FUNC) &h3rGetRes0Cells,    0},
  {"h3rRes0CellCount",   (DL_FUNC) &h3rRes0CellCount,   1},

  {"h3rGetPentagons",    (DL_FUNC) &h3rGetPentagons,    1},
  {"h3rPentagonCount",   (DL_FUNC) &h3rPentagonCount,   0},

  {"h3rGreatCircleDistanceRads", (DL_FUNC) &h3rGreatCircleDistanceRads, 4},
  {"h3rGreatCircleDistanceM",    (DL_FUNC) &h3rGreatCircleDistanceM,    4},
  {"h3rGreatCircleDistanceKm",   (DL_FUNC) &h3rGreatCircleDistanceKm,   4},

  {NULL,                NULL,                        0}
};

/* Imports from h3lib */
typedef uint32_t H3Error;

typedef enum {
  /** H3 digit in center */
  CENTER_DIGIT = 0,
  /** H3 digit in k-axes direction */
  K_AXES_DIGIT = 1,
  /** H3 digit in j-axes direction */
  J_AXES_DIGIT = 2,
  /** H3 digit in j == k direction */
  JK_AXES_DIGIT = J_AXES_DIGIT | K_AXES_DIGIT, /* 3 */
  /** H3 digit in i-axes direction */
  I_AXES_DIGIT = 4,
  /** H3 digit in i == k direction */
  IK_AXES_DIGIT = I_AXES_DIGIT | K_AXES_DIGIT, /* 5 */
  /** H3 digit in i == j direction */
  IJ_AXES_DIGIT = I_AXES_DIGIT | J_AXES_DIGIT, /* 6 */
  /** H3 digit in the invalid direction */
  INVALID_DIGIT = 7,
  /** Valid digits will be less than this value. Same value as INVALID_DIGIT.
   */
  NUM_DIGITS = INVALID_DIGIT,
  /** Child digit which is skipped for pentagons */
  PENTAGON_SKIPPED_DIGIT = K_AXES_DIGIT /* 1 */
} Direction;

typedef uint64_t H3Index;

#define MAX_CELL_BNDRY_VERTS 10

typedef struct {
  double lat;  ///< latitude in radians
  double lng;  ///< longitude in radians
} LatLng;

typedef struct {
  int numVerts;                        ///< number of vertices
  LatLng verts[MAX_CELL_BNDRY_VERTS];  ///< vertices in ccw order
} CellBoundary;

typedef struct {
  int numVerts;
  LatLng *verts;
} GeoLoop;

typedef struct {
  GeoLoop geoloop;  ///< exterior boundary of the polygon
  int numHoles;     ///< number of elements in the array pointed to by holes
  GeoLoop *holes;   ///< interior boundaries (holes) in the polygon
} GeoPolygon;

typedef struct {
  int numPolygons;
  GeoPolygon *polygons;
} GeoMultiPolygon;


typedef struct LinkedLatLng LinkedLatLng;
struct LinkedLatLng {
  LatLng vertex;
  LinkedLatLng *next;
};

typedef struct LinkedGeoLoop LinkedGeoLoop;
struct LinkedGeoLoop {
  LinkedLatLng *first;
  LinkedLatLng *last;
  LinkedGeoLoop *next;
};


typedef struct LinkedGeoPolygon LinkedGeoPolygon;
struct LinkedGeoPolygon {
  LinkedGeoLoop *first;
  LinkedGeoLoop *last;
  LinkedGeoPolygon *next;
};


typedef struct {
  int i;  ///< i component
  int j;  ///< j component
} CoordIJ;

void attribute_visible R_init_h3r(DllInfo *info)
{
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);

  R_useDynamicSymbols(info, FALSE);

  R_RegisterCCallable("h3r", "h3rLatLngToCell",    (DL_FUNC) &h3rLatLngToCell);
  R_RegisterCCallable("h3r", "h3rCellToLatLng",    (DL_FUNC) &h3rCellToLatLng);
  R_RegisterCCallable("h3r", "h3rCellToBoundary",  (DL_FUNC) &h3rCellToBoundary);

  // Inspection
  R_RegisterCCallable("h3r", "h3rGetResolution",       (DL_FUNC) &h3rGetResolution);
  R_RegisterCCallable("h3r", "h3rGetBaseCellNumber",   (DL_FUNC) &h3rGetBaseCellNumber);
  R_RegisterCCallable("h3r", "h3rIsValidCell",         (DL_FUNC) &h3rIsValidCell);
  R_RegisterCCallable("h3r", "h3rIsResClassIII",       (DL_FUNC) &h3rIsResClassIII);
  R_RegisterCCallable("h3r", "h3rIsPentagon",          (DL_FUNC) &h3rIsPentagon);
  R_RegisterCCallable("h3r", "h3rGetIcosahedronFaces", (DL_FUNC) &h3rGetIcosahedronFaces);
  R_RegisterCCallable("h3r", "h3rMaxFaceCount",        (DL_FUNC) &h3rMaxFaceCount);

  // Traversal

  R_RegisterCCallable("h3r", "h3rGridDisk",                 (DL_FUNC)&h3rGridDisk);
  R_RegisterCCallable("h3r", "h3rMaxGridDiskSize",          (DL_FUNC)&h3rMaxGridDiskSize);
  R_RegisterCCallable("h3r", "h3rGridDiskDistances",        (DL_FUNC)&h3rGridDiskDistances);
  R_RegisterCCallable("h3r", "h3rGridDiskUnsafe",           (DL_FUNC)&h3rGridDiskUnsafe);
  R_RegisterCCallable("h3r", "h3rGridDiskDistancesUnsafe",  (DL_FUNC)&h3rGridDiskDistancesUnsafe);
  R_RegisterCCallable("h3r", "h3rGridDiskDistancesSafe",    (DL_FUNC)&h3rGridDiskDistancesSafe);
  R_RegisterCCallable("h3r", "h3rGridRingUnsafe",           (DL_FUNC)&h3rGridRingUnsafe);
  R_RegisterCCallable("h3r", "h3rGridPathCells",            (DL_FUNC)&h3rGridPathCells);
  R_RegisterCCallable("h3r", "h3rGridPathCellsSize",        (DL_FUNC)&h3rGridPathCellsSize);
  R_RegisterCCallable("h3r", "h3rGridDistance",             (DL_FUNC)&h3rGridDistance);
  R_RegisterCCallable("h3r", "h3rCellToLocalIj",            (DL_FUNC)&h3rCellToLocalIj);
  R_RegisterCCallable("h3r", "h3rLocalIjToCell",            (DL_FUNC)&h3rLocalIjToCell);

  // Hierarchy
  R_RegisterCCallable("h3r", "h3rCellToParent",          (DL_FUNC) &h3rCellToParent);
  R_RegisterCCallable("h3r", "h3rCellToChildren",        (DL_FUNC) &h3rCellToChildren);
  R_RegisterCCallable("h3r", "h3rCellToCenterChild",     (DL_FUNC) &h3rCellToCenterChild);
  R_RegisterCCallable("h3r", "h3rCellToChildPos",        (DL_FUNC) &h3rCellToChildPos);
  R_RegisterCCallable("h3r", "h3rChildPosToCell",        (DL_FUNC) &h3rChildPosToCell);
  // R_RegisterCCallable("h3r", "h3rCompactCells",          (DL_FUNC) &h3rCompactCells);
  R_RegisterCCallable("h3r", "h3rUncompactCells",        (DL_FUNC) &h3rUncompactCells);

  // Regions
  R_RegisterCCallable("h3r", "h3rPolygonToCells",             (DL_FUNC) &h3rPolygonToCells);
  R_RegisterCCallable("h3r", "h3rCellsToMultiPolygon",        (DL_FUNC) &h3rCellsToMultiPolygon);

  // Directed Edges
  R_RegisterCCallable("h3r", "h3rAreNeighborCells",             (DL_FUNC) &h3rAreNeighborCells);
  R_RegisterCCallable("h3r", "h3rCellsToDirectedEdge",          (DL_FUNC) &h3rCellsToDirectedEdge);
  R_RegisterCCallable("h3r", "h3rIsValidDirectedEdge",          (DL_FUNC) &h3rIsValidDirectedEdge);
  R_RegisterCCallable("h3r", "h3rGetDirectedEdgeOrigin",        (DL_FUNC) &h3rGetDirectedEdgeOrigin);
  R_RegisterCCallable("h3r", "h3rGetDirectedEdgeDestination",   (DL_FUNC) &h3rGetDirectedEdgeDestination);
  R_RegisterCCallable("h3r", "h3rDirectedEdgeToCells",          (DL_FUNC) &h3rDirectedEdgeToCells);
  R_RegisterCCallable("h3r", "h3rOriginToDirectedEdges",        (DL_FUNC) &h3rOriginToDirectedEdges);
  R_RegisterCCallable("h3r", "h3rDirectedEdgeToBoundary",       (DL_FUNC) &h3rDirectedEdgeToBoundary);

  // Vertexes
  R_RegisterCCallable("h3r", "h3rCellToVertex",     (DL_FUNC) &h3rCellToVertex);
  R_RegisterCCallable("h3r", "h3rCellToVertexes",   (DL_FUNC) &h3rCellToVertexes);
  R_RegisterCCallable("h3r", "h3rVertexToLatLng",   (DL_FUNC) &h3rVertexToLatLng);
  R_RegisterCCallable("h3r", "h3rIsValidVertex",    (DL_FUNC) &h3rIsValidVertex);


  // Miscellaneous
  R_RegisterCCallable("h3r", "h3rDegsToRads",              (DL_FUNC) &h3rDegsToRads);
  R_RegisterCCallable("h3r", "h3rRadsToDegs",              (DL_FUNC) &h3rRadsToDegs);

  R_RegisterCCallable("h3r", "h3rGetHexagonAreaAvgM2",    (DL_FUNC) &h3rGetHexagonAreaAvgM2);
  R_RegisterCCallable("h3r", "h3rGetHexagonAreaAvgKm2",   (DL_FUNC) &h3rGetHexagonAreaAvgKm2);

  R_RegisterCCallable("h3r", "h3rCellAreaRads2", (DL_FUNC) &h3rCellAreaRads2);
  R_RegisterCCallable("h3r", "h3rCellAreaM2",    (DL_FUNC) &h3rCellAreaM2);
  R_RegisterCCallable("h3r", "h3rCellAreaKm2",   (DL_FUNC) &h3rCellAreaKm2);

  R_RegisterCCallable("h3r", "h3rGetNumCells",    (DL_FUNC) &h3rGetNumCells);
  R_RegisterCCallable("h3r", "h3rGetRes0Cells",   (DL_FUNC) &h3rGetRes0Cells);
  R_RegisterCCallable("h3r", "h3rRes0CellCount",  (DL_FUNC) &h3rRes0CellCount);

  R_RegisterCCallable("h3r", "h3rGetPentagons",   (DL_FUNC) &h3rGetPentagons);
  R_RegisterCCallable("h3r", "h3rPentagonCount",  (DL_FUNC) &h3rPentagonCount);

  R_RegisterCCallable("h3r", "h3rGreatCircleDistanceRads", (DL_FUNC) &h3rGreatCircleDistanceRads);
  R_RegisterCCallable("h3r", "h3rGreatCircleDistanceM",    (DL_FUNC) &h3rGreatCircleDistanceM);
  R_RegisterCCallable("h3r", "h3rGreatCircleDistanceKm",   (DL_FUNC) &h3rGreatCircleDistanceKm);

  R_forceSymbols(info, TRUE);  // controls visibility


}

void R_unload_h3r(DllInfo *info)
{
  // TODO:
  /* Release Resources */
}
