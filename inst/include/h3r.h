#pragma once

#ifndef R_H3R_H
#define R_H3R_H

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "h3libapi.h"

#ifdef __cplusplus
extern "C" {
#endif

H3Error (latLngToCell)(const LatLng*, int, H3Index*);
H3Error (cellToLatLng)(H3Index, LatLng*);
H3Error (cellToBoundary)(H3Index, CellBoundary*);
H3Error (maxGridDiskSize)(int, int64_t*);
H3Error (gridDiskUnsafe)(H3Index, int, H3Index*);
H3Error (gridDiskDistancesUnsafe)(H3Index, int, H3Index*, int*);
H3Error (gridDiskDistancesSafe)(H3Index, int, H3Index*, int*);
H3Error (gridDisksUnsafe)(H3Index*, int, int, H3Index*);
H3Error (gridDisk)(H3Index, int, H3Index*);
H3Error (gridDiskDistances)(H3Index, int, H3Index*, int*);
H3Error (gridRingUnsafe)(H3Index, int, H3Index*);
H3Error (maxPolygonToCellsSize)(const GeoPolygon*, int, uint32_t, int64_t*);
H3Error (polygonToCells)(const GeoPolygon*, int, uint32_t, H3Index*);
H3Error (cellsToLinkedMultiPolygon)(const H3Index*, const int, LinkedGeoPolygon*);
void (destroyLinkedMultiPolygon)(LinkedGeoPolygon*);
double (degsToRads)(double);
double (radsToDegs)(double);
double (greatCircleDistanceRads)(const LatLng*, const LatLng*);
double (greatCircleDistanceKm)(const LatLng*, const LatLng*);
double (greatCircleDistanceM)(const LatLng*, const LatLng*);
H3Error (getHexagonAreaAvgKm2)(int, double*);
H3Error (getHexagonAreaAvgM2)(int, double*);
H3Error (cellAreaRads2)(H3Index, double*);
H3Error (cellAreaKm2)(H3Index, double*);
H3Error (cellAreaM2)(H3Index, double*);
H3Error (getHexagonEdgeLengthAvgKm)(int, double*);
H3Error (getHexagonEdgeLengthAvgM)(int, double*);
H3Error (edgeLengthRads)(H3Index, double*);
H3Error (edgeLengthKm)(H3Index, double*);
H3Error (edgeLengthM)(H3Index, double*);
H3Error (getNumCells)(int, int64_t*);
int (res0CellCount)(void);
H3Error (getRes0Cells)(H3Index*);
int (pentagonCount)(void);
H3Error (getPentagons)(int, H3Index*);
int (getResolution)(H3Index);
int (getBaseCellNumber)(H3Index);
H3Error (stringToH3)(const char*, H3Index*);
int (isValidCell)(H3Index);
H3Error (cellToParent)(H3Index, int, H3Index*);
H3Error (cellToChildrenSize)(H3Index, int, int64_t*);
H3Error (cellToChildren)(H3Index, int, H3Index*);
H3Error (cellToCenterChild)(H3Index, int, H3Index*);
H3Error (cellToChildPos)(H3Index, int, int64_t*);
H3Error (childPosToCell)(int64_t, H3Index, int, H3Index*);
H3Error (compactCells)(const H3Index*, H3Index*, const int64_t);
H3Error (uncompactCellsSize)(const H3Index*, const int64_t, const int, int64_t*);
H3Error (uncompactCells)(const H3Index*, const int64_t, H3Index*, const int64_t, const int);
int (isResClassIII)(H3Index);
int (isPentagon)(H3Index);
H3Error (maxFaceCount)(H3Index, int*);
H3Error (getIcosahedronFaces)(H3Index, int*);
H3Error (areNeighborCells)(H3Index, H3Index, int*);
H3Error (cellsToDirectedEdge)(H3Index, H3Index, H3Index*);
int (isValidDirectedEdge)(H3Index);
H3Error (getDirectedEdgeOrigin)(H3Index, H3Index*);
H3Error (getDirectedEdgeDestination)(H3Index, H3Index*);
H3Error (directedEdgeToCells)(H3Index, H3Index*);
H3Error (originToDirectedEdges)(H3Index, H3Index*);
H3Error (directedEdgeToBoundary)(H3Index, CellBoundary*);
H3Error (cellToVertex)(H3Index, int, H3Index*);
H3Error (cellToVertexes)(H3Index, H3Index*);
H3Error (vertexToLatLng)(H3Index, LatLng*);
int (isValidVertex)(H3Index);
H3Error (gridDistance)(H3Index, H3Index, int64_t*);
H3Error (gridPathCellsSize)(H3Index, H3Index, int64_t*);
H3Error (gridPathCells)(H3Index, H3Index, H3Index*);
H3Error (cellToLocalIj)(H3Index, H3Index, uint32_t, CoordIJ*);
H3Error (localIjToCell)(H3Index, const CoordIJ*, uint32_t, H3Index*);
Direction (directionForNeighbor)(H3Index, H3Index);
void (_geoToClosestFace)(const LatLng*, int*, double*);
double (degsToRads)(double);

// Indexing
SEXP h3rLatLngToCell(SEXP lat, SEXP lng, SEXP res);
SEXP h3rCellToLatLng(SEXP h3);
SEXP h3rCellToBoundary(SEXP h3);


// Inspection
SEXP h3rGetResolution(SEXP h3);
SEXP h3rGetBaseCellNumber(SEXP h3);
SEXP h3rIsValidCell(SEXP h3);
SEXP h3rIsResClassIII(SEXP h3);
SEXP h3rIsPentagon(SEXP h3);
SEXP h3rGetIcosahedronFaces(SEXP h3);
SEXP h3rMaxFaceCount(SEXP h3);

// Traversal
SEXP h3rGridDisk(SEXP h3, SEXP k);
SEXP h3rMaxGridDiskSize(SEXP k);
SEXP h3rGridDiskDistances(SEXP h3, SEXP k);
SEXP h3rGridDiskUnsafe(SEXP h3, SEXP k) ;
SEXP h3rGridDiskDistancesUnsafe(SEXP h3, SEXP k) ;
SEXP h3rGridDiskDistancesSafe(SEXP h3, SEXP k);
SEXP h3rGridRingUnsafe(SEXP h3, SEXP k);
SEXP h3rGridPathCells(SEXP origH3, SEXP destH3);
SEXP h3rGridPathCellsSize(SEXP origH3, SEXP destH3);
SEXP h3rGridDistance(SEXP origH3, SEXP destH3);
SEXP h3rCellToLocalIj(SEXP orig, SEXP h3);
SEXP h3rLocalIjToCell(SEXP orig, SEXP coordI, SEXP coordJ);

// Hierarchy
SEXP h3rCellToParent(SEXP h3, SEXP parentResolution);
SEXP h3rCellToChildren(SEXP h3, SEXP childResolution);
SEXP h3rCellToChildrenSize(SEXP h3, SEXP res);
SEXP h3rCellToCenterChild(SEXP h3, SEXP res);
SEXP h3rCellToChildPos(SEXP h3, SEXP res);
SEXP h3rChildPosToCell(SEXP pos, SEXP h3, SEXP res);
SEXP h3rCompactCells(SEXP h3Sets);
SEXP h3rUncompactCells(SEXP h3Sets, SEXP res);

// Regions
SEXP h3rPolygonToCells(SEXP polygonArray, SEXP res, SEXP isLatLng);
SEXP h3rCellsToMultiPolygon(SEXP h3Sets, SEXP isGeoJson);

// Directed Edges
SEXP h3rAreNeighborCells(SEXP origH3, SEXP destH3);
SEXP h3rCellsToDirectedEdge(SEXP origH3, SEXP destH3);
SEXP h3rIsValidDirectedEdge(SEXP edge);
SEXP h3rGetDirectedEdgeOrigin(SEXP edge);
SEXP h3rGetDirectedEdgeDestination(SEXP edge);
SEXP h3rDirectedEdgeToCells(SEXP edge);
SEXP h3rOriginToDirectedEdges(SEXP origH3);
SEXP h3rDirectedEdgeToBoundary(SEXP h3);

// Vertexes
SEXP h3rCellToVertex(SEXP h3, SEXP vertexNum);
SEXP h3rCellToVertexes(SEXP h3);
SEXP h3rVertexToLatLng(SEXP h3);
SEXP h3rIsValidVertex(SEXP h3);

// Miscellaneous
SEXP h3rDegsToRads(SEXP degrees);
SEXP h3rRadsToDegs(SEXP degrees);

SEXP h3rGetHexagonArea(SEXP res, int areaType);
SEXP h3rGetHexagonAreaAvgM2(SEXP res);
SEXP h3rGetHexagonAreaAvgKm2(SEXP res);

SEXP h3rCellArea(SEXP h3, int areaType);
SEXP h3rCellAreaRads2(SEXP h3);
SEXP h3rCellAreaM2(SEXP h3);
SEXP h3rCellAreaKm2(SEXP h3);

SEXP h3rGetHexagonEdgeLengthAvg(SEXP res, int distType);
SEXP h3rGetHexagonEdgeLengthAvgM(SEXP res);
SEXP h3rGetHexagonEdgeLengthAvgKm(SEXP res);

SEXP h3rEdgeLength(SEXP edge, int distType);
SEXP h3rEdgeLengthRads(SEXP edge);
SEXP h3rEdgeLengthM(SEXP edge);
SEXP h3rEdgeLengthKm(SEXP edge);

SEXP h3rGetNumCells(SEXP res);
SEXP h3rGetRes0Cells(void);
SEXP h3rRes0CellCount(void);

SEXP h3rGetPentagons(SEXP res);
SEXP h3rPentagonCount(void);

SEXP h3rGreatCircleDistance(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons, int distType);
SEXP h3rGreatCircleDistanceRads(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons);
SEXP h3rGreatCircleDistanceM(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons);
SEXP h3rGreatCircleDistanceKm(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons);

#ifdef __cplusplus
}
#endif

#endif
