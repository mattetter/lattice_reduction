#ifndef MATRIX_H__
#define MATRIX_H__

#include <vector>
#include <iostream>

using namespace std;


class Matrix {
    private:
        // a matrix is just a list of rows of doubles
        vector<vector<double>> data;
    public: 
        // Constructor
        Matrix(int rows, int cols);

        // track number of rows/columns
        int rows() const;
        int cols() const;

        // obtain dot product of two rows - need for LLL
        double dot(int i, int j) const;


        // swap row operation for LLL
        void swap_rows(int i, int j);

        // reduce row i by row j * scalar
        void scale_row(int i, int j, double scalar);


        // change single elements
        double& at(int i, int j);
}