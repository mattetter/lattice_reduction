# include "matrix.h"
#include <cassert>
#include <iostream>

int main() {
    Matrix A = {{1, 1, 3},
                {-1, 2, 2},
                {2, 3, 1}};

    cout<<"A: \n";
    A.print();
}