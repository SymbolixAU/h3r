
#' Grid Disk
#'
#' Get indices within k distance of the origin index.
#'
#' Elements of the output array may be left as zero, which can happen when
#' crossing a pentagon.
#'
#' k-ring 0 is defined as the origin index, k-ring 1 is defined as k-ring 0
#' and all neighboring indexes, and so on.
#'
#' @param cell vector of H3 cells
#' @param k int distance
#'
#' @return the indices within k distance of the origin index
#'
#' @examples
#'
#' gridDisk(cell = c("8cbe63562a54bff","8cbe635631103ff"), k = c(1L, 2L))
#'
#' @export
gridDisk <- function(cell, k) {
  .Call(h3rGridDisk, cell, as.integer(k))
}

#' #' Get the maximum number of indices that result from the gridDisk algorithm
#' #' with the given k.
#' #'
#' #' k-ring 0 is defined as the origin index, k-ring 1 is defined as k-ring 0
#' #' and all neighboring indexes, and so on.
#' #'
#' #' @param k int distance
#' #'
#' #' @return maximum number of indices that result from the gridDisk algorithm
#' #' with the given k.
#' #'
#' #' @examples
#' #'
#' #' maxGridDiskSize(k = c(1L, 2L))
#' #'
#' #' @export
#' maxGridDiskSize <- function(k) {
#'   .Call(h3rMaxGridDiskSize, k)
#' }

#' Grid Disk Distances
#'
#' Get indices within k distance of the origin index.
#'
#' k-ring 0 is defined as the origin index, k-ring 1 is defined as k-ring 0
#' and all neighboring indexes, and so on.
#'
#' @param cell vector of H3 cells
#' @param k int distance
#'
#' @return indices within k distance of the origin index.
#'
#' @examples
#'
#' gridDiskDistances(cell = c("8cbe63562a54bff","8cbe635631103ff")
#'                  , k = c(1L, 2L))
#'
#' @export
gridDiskDistances <- function(cell, k) {
  .Call(h3rGridDiskDistances, cell, as.integer(k))
}

# #' Get indices within k distance of the origin index (unsafe version).
# #'
# #' k-ring 0 is defined as the origin index, k-ring 1 is defined as k-ring 0
# #' and all neighboring indexes, and so on.
# #'
# #' @param cell vector of H3 cells
# #' @param k int distance
# #'
# #' @return the indices within k distance of the origin index
# #'
# #' @examples
# #'
# #' gridDiskUnsafe(cell = c("8cbe63562a54bff","8cbe635631103ff")
# #'               , k = c(1L, 2L))
# #'
# #' @export
# gridDiskUnsafe <- function(cell, k) {
#   .Call(h3rGridDiskUnsafe, cell, k)
# }

# #' Get indices within k distance of the origin index (unsafe version).
# #'
# #' k-ring 0 is defined as the origin index, k-ring 1 is defined as k-ring 0
# #' and all neighboring indexes, and so on.
# #'
# #' @param cell vector of H3 cells
# #' @param k int distance
# #'
# #' @return indices within k distance of the origin index.
# #'
# #' @examples
# #'
# #' gridDiskDistancesUnsafe(cell = c("8cbe63562a54bff","8cbe635631103ff")
# #'                        , k = c(1L, 2L))
# #'
# #' @export
# gridDiskDistancesUnsafe <- function(cell, k) {
#   .Call(h3rGridDiskDistancesUnsafe, cell, k)
# }

# #' Get indices within k distance of the origin index (safe version).
# #'
# #' k-ring 0 is defined as the origin index, k-ring 1 is defined as k-ring 0
# #' and all neighboring indexes, and so on.
# #'
# #' @param cell vector of H3 cells
# #' @param k int distance
# #'
# #' @return indices within k distance of the origin index
# #'
# #' @examples
# #'
# #' gridDiskDistancesSafe(cell = c("8cbe63562a54bff","8cbe635631103ff")
# #'                      , k = c(1L, 2L))
# #'
# #' @export
# gridDiskDistancesSafe <- function(cell, k) {
#   .Call(h3rGridDiskDistancesSafe, cell, k)
# }

