
#ifndef R_H3R_API_H
#define R_H3R_API_H

#include <R.h>
#include <Rinternals.h>
#include <Rconfig.h>
#include <R_ext/Rdynload.h>

#ifdef HAVE_VISIBILITY_ATTRIBUTE
# define attribute_hidden __attribute__ ((visibility (hidden)))
#else
# define attribute_hidden
#endif

#ifdef __cplusplus
extern "C" {
#endif
  inline SEXP attribute_hidden h3rLatLngToCell(SEXP lat, SEXP lng, SEXP res) {
    SEXP(*fun)(SEXP, SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP, SEXP)) R_GetCCallable("h3r", "h3rLatLngToCell");
    return fun(lat, lng, res);
  }
  inline SEXP attribute_hidden h3rCellToLatLng(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCellToLatLng");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rCellToBoundary(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCellToBoundary");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rGetResolution(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetResolution");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rGetBaseCellNumber(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetBaseCellNumber");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rIsValidCell(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rIsValidCell");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rIsResClassIII(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rIsResClassIII");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rIsPentagon(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rIsPentagon");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rGetIcosahedronFaces(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetIcosahedronFaces");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rMaxFaceCount(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rMaxFaceCount");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rGridDisk(SEXP h3, SEXP k) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridDisk");
    return fun(h3, k);
  }
  inline SEXP attribute_hidden h3rMaxGridDiskSize(SEXP k) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rMaxGridDiskSize");
    return fun(k);
  }
  inline SEXP attribute_hidden h3rGridDiskDistances(SEXP h3, SEXP k) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridDiskDistances");
    return fun(h3, k);
  }
  inline SEXP attribute_hidden h3rGridDiskDistancesSafe(SEXP h3, SEXP k) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridDiskDistancesSafe");
    return fun(h3, k);
  }
  inline SEXP attribute_hidden h3rGridRingUnsafe(SEXP h3, SEXP k) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridRingUnsafe");
    return fun(h3, k);
  }
  inline SEXP attribute_hidden h3rGridPathCells(SEXP origH3, SEXP destH3) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridPathCells");
    return fun(origH3, destH3);
  }
  inline SEXP attribute_hidden h3rGridPathCellsSize(SEXP origH3, SEXP destH3) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridPathCellsSize");
    return fun(origH3, destH3);
  }
  inline SEXP attribute_hidden h3rGridDistance(SEXP origH3, SEXP destH3) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rGridDistance");
    return fun(origH3, destH3);
  }
  inline SEXP attribute_hidden h3rCellToLocalIj(SEXP orig, SEXP h3 ) {
    SEXP(*fun)(SEXP, SEXP ) =
      (SEXP(*)(SEXP, SEXP )) R_GetCCallable("h3r", "h3rCellToLocalIj");
    return fun(orig, h3 );
  }
  inline SEXP attribute_hidden h3rLocalIjToCell(SEXP orig, SEXP coordI, SEXP coordJ) {
    SEXP(*fun)(SEXP, SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP, SEXP)) R_GetCCallable("h3r", "h3rLocalIjToCell");
    return fun(orig, coordI, coordJ);
  }
  inline SEXP attribute_hidden h3rCellToParent(SEXP h3, SEXP parentResolution) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rCellToParent");
    return fun(h3, parentResolution);
  }
  inline SEXP attribute_hidden h3rCellToChildren(SEXP h3, SEXP childResolution) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rCellToChildren");
    return fun(h3, childResolution);
  }
  inline SEXP attribute_hidden h3rCellToCenterChild(SEXP h3, SEXP res) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rCellToCenterChild");
    return fun(h3, res);
  }
  inline SEXP attribute_hidden h3rCellToChildPos(SEXP h3, SEXP res) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rCellToChildPos");
    return fun(h3, res);
  }
  inline SEXP attribute_hidden h3rChildPosToCell(SEXP pos, SEXP h3, SEXP res) {
    SEXP(*fun)(SEXP, SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP, SEXP)) R_GetCCallable("h3r", "h3rChildPosToCell");
    return fun(pos, h3, res);
  }
  inline SEXP attribute_hidden h3rCompactCells(SEXP h3Sets) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCompactCells");
    return fun(h3Sets);
  }
  inline SEXP attribute_hidden h3rUncompactCells(SEXP h3Sets, SEXP res) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rUncompactCells");
    return fun(h3Sets, res);
  }
  inline SEXP attribute_hidden h3rAreNeighborCells(SEXP origH3, SEXP destH3) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rAreNeighborCells");
    return fun(origH3, destH3);
  }
  inline SEXP attribute_hidden h3rCellsToDirectedEdge(SEXP origH3, SEXP destH3) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rCellsToDirectedEdge");
    return fun(origH3, destH3);
  }
  inline SEXP attribute_hidden h3rIsValidDirectedEdge(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rIsValidDirectedEdge");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rGetDirectedEdgeOrigin(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetDirectedEdgeOrigin");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rGetDirectedEdgeDestination(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetDirectedEdgeDestination");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rDirectedEdgeToCells(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rDirectedEdgeToCells");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rOriginToDirectedEdges(SEXP origH3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rOriginToDirectedEdges");
    return fun(origH3);
  }
  inline SEXP attribute_hidden h3rDirectedEdgeToBoundary(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rDirectedEdgeToBoundary");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rCellToVertex(SEXP h3, SEXP vertexNum) {
    SEXP(*fun)(SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP)) R_GetCCallable("h3r", "h3rCellToVertex");
    return fun(h3, vertexNum);
  }
  inline SEXP attribute_hidden h3rCellToVertexes(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCellToVertexes");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rVertexToLatLng(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rVertexToLatLng");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rIsValidVertex(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rIsValidVertex");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rDegsToRads(SEXP degrees) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rDegsToRads");
    return fun(degrees);
  }
  inline SEXP attribute_hidden h3rRadsToDegs(SEXP degrees) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rRadsToDegs");
    return fun(degrees);
  }
  inline SEXP attribute_hidden h3rGetHexagonArea(SEXP res, int areaType) {
    SEXP(*fun)(SEXP, int) =
      (SEXP(*)(SEXP, int)) R_GetCCallable("h3r", "h3rGetHexagonArea");
    return fun(res, areaType);
  }
  inline SEXP attribute_hidden h3rGetHexagonAreaAvgM2(SEXP res) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetHexagonAreaAvgM2");
    return fun(res);
  }
  inline SEXP attribute_hidden h3rGetHexagonAreaAvgKm2(SEXP res) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetHexagonAreaAvgKm2");
    return fun(res);
  }
  inline SEXP attribute_hidden h3rCellArea(SEXP h3, int areaType) {
    SEXP(*fun)(SEXP, int) =
      (SEXP(*)(SEXP, int)) R_GetCCallable("h3r", "h3rCellArea");
    return fun(h3, areaType);
  }
  inline SEXP attribute_hidden h3rCellAreaRads2(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCellAreaRads2");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rCellAreaM2(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCellAreaM2");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rCellAreaKm2(SEXP h3) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rCellAreaKm2");
    return fun(h3);
  }
  inline SEXP attribute_hidden h3rGetHexagonEdgeLengthAvg(SEXP res, int distType) {
    SEXP(*fun)(SEXP, int) =
      (SEXP(*)(SEXP, int)) R_GetCCallable("h3r", "h3rGetHexagonEdgeLengthAvg");
    return fun(res, distType);
  }
  inline SEXP attribute_hidden h3rGetHexagonEdgeLengthAvgM(SEXP res) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetHexagonEdgeLengthAvgM");
    return fun(res);
  }
  inline SEXP attribute_hidden h3rGetHexagonEdgeLengthAvgKm(SEXP res) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetHexagonEdgeLengthAvgKm");
    return fun(res);
  }
  inline SEXP attribute_hidden h3rEdgeLength(SEXP edge, int distType) {
    SEXP(*fun)(SEXP, int) =
      (SEXP(*)(SEXP, int)) R_GetCCallable("h3r", "h3rEdgeLength");
    return fun(edge, distType);
  }
  inline SEXP attribute_hidden h3rEdgeLengthRads(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rEdgeLengthRads");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rEdgeLengthM(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rEdgeLengthM");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rEdgeLengthKm(SEXP edge) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rEdgeLengthKm");
    return fun(edge);
  }
  inline SEXP attribute_hidden h3rGetNumCells(SEXP res) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetNumCells");
    return fun(res);
  }
  inline SEXP attribute_hidden h3rGetRes0Cells() {
    SEXP(*fun)() =
      (SEXP(*)()) R_GetCCallable("h3r", "h3rGetRes0Cells");
    return fun();
  }
  inline SEXP attribute_hidden h3rRes0CellCount() {
    SEXP(*fun)() =
      (SEXP(*)()) R_GetCCallable("h3r", "h3rRes0CellCount");
    return fun();
  }
  inline SEXP attribute_hidden h3rGetPentagons(SEXP res) {
    SEXP(*fun)(SEXP) =
      (SEXP(*)(SEXP)) R_GetCCallable("h3r", "h3rGetPentagons");
    return fun(res);
  }
  inline SEXP attribute_hidden h3rPentagonCount() {
    SEXP(*fun)() =
      (SEXP(*)()) R_GetCCallable("h3r", "h3rPentagonCount");
    return fun();
  }
  inline SEXP attribute_hidden h3rGreatCircleDistance(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons, int distType) {
    SEXP(*fun)(SEXP, SEXP, SEXP, SEXP, int) =
      (SEXP(*)(SEXP, SEXP, SEXP, SEXP, int)) R_GetCCallable("h3r", "h3rGreatCircleDistance");
    return fun(aLats, aLons, bLats, bLons, distType);
  }
  inline SEXP attribute_hidden h3rGreatCircleDistanceRads(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons) {
    SEXP(*fun)(SEXP, SEXP, SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP, SEXP, SEXP)) R_GetCCallable("h3r", "h3rGreatCircleDistanceRads");
    return fun(aLats, aLons, bLats, bLons);
  }
  inline SEXP attribute_hidden h3rGreatCircleDistanceM(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons) {
    SEXP(*fun)(SEXP, SEXP, SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP, SEXP, SEXP)) R_GetCCallable("h3r", "h3rGreatCircleDistanceM");
    return fun(aLats, aLons, bLats, bLons);
  }
  inline SEXP attribute_hidden h3rGreatCircleDistanceKm(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons) {
    SEXP(*fun)(SEXP, SEXP, SEXP, SEXP) =
      (SEXP(*)(SEXP, SEXP, SEXP, SEXP)) R_GetCCallable("h3r", "h3rGreatCircleDistanceKm");
    return fun(aLats, aLons, bLats, bLons);
  }
  #ifdef __cplusplus
}


