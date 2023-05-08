
#' Are neighbor cells
#'
#' Returns whether or not the provided H3 cell indexes are neighbors
#'
#' @param origin vector of origin H3 cell indexes
#' @param destination vector of destination H3 cell indexes
#'
#' @return 1 if the indexes are neighbors, 0 otherwise.
#'
#' @examples
#'
#' areNeighborCells(
#'   origin = c("85283473fffffff","85283473fffffff")
#'   , destination = c("85283471fffffff","85283477fffffff")
#'  )
#'
#' @export
areNeighborCells <- function(origin, destination) {
  .Call(h3rAreNeighborCells, origin, destination)
}

#' Cells to directed edge
#'
#' Returns a unidirectional edge H3 index based on the provided origin
#' and destination.
#'
#' @param origin vector of origin H3 cell indexes
#' @param destination vector of destination H3 cell indexes
#'
#' @return a unidirectional edge H3 index based on the provided origin
#' and destination.
#'
#' @examples
#'
#' cellsToDirectedEdge(
#'   origin = c("85283471fffffff","85283473fffffff")
#'   , destination = c("85283475fffffff","85283477fffffff")
#'  )
#'
#' @export
cellsToDirectedEdge <- function(origin, destination) {
  .Call(h3rCellsToDirectedEdge, origin, destination)
}

#' Is valid directed edge
#'
#' Determines if the provided H3Index is a valid unidirectional edge index.
#'
#' @param edge vector of unidirectional edge H3 indexes
#'
#' @return 1 if it is a unidirectional edge H3Index, otherwise 0.
#'
#' @examples
#'
#' isValidDirectedEdge(edge = c("13d2a1672b34ffff","16a2a1072b59ffff"))
#'
#' @export
isValidDirectedEdge <- function(edge) {
  .Call(h3rIsValidDirectedEdge, edge)
}

#' Get the origin cell of the unidirectional edge
#'
#' @param edge vector of unidirectional edge H3 indexes
#'
#' @return the origin hexagon from the unidirectional edge H3Index.
#'
#' @examples
#'
#' getDirectedEdgeOrigin((edge = c("115283473fffffff","16a2a1072b59ffff")))
#'
#' @export
getDirectedEdgeOrigin <- function(edge) {
  .Call(h3rGetDirectedEdgeOrigin, edge)
}

#' Get the destination cell of the unidirectional edge
#'
#' @param edge vector of unidirectional edge H3 indexes
#'
#' @return the destination hexagon from the unidirectional edge H3Index.
#'
#' @examples
#'
#' getDirectedEdgeDestination(edge = c("115283473fffffff","16a2a1072b59ffff"))
#'
#' @export
getDirectedEdgeDestination <- function(edge) {
  .Call(h3rGetDirectedEdgeDestination, edge)
}

#' Get the origin and destination cells of the unidirectional edge
#'
#' @param edge vector of unidirectional edge H3 indexes
#'
#' @return the origin, destination pair of hexagon IDs for the given edge ID
#'
#' @examples
#'
#' directedEdgeToCells(edge = c("115283473fffffff","115283471fffffff"))
#'
#' @export
directedEdgeToCells <- function(edge) {
  .Call(h3rDirectedEdgeToCells, edge)
}

#' Get all of the directed edges from an origin
#'
#' @param origin vector of origin H3 cell indexes
#'
#' @return a vector for each origin with all of the directed edges from the
#' current H3Index
#'
#' @examples
#'
#' originToDirectedEdges(origin = c("85283473fffffff","8cbe635631103ff"))
#'
#' @export
originToDirectedEdges <- function(origin) {
  .Call(h3rOriginToDirectedEdges, origin)
}

#' Directed edge To Boundary
#'
#' @param edge unidirectional edge
#'
#' @return named list, each element named with the input H3 cell, and containing
#' a `lat` and `lng` vector
#'
#' @examples
#'
#' directedEdgeToBoundary(edge = c("115283473fffffff","115283477fffffff"))
#'
#' @export
directedEdgeToBoundary <- function(edge) {
  .Call(h3rDirectedEdgeToBoundary, edge)
}
