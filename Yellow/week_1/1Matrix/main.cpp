//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() = default;
    Matrix(size_t numRows, size_t numCols);
    void Reset(size_t numRows, size_t numCols);

    int At(int row, int col) const;
    int &At(int row, int col);
    size_t GetNumRows() const;
    size_t GetNumColumns() const;
private:
    vector<vector<int>> m_data;
};

Matrix::Matrix(size_t numRows, size_t numCols) {

    if (numCols < 0 || numRows < 0) {
        throw out_of_range("Matrix args num of rows " + to_string(numRows) + " or cols "
                             + to_string(numRows) + "less then 0");
    }
//    m_data.resize(numRows);
    m_data.assign(numRows, vector<int>(numCols));
}

void Matrix::Reset(size_t numRows, size_t numCols) {
    if (numCols < 0 || numRows < 0) {
        throw out_of_range("Matrix args num of rows " + to_string(numRows) + " or cols "
                           + to_string(numRows) + "less then 0");
    }
//    m_data.resize(numRows);
    m_data.assign(numRows, vector<int>(numCols));
}

int Matrix::At(int row, int col) const {
    return m_data.at(row).at(col);
}

int &Matrix::At(int row, int col) {
    return m_data.at(row).at(col);
}

size_t Matrix::GetNumRows() const {
    return m_data.size();
}

size_t Matrix::GetNumColumns() const {
    if (m_data.size() > 0) {
        return m_data[0].size();
    } else {
        return 0;
    }
}

istream &operator>>(istream &is, Matrix &mat) {
    int numRows, numCols = 0;
    cin >> numRows >> numCols;
    mat.Reset(numRows, numCols);

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            cin >> mat.At(i, j);
        }
    }
    return is;
}



ostream &operator<<(ostream &os, const Matrix &mat) {
    cout << mat.GetNumRows() << " " << mat.GetNumColumns() << "\n";
    for(int i = 0; i < mat.GetNumRows(); i++) {
        for(int j = 0; j < mat.GetNumColumns(); j++) {
            if (j > 0) {
                out << " ";
            }
            cout << mat.At(i, j);
        }
        cout << '\n';
    }
    return os;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.GetNumColumns() == rhs.GetNumColumns() && lhs.GetNumRows() == rhs.GetNumRows()) {
        for(int i = 0; i < lhs.GetNumRows(); i++) {
            for(int j = 0; j < lhs.GetNumColumns(); j++) {
                if (lhs.At(i, j) != rhs.At(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.GetNumColumns() != rhs.GetNumColumns() && lhs.GetNumRows() != rhs.GetNumRows()) {
        throw invalid_argument("matrix op + has different size matrix");
    }
    Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());
    for(int i = 0; i < lhs.GetNumRows(); i++) {
        for(int j = 0; j < lhs.GetNumColumns(); j++) {
            res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return res;
}


int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}