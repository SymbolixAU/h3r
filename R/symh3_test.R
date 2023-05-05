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


# library(geosphere)
#
# cell <- "81283ffffffffff" # Res3: 832800fffffffff
# cell_path <- c(cell, directions_cell(origin = cell, distance = 20L, direction = "I")[[1]])
#
# output_df <- NULL
# for (i in 1:(length(cell_path) - 1)) {
#   result<- directedEdgeToBoundary(cellsToDirectedEdge(cell_path[i], cell_path[i + 1]))
#   edge <- names(result)
#   centre <- geosphere::midPoint(c(result[[edge]]$lng[1], result[[edge]]$lat[1]), c(result[[edge]]$lng[2], result[[edge]]$lat[2]))
#   output_df <- rbind(output_df, data.frame(
#     cell = cell_path[i],
#     edge = edge,
#     point = centre,
#     stringsAsFactors = FALSE
#   ))
# }
# output_df
#
# output_df_2 <- NULL
# for (i in 1:(nrow(output_df) - 1)) {
#   orig <- c(output_df[i,]$point.lon, output_df[i,]$point.lat)
#   dest <- c(output_df[i + 1,]$point.lon, output_df[i + 1,]$point.lat)
#   output_df_2 <- rbind(output_df_2, data.frame(
#     origin.lon = orig[1],
#     origin.lat = orig[2],
#     distance = geosphere::distHaversine(orig, dest),
#     bearing = geosphere::bearing(orig, dest),
#     stringsAsFactors = FALSE
#   ))
# }
# print(paste0("Res: ", getResolution(cell)))
# output_df_2

