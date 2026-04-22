# include "matrix.h"
# include <stdexcept>

using namespace std;

// initialize
Matrix::Matrix(int rows, int cols)
    : data(rows, vector<double>(cols, 0.0)) {}

Matrix::Matrix(initializer_list<initializer_list<double>> rows){
    for (auto row : rows) {
        data.push_back(vector<double>(row));
    }
}


int Matrix::rows() const {
    return data.size();
}

int Matrix::cols() const {
    if (!data.empty()){
    return data[0].size();
    } else {
        return 0;
    }
}

void Matrix:: swap_rows(int i, int j) {
    // swap row i with row j
    vector<double> temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}


void Matrix::sub_scale_row(int i, int j, double scalar){
    // just iterate through row and change each element
    for (int k = 0; k < cols(); k++){
        data[i][k] -= scalar * data[j][k];
    }
}

double& Matrix:: at(int i, int j) {return data[i][j]; }

vector<double>& Matrix::operator[](int i) {
    return data[i];
}

void Matrix::print() const{
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++){
            cout<< data[i][j]<<" ";
        }
        cout<< "\n";
    }
}


