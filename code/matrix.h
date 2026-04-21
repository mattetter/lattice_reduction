#ifndef MATRIX_H__
#define MATRIX_H__

#include <vector>
#include <iostream>

using namespace std;


class Matrix {
    private:
        // a matrix is just a list of rows of doubles
        vector<vector<double>> data;

                // scale vector by scalar
        vector<double> scale_vector(const vector<double>& row, double scalar);

        // find the idfference between two vectors
        vector<double> vec_vec_subtr(const vector<double>& minuend, const vector<double>& subtrahend);

    public: 
        // Constructor
        Matrix(int rows, int cols);

        // constructor with lists for input so we can test
        Matrix(initializer_list<initializer_list<double>> rows);

        // track number of rows/columns
        int rows() const;
        int cols() const;

        // swap row operation for LLL
        void swap_rows(int i, int j);


        // reduce row i by row j * scalar
        void sub_scale_row(int i, int j, double scalar);


        // change single elements
        double& at(int i, int j);

        // print nicely for debugging
        void print() const;

        // add access for rows
        vector<double>& operator[](int i);
};

#endif