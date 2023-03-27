#' lat lng to cell
#'
#' Indexes the location at the specified resolution, returning the index of the cell
#' containing the location. This buckets the geographic point into the H3 grid
#'
#' @param lat latitude
#' @param lng longitude
#' @param resolution cell resolution
#'
#' @examples
#'
#' latLngToCell(
#'   lat = c(-37.820197, -37.818476)
#'   , lng = c(144.983324, 144.967354)
#'   , resolution = 12L
#'   )
#'
#' @export
latLngToCell <- function(lat, lng, resolution) {
  .Call(h3rLatLngToCell, lat, lng, resolution)
}

#' Cell To Lat Lon
#'
#' Finds the center of the cell in grid space
#'
#' @param cell vector of H3 cells
#'
#' @return a list of two vectors, `lat` and `lng`, each the same length as `cell`,
#' giving the center of `cell`
#'
#' @examples
#'
#' cellToLatLng(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @export
cellToLatLng <- function(cell) {
  .Call(h3rCellToLatLng, cell)
}

#' Cell To Boundary
#'
#' @inheritParams cellToLatLng
#'
#' @return named list, each element named with the input H3 cell, and containing
#' a `lat` and `lng` vector
#'
#' @examples
#'
#' cellToBoundary(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @export
cellToBoundary <- function(cell) {
  .Call(h3rCellToBoundary, cell)
}
