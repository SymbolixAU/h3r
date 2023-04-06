
#' Polygon to cells
#'
#' Returns the h3 indexes for the input GeoJSON-like data structure
#'
#' @param polygons an array of polygons. Each polygon is an array of vectors. Each vector is a list of (lat, lon) or (lon, lat)
#' @param resolution The resolution of the output cells
#' @param isGeojson if the input isGeoJson (each vertex is (lon, lat)). The default is FALSE (each vertex is (lat, lon))
#'
#' @examples
#'
#' cellToVertex(
#'   cell = c(rep("8cbe63562a54bff", 6))
#'   , vertexNum = c(0L:5L)
#'   )
#'
#' @export
polygonToCells <- function(polygons, resolution, isGeoJson = FALSE) {
  .Call(h3rPolygonToCells, polygons, resolution, isGeoJson)
}
