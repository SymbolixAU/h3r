
#' Degrees To Rads
#'
#' Converts Degrees to Radians
#'
#' @param deg vector of degrees
#'
#' @return numeric vector giving the input `deg` values as radians
#'
#' @examples
#'
#' degsToRads(deg = seq(0, 360, by = 15))
#'
#'
#' @export
degsToRads <- function(deg) {
  .Call(h3rDegsToRads, deg)
}

#' Rads to Degrees
#'
#' Converts Radians to Degrees
#'
#' @param rad vector of radians
#'
#' @return numeric vector giving the input `rad` values as degrees
#'
#' @examples
#' radsToDegs(rad = seq(0, 2 * pi, by = (pi / 12) ) )
#'
#' @export
radsToDegs <- function(rad) {
  .Call(h3rRadsToDegs, rad)
}


#' Get the average hexagon area in square meters at the given resolution.
#' Excludes pentagons.
#'
#' @param resolution cell resolution
#'
#' @return Average hexagon area in square meters at the given resolution.
#' Excludes pentagons.
#'
#' @examples
#'
#' getHexagonAreaAvgM2(resolution = c(12L,10L))
#'
#' @export
getHexagonAreaAvgM2 <- function(resolution) {
  .Call(h3rGetHexagonAreaAvgM2, int(resolution))
}

#' Get the average hexagon area in square kilometers at the given resolution.
#' Excludes pentagons.
#'
#' @param resolution cell resolution
#'
#' @return Average hexagon area in square kilometers at the given resolution.
#' Excludes pentagons.
#'
#' @examples
#'
#' getHexagonAreaAvgKm2(resolution = c(12L,10L))
#'
#' @export
getHexagonAreaAvgKm2 <- function(resolution) {
  .Call(h3rGetHexagonAreaAvgKm2, int(resolution))
}

#' Exact area of specific cell in square radians.
#'
#' @param cell vector of H3 cells
#'
#' @return the exact area of specific cell in square radians.
#'
#' @examples
#'
#' cellAreaRads2(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @export
cellAreaRads2 <- function(cell) {
  .Call(h3rCellAreaRads2, cell)
}

#' Exact area of specific cell in square meters.
#'
#' @param cell vector of H3 cells
#'
#' @return the exact area of specific cell in square meters.
#'
#' @examples
#'
#' cellAreaM2(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @export
cellAreaM2 <- function(cell) {
  .Call(h3rCellAreaM2, cell)
}

#' Exact area of specific cell in square kilometers.
#'
#' @param cell vector of H3 cells
#'
#' @return the exact area of specific cell in square kilometers.
#'
#' @examples
#'
#' cellAreaKm2(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @export
cellAreaKm2 <- function(cell) {
  .Call(h3rCellAreaKm2, cell)
}

#' Get the average hexagon edge length in meters at the given resolution.
#' Excludes pentagons.
#'
#' @param resolution cell resolution
#'
#' @return Average hexagon edge length in meters at the given resolution.
#' Excludes pentagons.
#'
#' @examples
#'
#' getHexagonEdgeLengthAvgM(resolution = c(12L,10L))
#'
#' @export
getHexagonEdgeLengthAvgM <- function(resolution) {
  .Call(h3rGetHexagonEdgeLengthAvgM, int(resolution))
}

#' Get the average hexagon edge length in kilometers at the given resolution.
#' Excludes pentagons.
#'
#' @param resolution cell resolution
#'
#' @return Average hexagon edge length in kilometers at the given resolution.
#' Excludes pentagons.
#'
#' @examples
#'
#' getHexagonEdgeLengthAvgKm(resolution = c(12L,10L))
#'
#' @export
getHexagonEdgeLengthAvgKm <- function(resolution) {
  .Call(h3rGetHexagonEdgeLengthAvgKm, int(resolution))
}

#' Get the exact edge length of specific unidirectional edge in radians.
#'
#' @param edge vector of unidirectional H3 edges
#'
#' @return the exact edge length of specific unidirectional edge in radians.
#'
#' @examples
#'
#' edgeLengthRads(edge = c("13d2a1672b34ffff","16a2a1072b59ffff"))
#'
#' @export
edgeLengthRads <- function(edge) {
  .Call(h3rEdgeLengthRads, edge)
}

