#ifndef LLL_H__
#define LLL_H__

#include "matrix.h"

// obtain dot product of two rows 
double dot(const vector<double>& u, const vector<double>& v);

// Runs the Gram-Schmidt algorithm without the normalization step
// output of orthoganal row-vectors is stored in b_star and the coefficients in mu
void gs(Matrix& B, Matrix& b_star, Matrix& mu);

// the LLL_reduction step. replaces B with an LLL-reduced basis.
void lll(Matrix& B);









#endif