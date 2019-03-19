#include "BarcodeMatcher.h"
#include <Rcpp.h>
using namespace Rcpp;

int hamming(const std::string& str1, 
            const std::string& str2) {
    // init
    //int dist = 1;
    
    //*
    int dist = 0;
    int len1 = str1.length();
    int len2 = str2.length();
    
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
    //*/
    return dist;
} // end func



//' @export
// [[Rcpp::export]]
NumericVector cdist_str(
        const StringVector& vec_str1,
        const StringVector& vec_str2
) {
    // init
    int len1 = vec_str1.length();
    int len2 = vec_str2.length();
    NumericMatrix mat_dist(len1, len2);
    
    //for (int idx1 = 0; idx1 < len1; idx1 += 1){
    //    std::cout << vec_str1[idx1] << std::endl;
    //}
    
    //*
    // pairwise distance
    for (int idx1 = 0; idx1 < len1; idx1 += 1){
        //std::cout << std::string(vec_str1[idx1]) << std::endl;
        for (int idx2 = 0; idx2 < len2; idx2 += 1){
            //mat_dist(idx1, idx2) = hamming(
            //    std::string(vec_str1[idx1]), 
            //    std::string(vec_str2[idx2]));
            mat_dist(idx1, idx2) = dist_metric_hamming(
                std::string(vec_str1[idx1]), 
                std::string(vec_str2[idx2]));
        } // end inner loop
    } // end outer loop
    //*/
    
    return mat_dist;
}



// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
cdist_str(c("ab", "ac"), c("bb", "bc", "bd"))
*/
