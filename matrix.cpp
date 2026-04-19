# include "matrix.h"
# include <stdexcept>

using namespace std;

// initialize
Matrix::Matrix(int rows, int cols)
    : data(rows, vector<double>(cols, 0.0)) {}


int Matrix::rows() const {
    return data.size();
}

int Matrix::cols() const {
    if (!data.empty()){
    return data[0].size();
    } else {
        return -1;
    }
}

double Matrix::dot(int i, int j) const {
    double ret = 0.0;
    for (int k = 0; k < cols(); k++){
        ret += data[i][k] * data[j][k];
    }

    return ret;
}

void Matrix:: swap_rows(int i, int j) {
    //TODO
}

void Matrix::scale_row(int i, int j, double scalar){
    //TODO
}

double& Matrix:: at(int i, int j) {return data[i][j]; }