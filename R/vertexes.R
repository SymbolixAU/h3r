
#' Cell To Vertex
#'
#' Returns the index for the specified cell vertex.
#' Valid vertex numbers are between 0 and 5 (inclusive) for hexagonal cells,
#' and 0 and 4 (inclusive) for pentagonal cells.
#'
#' @inheritParams cellToLatLng
#' @param vertexNum integer giving the vertex number of the index to return
#'
#' @examples
#'
#' cellToVertex(
#'   cell = c(rep("8cbe63562a54bff", 6))
#'   , vertexNum = c(0L:5L)
#'   )
#'
#' @export
cellToVertex <- function(cell, vertexNum) {
  .Call(h3rCellToVertex, cell, vertexNum)
}

#' Cell To Vertexes
#'
#' Returns the indexes for all vertices of the given `cell`. The
#' Output will have a 0 in the result if the input `cell` is a pentagon
#'
#' @inheritParams latLngToCell
#'
#' @examples
#'
#' cellToVertexes(cell = c("8cbe63562a54bff", "8cbe635631103ff") )
#'
#'
#' @export
cellToVertexes <- function(cell) {
  .Call(h3rCellToVertexes, cell)
}


#' Vertex To Lat Lng
#'
#' Returns the latitude and longitude of the given vertex
#'
#' @param vertex H3 Vertex index
#'
#' @examples
#'
#' vertexToLatLng(
#'   vertex = cellToVertex(
#'     vertex = c("24cbe63562a549ff","255283463fffffff")
#'     )
#' )
#'
#'
#' @export
vertexToLatLng <- function(vertex) {
  .Call(h3rVertexToLatLng, vertex)
}


#' Is Valid Vertex
#'
#' Returns 1 if the given index represents a valid H3 vertex
#'
#' @inheritParams vertexToLatLng
#'
#' @examples
#'
#' isValidVertex(vertex = c("24cbe63562a549ff", "abc"))
#'
#'
#' @export
isValidVertex <- function(vertex) {
  .Call(h3rIsValidVertex, vertex)
}

