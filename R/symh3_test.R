#' Get the h3 cells from the origin to an direction within a certain distance
#'
#' @param origin a vector of origin H3 cell indexes
#' @param distance a int vector of distance
#' @param direction a string vector of direction. Choices are `c('I', 'J', 'K', 'IJ', 'IK', 'JK')`
#'
#' @return a list of lists of h3 cells on the path of an origin to distance away on direction
#'
#' @examples
#' directions_cell(origin = c("8cbe63562a54bff", "8cbe635631103ff")
#'                , distance = c(5L, 100L)
#'                , direction = c("I", "JK"))
#'
#' @export
directions_cell <- function(origin, distance, direction) {
  .Call(symh3_directions_cell, origin, distance, direction)
}
