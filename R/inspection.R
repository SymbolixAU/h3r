
#' Get Resolution
#'
#' Returns the resolution of the index.
#'
#' @inheritParams cellToLatLng
#'
#' @examples
#'
#' getResolution(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @return a vector the same length as `cell` giving the resolution of each
#' index
#'
#' @export
getResolution <- function(cell) {
  .Call(h3rGetResolution, cell)
}


#' Get Base Cell Number
#'
#' Returns the base cell number of the index
#'
#' @inheritParams cellToLatLng
#'
#' @examples
#'
#' getBaseCellNumber(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @return a vector the same length as `cell` giving the base cell number of
#' each index
#'
#' @export
getBaseCellNumber <- function(cell) {
  .Call(h3rGetBaseCellNumber, cell)
}

## TODO:
# h3ToString
# stringToH3


#' Is Valid Cell
#'
#' Returns non-zero if this is a valid H3 cell index
#'
#' @inheritParams cellToLatLng
#'
#' @examples
#'
#' isValidCell(cell = c("8cbe63562a54bff","8cbe635631103ff", "abc", "3"))
#'
#' @return a vector the same length as `cell` giving the validity of the cell
#'
#' @export
isValidCell <- function(cell) {
  .Call(h3rIsValidCell, cell)
}


#' Is Res Class III
#'
#' Returns non-zero if this index has a resolution with Class III orientation.
#'
#' @inheritParams cellToLatLng
#'
#' @examples
#'
#' isResClassIII(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' hex8 <- "88bf4ac0cdfffff"
#' hex9 <- "89bf4ac0cd7ffff"
#' hex10 <- "8abf4ac0cd67fff"
#' isResClassIII(cell = c(hex8, hex9, hex10))
#'
#' @return a vector the same length as `cell` indicating if the cell is Class II
#'
#' @export
isResClassIII <- function(cell) {
  .Call(h3rIsResClassIII, cell)
}


#' Is Pentagon
#'
#' Returns non-zero if this index represents a pentagonal cell.
#'
#' @inheritParams cellToLatLng
#'
#' @examples
#'
#' isPentagon(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' @return a vector the same length as `cell` indicating if the cell is Class II
#'
#' @export
isPentagon <- function(cell) {
  .Call(h3rIsPentagon, cell)
}

#' Get Icosahedron Faces
#'
#' Find all icosahedron faces intersected by a given H3 index.
#' Faces are represented as integers from 0-19, inclusive.
#' The array is sparse, and empty (no intersection) array values are
#' represented by -1.
#'
#' @inheritParams cellToLatLng
#'
#' @examples
#' getIcosahedronFaces(cell = c("8cbe63562a54bff","8cbe635631103ff"))
#'
#' getIcosahedronFaces(cell = cellToParent(c("8cbe63562a54bff" ,"8cbe635631103ff"), c(7L, 7L)))
#'
#' @return list of vectors. Each list element corresponds to the input `cell` values.
#' Each vector in a list element gives the faces intersected by the `cell`
#'
#' @export
getIcosahedronFaces <- function(cell) {
  .Call(h3rGetIcosahedronFaces, cell)
}

