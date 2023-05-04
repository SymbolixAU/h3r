
#' Degrees To Rads
#'
#' Converts Degrees to Radians
#'
#' @param deg vector of degrees
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
  .Call(h3rGetHexagonAreaAvgM2, resolution)
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
  .Call(h3rGetHexagonAreaAvgKm2, resolution)
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
  .Call(h3rGetHexagonEdgeLengthAvgM, resolution)
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
  .Call(h3rGetHexagonEdgeLengthAvgKm, resolution)
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
  .Call(h3rGetNumCells, resolution)
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

# #' Get the number of resolution 0 H3 indexes, which is defined as 122.
# #'
# #' @return the number of resolution 0 H3 indexes, which is defined as 122.
# #'
# #' @examples
# #'
# #' res0CellCount()
# #'
# #' @export
# res0CellCount <- function() {
#   .Call(h3rRes0CellCount)
# }

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
  .Call(h3rGetPentagons, resolution)
}

# #' Get the number of pentagon H3 indexes per resolution. This is always 12,
# #' but provided as a convenience.
# #'
# #' @return the number of pentagon H3 indexes per resolution.
# #'
# #' @examples
# #'
# #' pentagonCount()
# #'
# #' @export
# pentagonCount <- function() {
#   .Call(h3rPentagonCount)
# }

#' Great Circle Distance In Radians
#'
#' @examples
#'
#' greatCircleDistanceRads(
#'   aLats = c(-37.820197)
#'   , aLons = c(144.983324)
#'   , bLats = c(-37.818476)
#'   , bLons = c(144.967354)
#' )
#'
#' @export
greatCircleDistanceRads <- function(aLats, aLons, bLats, bLons) {
  .Call(h3rGreatCircleDistanceRads, aLats, aLons, bLats, bLons)
}


#' Great Circle Distance In Meters
#'
#' @examples
#'
#' greatCircleDistanceM(
#'   aLats = c(-37.820197)
#'   , aLons = c(144.983324)
#'   , bLats = c(-37.818476)
#'   , bLons = c(144.967354)
#' )
#'
#' @export
greatCircleDistanceM <- function(aLats, aLons, bLats, bLons) {
  .Call(h3rGreatCircleDistanceM, aLats, aLons, bLats, bLons)
}

#' Great Circle Distance In Kilometers
#'
#' @examples
#'
#' greatCircleDistanceKm(
#'   aLats = c(-37.820197)
#'   , aLons = c(144.983324)
#'   , bLats = c(-37.818476)
#'   , bLons = c(144.967354)
#' )
#'
#' @export
greatCircleDistanceKm <- function(aLats, aLons, bLats, bLons) {
  .Call(h3rGreatCircleDistanceKm, aLats, aLons, bLats, bLons)
}



#' Direction For Neighbor
#'
#'
#' @export
directionForNeighbor <- function(origin, destination) {
  .Call(h3rDirectionForNeighbour, origin, destination)
}
