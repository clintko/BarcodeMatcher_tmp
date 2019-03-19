#include "BarcodeMatcher.h"
#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//
//' @export
// [[Rcpp::export]]
int dist_metric_hamming(
        const std::string& str1, 
        const std::string& str2
) {
    // init
    int dist = 0;
    int len1 = str1.size();
    int len2 = str2.size();
    
    // check input
    if(len1 != len2) {
        throw std::invalid_argument("Two strings are not of the same length!");
    } // end if
    
    // calculate hamming disance
    for (int idx = 0; idx < len1; idx += 1){
        if (str1[idx] != str2[idx]) {
            dist += 1;
        } // end if
    } // end for
    
    return dist;
} // end func


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
dist_metric_hamming("abc", "aBc")
*/
