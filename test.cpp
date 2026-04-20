# include "matrix.h"
#include <cassert>
#include <iostream>

int main() {
    Matrix A = {{1, 1, 2},
                {2, 2, 1},
                {-1, 2, 3}};

    cout<<"A: \n";
    A.print();

    assert(A.at(2,0) == -1);
    assert(A.at(0,0)== 1);

    A.swap_rows(0, 2);
    A.print();
}