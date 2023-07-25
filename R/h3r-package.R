#' @useDynLib "h3r", .registration = TRUE
#' @import h3lib
NULL

#' Stations
#'
#' A data set of train stations in Melbourne
#'
#' @format
#' \describe{
#'  \item{stop_id}{The ID of the station}
#'  \item{stop_name}{The name of the station}
#'  \item{lat}{The latitude coordinate of the station}
#'  \item{lon}{The longitude coordinate of the station}
#' }
#'
#' @details
#' Obtained from \url{https://discover.data.vic.gov.au/dataset/timetable-and-geographic-information-gtfs}
#' and distributed under the Creative Commons 4 License \url{https://creativecommons.org/licenses/by/4.0/}
"stations"

int <- function(x) as.integer(x)