#' Grid Ring Unsafe
#'
#' Produces the hollow hexagonal ring centered at origin with sides of length k.
#'
#' @param cell vector of H3 cells
#' @param k side length
#'
#' @return the indices of the hollow hexagonal ring centered at origin with
#' sides of length k.
#'
#' @examples
#'
#' gridRingUnsafe(cell = c("8cbe63562a54bff","85283473fffffff"), k = c(2L, 1L))
#'
#' @export
gridRingUnsafe <- function(cell, k) {
  .Call(h3rGridRingUnsafe, cell, as.integer(k))
}

#' Grid Path Cells
#'
#' Given two H3 indexes, return the line of indexes between them (inclusive).
#'
#' This function may fail to find the line between two indexes, for example if
#' they are very far apart.
#' It may also fail when finding distances for indexes on opposite sides of a
#' pentagon.
#'
#' @param origin vector of origin H3 cell indexes
#' @param destination vector of destination H3 cell indexes
#'
#' @return the line of indexes between the two H3 cells
#'
#' @examples
#'
#' gridPathCells(origin = c("85283473fffffff","85283473fffffff")
#'               , destination = c("85283471fffffff","85283477fffffff"))
#'
#' @export
gridPathCells <- function(origin, destination) {
  .Call(h3rGridPathCells, origin, destination)
}

#' #' Get the size of the grid of cells forming the shortest path between two H3
#' #' cells.
#' #'
#' #' @param origin vector of origin H3 cell indexes
#' #' @param destination vector of destination H3 cell indexes
#' #'
#' #' @return the size of the grid of cells forming the shortest path between
#' #' the two H3 cells
#' #'
#' #' @examples
#' #'
#' # gridPathCellsSize(origin = c("85283473fffffff","85283473fffffff")
#' #                   , destination = c("85283471fffffff","85283477fffffff"))
#' #'
#' #' @export
#' gridPathCellsSize <- function(origin, destination) {
#'   .Call(h3rGridPathCellsSize, origin, destination)
#' }

#' Grid Distance
#'
#' Provides the distance in grid cells between the two indexes.
#'
#' @param origin vector of origin H3 cell indexes
#' @param destination vector of destination H3 cell indexes
#'
#' @return the grid distance between the two H3 cells
#'
#' @examples
#'
#' gridDistance(origin = c("85283473fffffff","85283473fffffff"),
#'              destination = c("8528342bfffffff","85283477fffffff"))
#'
#' @export
gridDistance <- function(origin, destination) {
  .Call(h3rGridDistance, origin, destination)
}

#' Cell to Local IJ
#'
#' Produces local IJ coordinates for an H3 index anchored by an origin.
#'
#' @param origin vector of anchor cell
#' @param cell vector of cell you input
#'
#' @return (i, j) coordinates
#'
#' @examples
#'
#' cellToLocalIj(origin = c("85283473fffffff","85283473fffffff")
#'              , cell = c("8528342bfffffff","85283477fffffff"))
#'
#' @export
cellToLocalIj <- function(origin, cell) {
  .Call(h3rCellToLocalIj, origin, cell)
}

#' Local IJ To Cell
#'
#' Produces an H3 index from local IJ coordinates anchored by an origin.
#'
#' @param origin vector of anchor cell
#' @param i vector of local I coordinate
#' @param j vector of local I coordinate
#'
#' @return cell vector of H3 cells
#'
#' @examples
#'
#' localIjToCell(origin = c("85283473fffffff","85283473fffffff")
#'              , i = c(1L, 2L), j = c(2L, 1L))
#'
#' @export
localIjToCell <- function(origin, i, j) {
  .Call(h3rLocalIjToCell, origin, as.integer(i), as.integer(j))
}
