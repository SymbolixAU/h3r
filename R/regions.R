
#' Polygon to cells
#'
#' Returns the h3 indexes for the input GeoJSON-like data structure
#'
#' @param polygons A list of polygons. Each polygon is list of matrices.
#' @param resolution The resolution of the output cells
#' @param isLatLng `TRUE` (default) if the coordinates are in `lat / lng` order.
#' `FALSE` otherwise
#'
#' @return h3 indexes for the input GeoJSON-like data structure
#'
#' @examples
#'
#' ## single polygon
#' polygon <- list(
#'   list(
#'   matrix(
#'     c(
#'     37.813318999983238, -122.4089866999972145,
#'     37.7198061999978478, -122.3544736999993603,
#'     37.8151571999998453, -122.4798767000009008
#'     )
#'     , ncol = 2
#'     , byrow = TRUE
#'   )
#'   )
#' )
#'
#' polygonToCells(polygon, resolution = 7L)
#'
#' ## poylgon with a hole
#' polygon <- list(
#' list(
#'   matrix(
#'     c(
#'     37.813318999983238, -122.4089866999972145,
#'     37.7198061999978478, -122.3544736999993603,
#'     37.8151571999998453, -122.4798767000009008
#'     )
#'     , ncol = 2
#'     , byrow = TRUE
#'   ),
#'   matrix(
#'     c(
#'     37.813318999983238, -122.4089866999972145,
#'     37.7198061999978478, -122.3544736999993603,
#'     37.8151571999998453, -122.4498767000009008
#'     )
#'     , ncol = 2
#'     , byrow = TRUE
#'   )
#' )
#' )
#'
#' polygonToCells(polygon, resolution = 7L)
#'
#' ## Many polygons
#' polygon <- list(
#'   list(
#'     matrix(
#'       c(
#'       37.813318999983238, -122.4089866999972145,
#'       37.7198061999978478, -122.3544736999993603,
#'       37.8151571999998453, -122.4798767000009008
#'       )
#'       , ncol = 2
#'       , byrow = TRUE
#'     )
#'    ),
#'  list(
#'   matrix(
#'     c(
#'     37.813318999983238, -122.4089866999972145,
#'     37.7198061999978478, -122.3544736999993603,
#'     37.8151571999998453, -122.4498767000009008
#'     )
#'     , ncol = 2
#'     , byrow = TRUE
#'     )
#'   )
#' )
#'
#' polygonToCells(polygon, resolution = c(7L, 7L))
#'
#'
#' @export
polygonToCells <- function(polygons, resolution, isLatLng = TRUE) {
  .Call(h3rPolygonToCells, polygons, int(resolution), int(isLatLng))
}


#' Cells to GeoPolygons
#'
#' Get the outlines of a set of H3 hexagons, returned in GeoJSON-like
#' MultiPolygon.
#'
#' @param cellSet list of string vectors containing to be H3 cell indexes
#' @inheritParams polygonToCells
#'
#' @return GeoJSON-like MultiPolygon containing the outlines of the set of
#' input H3 hexagons
#'
#' @examples
#'
#' cellsToMultiPolygon(
#'   cellSet = list(
#'     list(c("872830828ffffff", "87283082effffff"))
#'     , list(c("872830828ffffff"))
#'     )
#'     , 1L
#'   )
#'
#' @export
cellsToMultiPolygon <- function(cellSet, isLatLng = TRUE) {
  .Call(h3rCellsToMultiPolygon, cellSet, int(isLatLng))
}
