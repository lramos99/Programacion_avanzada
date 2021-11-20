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

// [[Rcpp::export]]
double my_knn_C(NumericMatrix X, NumericVector X0, NumericVector y){
  int nrows = X.nrow();
  int ncols = X.ncol();
  int closest_distance = 99999999;
  int closest_output = -1;
  int closest_neighbor = -1;
  int i;
  int j;
  for(i=0; i<nrows; i++){
    double distance = 0;
    for(j=0; j<ncols; j++){
      double difference = X(i,j)-X0[j];
      distance = distance + difference * difference;
    }
      distance = sqrt(distance);
      
      if(distance < closest_distance){
        closest_distance = distance;
        closest_output = y[i];
        closest_neighbor = i;
      }
    }
  return(closest_output);
}