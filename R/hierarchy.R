
#' Cell To Parent
#'
#' Provides the parent (coarser) index containing `cell`
#'
#' @inheritParams cellToLatLng
#' @param parentRes integer vector specifying the parent resolution for each `cell`
#'
#' @return vector of parent cells for each `cell`
#'
#' @examples
#'
#' cell <- "8cbe63562a54bff"
#' getResolution(cell = cell)2
#'
#' ## The `parentRes` should be a lower value than the result of `getResolution()`
#' cellToParent(cell = rep(cell, 2), parentRes = c(11L, 10L))
#'
#'
#' @export
cellToParent <- function(cell, parentRes) {
  .Call(h3rCellToParent, cell, parentRes)
}


#' Cell To Children
#'
#' Returns all the H3 indexes contained by the input `cell` and the defined child resolution
#'
#' @return a named list, where each element is the input `cell`, and the values
#' of each element are the child H3 cells
#'
#' @examples
#'
#' cell <- "8cbe63562a54bff"
#' getResolution(cell = cell)
#'
#' cellToChildren(cell, childRes = 13L)
#'
#' @export
cellToChildren <- function(cell, childRes) {
  .Call(h3rCellToChildren, cell, childRes)
}

#' Provies the center child index contained by `cell` at the `childRes` resolution
#'
#' @param cell vector of H3 cells
#' @param childRes integer vector specifying the child resolution for each `cell`
#'
#' @return index of the child cells
#'
#' @examples
#'
#' cellToCenterChild(cell = c("85283473fffffff","85283473fffffff"), childRes = c(7L, 8L))
#'
#' @export
cellToCenterChild <- function(cell, childRes) {
  .Call(h3rCellToCenterChild, cell, childRes)
}

#' Returns the position of the child cell within an ordered list of all children of the cell's parent at the specified resolution parentRes.
#'
#' @param cell vector of child H3 cells
#' @param parentRes integer vector specifying the parent resolution for each `cell`
#'
#' @return the position of the child cell
#'
#' @examples
#'
#' cellToChildPos(cell = c("8cbe63562a54bff","8cbe635631103ff"), parentRes = c(1L, 2L))
#'
#' @export
cellToChildPos <- function(cell, parentRes) {
  .Call(h3rCellToChildPos, cell, parentRes)
}

#' Returns the child cell at a given position within an ordered list of all children of parent at the specified resolution childRes.
#'
#' @param childPos the position of the child cell
#' @param cell vector of parent H3 cells
#' @param childRes integer vector specifying the child resolution for each `cell`
#'
#' @return the position of the child cell
#'
#' @examples
#'
#' childPosToCell(childPos = c(42, 41), cell = c("85283473fffffff","85283473fffffff"), childRes = c(7L, 7L))
#'
#' @export
childPosToCell <- function(childPos, cell, childRes) {
  .Call(h3rChildPosToCell, childPos, cell, childRes)
}

#' Compacts the set cellSet of indexes as best as possible, into the array compactedSet.
#'
#' @param cellSet list of character vectors containing to be compacted H3 cell indexes
#'
#' @return a list of character vectors containing the compacted H3 cell indexes
#'
#' @examples
#'
#' compactCells(gridDisk(cell = c("8cbe63562a54bff","8cbe635631103ff"), k = c(1L, 2L)))
#'
#' @export
compactCells <- function(cellSet) {
.Call(h3rCompactCells, cellSet)
}

#' Uncompacts a set of compacted H3 cell indexes to a given resolution.
#'
#' This function uncompacts the provided set of compacted H3 cell indexes to the specified resolution.
#'
#' @param compactedSet list of character vectors containing compacted H3 cell indexes
#' @param res integer specifying the resolution to uncompact the cells to
#'
#' @return a list of character vectors containing the uncompacted H3 cell indexes at the specified resolution
#'
#' @examples
#'
#' uncompactCells(compactCells(gridDisk('85283473fffffff', 1L)), res = 5L)
#'
#' @export
uncompactCells <- function(compactedSet, res) {
.Call(h3rUncompactCells, compactedSet, res)
}

## TODO:
# cellToChildrenSize <-- returns int64_t
# compactCells
# uncompactCells
# uncompactCellsSize
