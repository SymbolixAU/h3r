#' @useDynLib h3rc, .registration = TRUE
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
  .Call(h3rcLatLngToCell, lat, lon, res)
}


#' #' Direction for neighbour
#' #'
#' #' An example caling the `directionForNeighbor` C funciton direclty from H3
#' #' (exported through `h3rapi.H`)
#' #'
#' #' @examples
#' #'
#' #' directionForNeighbour("89bf4ac0cd7ffff", "89bf4ac0c8bffff")
#' #' directionForNeighbour("88bf4ac0cdfffff", "88bf4ac01bfffff")
#' #' directionForNeighbour("8abf4ac0b857fff", "8abf4ac0b857fff")
#' #'
#' #' @export
#' directionForNeighbour <- function(origin, destination) {
#'   .Call(h3rcDirectionForNeighbour, origin, destination)
#' }
