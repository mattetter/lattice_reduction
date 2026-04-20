#include "lll.h"
#include <cmath>


double dot(const vector<double>& u, const vector<double>& v){
    double ret = 0.0;
    for (size_t k = 0; k < u.size(); k++){
        ret += v[k] * u[k];
    }

    return ret;
}

void gs(Matrix& B, Matrix& b_star, Matrix& mu){
    // first vector in GS is already orthogonal so we'll set that up first
    b_star[0] = B[0];
    // loop through rows in B and generate the orthogonal vectors and coefficients
    for (int i = 1; i < B.rows(); i++){
        // start with B_i
        b_star[i] = B[i];
        // loop through all earlier indexes
        for (int j = 0; j < i; j++){
            //calculate the coefficient Bi@b*j/ norm squared of b*j
            mu.at(i, j) = dot(B[i], b_star[j]) / dot(b_star[j], b_star[j]);
            //subtract the shadow of b*j from b*i using the matrix function created for this
            b_star.sub_scale_row(i, j, mu.at(i,j) );
        }
    }
}


void lll(Matrix& B){
    //double delta = 0.75;
}