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



# cell_path <- c("8cbe63562a54bff", directions_cell(origin = c("8cbe63562a54bff"), distance = c(5L), direction = c("I", "JK"))[[1]])
#
# output_df <- NULL
# for (i in 1:(length(cell_path) - 1)) {
#   result<- directedEdgeToBoundary(cellsToDirectedEdge(cell_path[i], cell_path[i + 1]))
#   edge <- names(result)
#   output_df <- rbind(output_df, data.frame(
#     cell = cell_path[i],
#     edge = edge,
#     lat_1 = result[[edge]]$lat[1],
#     lat_2 = result[[edge]]$lat[2],
#     lng_1 = result[[edge]]$lng[1],
#     lng_2 = result[[edge]]$lng[2],
#     stringsAsFactors = FALSE
#   ))
# }
#
# output_df
