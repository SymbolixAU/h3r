#' @useDynLib h3rcpp, .registration = TRUE
#' @import Rcpp
NULL

#' ll2Cel
#'
#' LatLon to Cell
#'
#'
#' @examples
#'
#' ll2Cell(
#'   lat = c(-37.820197, -37.818476)
#'   , lon = c(144.983324, 144.967354)
#'   , res = 12L
#'   )
#'
#' @export
ll2Cell <- function(lat, lon, res) {
  return( h3rcppLatLngToCell(lat, lon, res))
}
