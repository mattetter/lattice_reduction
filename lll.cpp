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

// follows https://arxiv.org/pdf/2410.22196 closely
void lll(Matrix& B){

    double delta = 0.75;
    // gram-schmidt orthogonalization of current basis
    Matrix b_star(B.rows(), B.cols());
    Matrix mu(B.rows(), B.rows());
    gs(B, b_star, mu); 
    // Nothing to do on index 0, start at 1
    int i = 1;
    // a while loop because we need to rewind occasionally
    while (i < B.rows()){
        // reduction step
        for (int j = i-1; j>= 0; j--){
            // adjust the ith vector in basis sso that bi = bi − ⌊µ_{i,j} ⌉bj
            double rounded_muij = round(mu.at(i,j));
            B.sub_scale_row(i, j, rounded_muij);
            // recompute mu
            gs(B, b_star, mu);

        }
        // swapping step: if Lovasz condition ((δ − µ^2_{i,i-1})||b*_{i-1}||^2 <=||b*_i||^2) not met, swap b_{i−1} and b_i
        double lovasz = (delta - mu.at(i, i-1)*mu.at(i, i-1)) *(dot(b_star[i-1],b_star[i-1]));
        if (lovasz > dot(b_star[i], b_star[i])){
            B.swap_rows(i, i-1);
            // rewind if we swapped
            if (i > 1){
                i--;
            }
        }
        else {
            // move on if condition met
            i++;
        }

    }

}