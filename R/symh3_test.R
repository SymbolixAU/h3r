#' Get the h3 cells from the origin to an direction within a certain distance
#'
#' @param origin_vector vector of origin H3 cell indexes
#' @param distance_vector int vector of distance
#' @param direction_vector string vector of direction. Choices are `c('I', 'J', 'K', 'IJ', 'IK', 'JK')`
#'
#' @return a list of lists of h3 cells on the path of an origin to distance away on direction
#'
#' @examples
#' directions_cell(origin_vector = c("8cbe63562a54bff", "8cbe635631103ff")
#'                , distance_vector = c(5L, 100L)
#'                , direction_vector = c("I", "JK"))
#'
#' @export
directions_cell <- function(origin_vector, distance_vector, direction_vector) {
  .Call(symh3_directions_cell, origin_vector, distance_vector, direction_vector)
}
