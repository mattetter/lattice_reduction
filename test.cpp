# include "matrix.h"
# include "lll.h"
#include <cassert>
#include <iostream>

int main() {
    Matrix B = {{1, 1, 2},
                {2, 2, 1},
                {-1, 2, 3}};

    // nxm
    Matrix b_star(B.rows(), B.cols());
    //nxn
    Matrix mu(B.rows(), B.rows());

    gs(B, b_star, mu);

    cout<<"bstar";
    b_star.print();

    // check that columns are orthogonal
    cout<< dot(b_star[0], b_star[1])<<endl;
    cout<<dot(b_star[1], b_star[2])<<endl;
    cout<<dot(b_star[2], b_star[0])<<endl;
}