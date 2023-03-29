
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
#' getResolution(cell = cell)
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

#' Cell To Center Child
#'
#' Provies the center child index contained by `cell` at the `childRes` resolution
#'
#' @export
cellToCenterChild <- function(cell, childRes) {

}

## TODO:
# cellToChildrenSize <-- returns int64_t
# cellToCenterChild
# cellToChildPos
# compactCells
# uncompactCells
# uncompactCellsSize
