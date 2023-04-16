
#' Polygon to cells
#'
#' Returns the h3 indexes for the input GeoJSON-like data structure
#'
#' @param polygons an array of polygons. Each polygon is an array of vectors. Each vector is a list of (lat, lon) or (lon, lat)
#' @param resolution The resolution of the output cells
#' @param isGeojson if the input isGeoJson (each vertex is (lon, lat)). The default is 0L (each vertex is (lat, lon))
#'
#' @return h3 indexes for the input GeoJSON-like data structure
#'
#' @examples
#'
#' polygonToCells(
#'   list(
#'     list(
#'       c(37.813318999983238, -122.4089866999972145)
#'       , c(37.7198061999978478, -122.3544736999993603)
#'       , c(37.8151571999998453, -122.4798767000009008)
#'       )
#'      )
#'    , 7L
#'  )
#'
#' polygonToCells(
#'   list(
#'     list(
#'       c(37.813318999983238, -122.4089866999972145)
#'       , c(37.7198061999978478, -122.3544736999993603)
#'       , c(37.8151571999998453, -122.4798767000009008)
#'       )
#'      , list(
#'        c(37.813318999983238, -122.4089866999972145)
#'        , c(37.7198061999978478, -122.3544736999993603)
#'        , c(37.8151571999998453, -122.4498767000009008)
#'        )
#'      )
#'    , 7L
#'  )
#'
#' @export
polygonToCells <- function(polygons, resolution, isGeoJson = 0L) {
  .Call(h3rPolygonToCells, polygons, resolution, isGeoJson)
}


#' Cells to GeoPolygons
#'
#' Get the outlines of a set of H3 hexagons, returned in GeoJSON-like MultiPolygon.
#'
#' @param cellSet list of string vectors containing to be H3 cell indexes
#' @param isGeojson if the input isGeoJson (each vertex is (lon, lat)). The default is 0L (each vertex is (lat, lon))
#'
#' @return GeoJSON-like MultiPolygon containing the outlines of the set of input H3 hexagons
#'
#' @examples
#'
#' cellsToMultiPolygon(cellSet = list(c("872830828ffffff", "87283082effffff")), 1L)
#'
#' @export
cellsToMultiPolygon <- function(cellSet, isGeoJson = 0L) {
  .Call(h3rCellsToMultiPolygon, cellSet, isGeoJson)
}
