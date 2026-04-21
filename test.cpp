# include "matrix.h"
# include "lll.h"
#include <cassert>
#include <iostream>

int main() {
    Matrix B = {{1, 1, 2, 7, 9, -3},
                {2, 2, 1, 4, 3, -9},
                {-1, 2, 3, 1, -1, 8},
                {5, 6, 7, 8, 9 , 3},
                {1, 1, 1, 1, 1, 1},
                {9, 0, 9, 9, 9, 0}};

    // nxm
    Matrix b_star(B.rows(), B.cols());
    //nxn
    Matrix mu(B.rows(), B.rows());

    // gs(B, b_star, mu);

    // cout<<"bstar \n";
    // b_star.print();

    // // check that columns are orthogonal
    // cout<< dot(b_star[0], b_star[1])<<endl;
    // cout<<dot(b_star[1], b_star[2])<<endl;
    // cout<<dot(b_star[2], b_star[0])<<endl;

    // mu.print();

    cout<<"Before"<<endl;
    B.print();

    lll(B);

    cout<<"after"<<endl;
    B.print();

    // re-run GS to see if vals of mu are <= .5 and that ||b_star_i||^2 drops smoothly

    gs(B, b_star, mu);

    mu.print();


    for(int i = 0; i < b_star.rows(); i++){
        cout<<"||b_star_i||^2: "<< dot(b_star[i], b_star[i])<<endl; 
    }

}