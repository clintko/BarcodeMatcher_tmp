#' your_package
#' 
#' Description of your package
#' 
#' @docType package
#' @author clintko 
#' @import Rcpp
#' @importFrom Rcpp evalCpp
#' @useDynLib BarcodeMatcher
#' @name BarcodeMatcher
NULL  

#' create an R function with the document. The document is copied from klutometis/roxygen
#'
#' @param x input numeric vector
#' @param y input numeric vector
#' @seealso \code{\link{fun_add}} which this function wraps
#' @export
#' @examples
#' str_length(letters)
#' str_length(c("i", "like", "programming", NA))
myfun <- function(x, y) {
    result = myfun_add(x, y)
    print(result)
}

#' create second R function with the document.
#'
#' @param x input numeric vector
#' @param y input numeric vector
#' @return sum up the numeric vectors
#' @seealso \code{\link{fun}} which this function wraps
#' @export
#' @examples
#' str_length(letters)
#' str_length(c("i", "like", "programming", NA))
myfun_add <- function(x, y) {
    return(x + y)
}