#' Get the exact edge length of specific unidirectional edge in meters.
#'
#' @param edge vector of unidirectional H3 edges
#'
#' @return the exact edge length of specific unidirectional edge in meters.
#'
#' @examples
#'
#' edgeLengthM(edge = c("13d2a1672b34ffff","16a2a1072b59ffff"))
#'
#' @export
edgeLengthM <- function(edge) {
  .Call(h3rEdgeLengthM, edge)
}

#' Get the exact edge length of specific unidirectional edge in kilometers.
#'
#' @param edge vector of unidirectional H3 edges
#'
#' @return the exact edge length of specific unidirectional edge in kilometers.
#'
#' @examples
#'
#' edgeLengthKm(edge = c("13d2a1672b34ffff","16a2a1072b59ffff"))
#'
#' @export
edgeLengthKm <- function(edge) {
  .Call(h3rEdgeLengthKm, edge)
}

#' Get the number of unique H3 indexes at the given resolution.
#'
#' @param resolution cell resolution
#'
#' @return the number of unique H3 indexes at the given resolution
#'
#' @examples
#'
#' getNumCells(resolution = c(12L,10L))
#'
#' @export
getNumCells <- function(resolution) {
  .Call(h3rGetNumCells, int(resolution))
}

#' Get all the resolution 0 H3 indexes.
#'
#' @return all the resolution 0 H3 indexes.
#'
#' @examples
#'
#' getRes0Cells()
#'
#' @export
getRes0Cells <- function() {
  .Call(h3rGetRes0Cells)
}

#' Get all the pentagon H3 indexes at the specified resolution.
#'
#' @param resolution cell resolution
#'
#' @return all the pentagon H3 indexes at the specified resolution.
#'
#' @examples
#'
#' getPentagons(resolution = c(12L,10L))
#'
#' @export
getPentagons <- function(resolution) {
  .Call(h3rGetPentagons, int(resolution))
}

#' Great Circle Distance In Radians
#'
#' Gives the "great circle" or "haversine" distance between pairs of lat/lng coordinates
#' in radians
#'
#' @param aLat vector of latitude cooridnates (from)
#' @param aLng vector of longitude coordinates (from)
#' @param bLat vector of latitude coordinates (to)
#' @param bLng vector of longitude coordinates (to)
#'
#' @return numeric vector giving the great circle distance in radians
#'
#' @examples
#'
#' greatCircleDistanceRads(
#'   aLat = c(-37.820197)
#'   , aLng = c(144.983324)
#'   , bLat = c(-37.818476)
#'   , bLng = c(144.967354)
#' )
#'
#' @export
greatCircleDistanceRads <- function(aLat, aLng, bLat, bLng) {
  .Call(h3rGreatCircleDistanceRads, aLat, aLng, bLat, bLng)
}


#' Great Circle Distance In Meters
#'
#' Gives the "great circle" or "haversine" distance between pairs of lat/lng coordinates
#' in meters.
#'
#' @inheritParams greatCircleDistanceRads
#'
#' @return numeric vector giving the great circle distance in metres
#' @examples
#'
#' greatCircleDistanceM(
#'   aLat = c(-37.820197)
#'   , aLng = c(144.983324)
#'   , bLat = c(-37.818476)
#'   , bLng = c(144.967354)
#' )
#'
#' @export
greatCircleDistanceM <- function(aLat, aLng, bLat, bLng) {
  .Call(h3rGreatCircleDistanceM, aLat, aLng, bLat, bLng)
}

#' Great Circle Distance In Kilometers
#'
#' Gives the "great circle" or "haversine" distance between pairs of lat/lng coordinates
#' in kilometers.
#'
#' @inheritParams greatCircleDistanceRads
#' @return numeric vector giving the great circle distance in kilometres
#'
#' @examples
#'
#' greatCircleDistanceKm(
#'   aLat = c(-37.820197)
#'   , aLng = c(144.983324)
#'   , bLat = c(-37.818476)
#'   , bLng = c(144.967354)
#' )
#'
#' @export
greatCircleDistanceKm <- function(aLat, aLng, bLat, bLng) {
  .Call(h3rGreatCircleDistanceKm, aLat, aLng, bLat, bLng)
}