namespace h3r {
    inline SEXP latLngToCell(SEXP lat, SEXP lng, SEXP res) {
    return h3rLatLngToCell(lat, lng, res);
  }
    inline SEXP cellToLatLng(SEXP h3) {
    return h3rCellToLatLng(h3);
  }
    inline SEXP cellToBoundary(SEXP h3) {
    return h3rCellToBoundary(h3);
  }
    inline SEXP getResolution(SEXP h3) {
    return h3rGetResolution(h3);
  }
    inline SEXP getBaseCellNumber(SEXP h3) {
    return h3rGetBaseCellNumber(h3);
  }
    inline SEXP isValidCell(SEXP h3) {
    return h3rIsValidCell(h3);
  }
    inline SEXP isResClassIII(SEXP h3) {
    return h3rIsResClassIII(h3);
  }
    inline SEXP isPentagon(SEXP h3) {
    return h3rIsPentagon(h3);
  }
    inline SEXP getIcosahedronFaces(SEXP h3) {
    return h3rGetIcosahedronFaces(h3);
  }
    inline SEXP maxFaceCount(SEXP h3) {
    return h3rMaxFaceCount(h3);
  }
    inline SEXP gridDisk(SEXP h3, SEXP k) {
    return h3rGridDisk(h3, k);
  }
    inline SEXP maxGridDiskSize(SEXP k) {
    return h3rMaxGridDiskSize(k);
  }
    inline SEXP gridDiskDistances(SEXP h3, SEXP k) {
    return h3rGridDiskDistances(h3, k);
  }
    inline SEXP gridDiskDistancesSafe(SEXP h3, SEXP k) {
    return h3rGridDiskDistancesSafe(h3, k);
  }
    inline SEXP gridRingUnsafe(SEXP h3, SEXP k) {
    return h3rGridRingUnsafe(h3, k);
  }
    inline SEXP gridPathCells(SEXP origH3, SEXP destH3) {
    return h3rGridPathCells(origH3, destH3);
  }
    inline SEXP gridPathCellsSize(SEXP origH3, SEXP destH3) {
    return h3rGridPathCellsSize(origH3, destH3);
  }
    inline SEXP gridDistance(SEXP origH3, SEXP destH3) {
    return h3rGridDistance(origH3, destH3);
  }
    inline SEXP cellToLocalIj(SEXP orig, SEXP h3 ) {
    return h3rCellToLocalIj(orig, h3 );
  }
    inline SEXP localIjToCell(SEXP orig, SEXP coordI, SEXP coordJ) {
    return h3rLocalIjToCell(orig, coordI, coordJ);
  }
    inline SEXP cellToParent(SEXP h3, SEXP parentResolution) {
    return h3rCellToParent(h3, parentResolution);
  }
    inline SEXP cellToChildren(SEXP h3, SEXP childResolution) {
    return h3rCellToChildren(h3, childResolution);
  }
    inline SEXP cellToCenterChild(SEXP h3, SEXP res) {
    return h3rCellToCenterChild(h3, res);
  }
    inline SEXP cellToChildPos(SEXP h3, SEXP res) {
    return h3rCellToChildPos(h3, res);
  }
    inline SEXP childPosToCell(SEXP pos, SEXP h3, SEXP res) {
    return h3rChildPosToCell(pos, h3, res);
  }
    inline SEXP compactCells(SEXP h3Sets) {
    return h3rCompactCells(h3Sets);
  }
    inline SEXP uncompactCells(SEXP h3Sets, SEXP res) {
    return h3rUncompactCells(h3Sets, res);
  }
    inline SEXP areNeighborCells(SEXP origH3, SEXP destH3) {
    return h3rAreNeighborCells(origH3, destH3);
  }
    inline SEXP cellsToDirectedEdge(SEXP origH3, SEXP destH3) {
    return h3rCellsToDirectedEdge(origH3, destH3);
  }
    inline SEXP isValidDirectedEdge(SEXP edge) {
    return h3rIsValidDirectedEdge(edge);
  }
    inline SEXP getDirectedEdgeOrigin(SEXP edge) {
    return h3rGetDirectedEdgeOrigin(edge);
  }
    inline SEXP getDirectedEdgeDestination(SEXP edge) {
    return h3rGetDirectedEdgeDestination(edge);
  }
    inline SEXP directedEdgeToCells(SEXP edge) {
    return h3rDirectedEdgeToCells(edge);
  }
    inline SEXP originToDirectedEdges(SEXP origH3) {
    return h3rOriginToDirectedEdges(origH3);
  }
    inline SEXP directedEdgeToBoundary(SEXP h3) {
    return h3rDirectedEdgeToBoundary(h3);
  }
    inline SEXP cellToVertex(SEXP h3, SEXP vertexNum) {
    return h3rCellToVertex(h3, vertexNum);
  }
    inline SEXP cellToVertexes(SEXP h3) {
    return h3rCellToVertexes(h3);
  }
    inline SEXP vertexToLatLng(SEXP h3) {
    return h3rVertexToLatLng(h3);
  }
    inline SEXP isValidVertex(SEXP h3) {
    return h3rIsValidVertex(h3);
  }
    inline SEXP degsToRads(SEXP degrees) {
    return h3rDegsToRads(degrees);
  }
    inline SEXP radsToDegs(SEXP degrees) {
    return h3rRadsToDegs(degrees);
  }
    inline SEXP getHexagonArea(SEXP res, int areaType) {
    return h3rGetHexagonArea(res, areaType);
  }
    inline SEXP getHexagonAreaAvgM2(SEXP res) {
    return h3rGetHexagonAreaAvgM2(res);
  }
    inline SEXP getHexagonAreaAvgKm2(SEXP res) {
    return h3rGetHexagonAreaAvgKm2(res);
  }
    inline SEXP cellArea(SEXP h3, int areaType) {
    return h3rCellArea(h3, areaType);
  }
    inline SEXP cellAreaRads2(SEXP h3) {
    return h3rCellAreaRads2(h3);
  }
    inline SEXP cellAreaM2(SEXP h3) {
    return h3rCellAreaM2(h3);
  }
    inline SEXP cellAreaKm2(SEXP h3) {
    return h3rCellAreaKm2(h3);
  }
    inline SEXP getHexagonEdgeLengthAvg(SEXP res, int distType) {
    return h3rGetHexagonEdgeLengthAvg(res, distType);
  }
    inline SEXP getHexagonEdgeLengthAvgM(SEXP res) {
    return h3rGetHexagonEdgeLengthAvgM(res);
  }
    inline SEXP getHexagonEdgeLengthAvgKm(SEXP res) {
    return h3rGetHexagonEdgeLengthAvgKm(res);
  }
    inline SEXP edgeLength(SEXP edge, int distType) {
    return h3rEdgeLength(edge, distType);
  }
    inline SEXP edgeLengthRads(SEXP edge) {
    return h3rEdgeLengthRads(edge);
  }
    inline SEXP edgeLengthM(SEXP edge) {
    return h3rEdgeLengthM(edge);
  }
    inline SEXP edgeLengthKm(SEXP edge) {
    return h3rEdgeLengthKm(edge);
  }
    inline SEXP getNumCells(SEXP res) {
    return h3rGetNumCells(res);
  }
    inline SEXP getRes0Cells() {
    return h3rGetRes0Cells();
  }
    inline SEXP res0CellCount() {
    return h3rRes0CellCount();
  }
    inline SEXP getPentagons(SEXP res) {
    return h3rGetPentagons(res);
  }
    inline SEXP pentagonCount() {
    return h3rPentagonCount();
  }
    inline SEXP greatCircleDistance(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons, int distType) {
    return h3rGreatCircleDistance(aLats, aLons, bLats, bLons, distType);
  }
    inline SEXP greatCircleDistanceRads(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons) {
    return h3rGreatCircleDistanceRads(aLats, aLons, bLats, bLons);
  }
    inline SEXP greatCircleDistanceM(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons) {
    return h3rGreatCircleDistanceM(aLats, aLons, bLats, bLons);
  }
    inline SEXP greatCircleDistanceKm(SEXP aLats, SEXP aLons, SEXP bLats, SEXP bLons) {
    return h3rGreatCircleDistanceKm(aLats, aLons, bLats, bLons);
  }

}


#endif  // __cplusplus

#endif // R_H3R_API_H
