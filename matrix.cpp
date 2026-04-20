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
    // swap row i with row j
    vector<double> temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

vector<double> Matrix::scale_vector(const vector<double>& row, double scalar){
    vector<double> ret;
    ret.reserve(row.size());
    for(double val: row){
        ret.push_back(val*scalar);
    }
    return ret;
}

vector<double> Matrix::vec_vec_subtr(const vector<double>& minuend, const vector<double>& subtrahend){
    vector<double> difference;
    difference.reserve(minuend.size());
    for(size_t i = 0; i < minuend.size(); i++){
        difference.push_back(minuend[i]- subtrahend[i]);
    }

    return difference;

}
void Matrix::sub_scale_row(int i, int j, double scalar){
    // get j scaled first
    vector<double> j_scaled = scale_vector(data[j], scalar);
    // reduce i
    data[i] = vec_vec_subtr(data[i], j_scaled);
}

double& Matrix:: at(int i, int j) {return data[i][j]; }

void Matrix::print() const{
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++){
            cout<< data[i][j]<<" ";
        }
        cout<< "\n";
    }
}
