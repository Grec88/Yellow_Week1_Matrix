//============================================================================
// Name        : Yellow_Week1_Matrix.cpp
// Author      : grec88
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <exception>
#include <sstream>
using namespace std;

class Matrix {
private:
  int num_rows_;
  int num_columns_;

  vector<vector<int>> mat;

public:
  friend bool operator==(const Matrix &mat1, const Matrix mat2);

  Matrix() {
    num_rows_ = 0;
    num_columns_ = 0;
  }

  Matrix(int num_rows, int num_columns) {
    Reset(num_rows, num_columns);
  }

  void Reset(int num_rows, int num_columns) {
    if (num_rows < 0) {
      throw out_of_range("num_rows must be >= 0");
    }
    if (num_columns < 0) {
      throw out_of_range("num_columns must be >= 0");
    }
    if (num_rows == 0 || num_columns == 0) {
      num_rows = num_columns = 0;
    }

    num_rows_ = num_rows;
    num_columns_ = num_columns;
    mat.assign(num_rows, vector<int>(num_columns));
  }

  int& At(int row, int column) {
    return mat.at(row).at(column);
  }

  int At(int row, int column) const {
    return mat.at(row).at(column);
  }

  int GetNumRows() const {
    return num_rows_;
  }

  int GetNumColumns() const {
    return num_columns_;
  }
};

istream& operator>>(istream &stream, Matrix &mas) {
	int a, b;
	stream >> a >> b;
	mas.Reset(a, b);
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				stream >> mas.At(i, j);
			}
		}
	return stream;
}

ostream& operator<<(ostream &stream, const Matrix &mas) {
	stream << mas.GetNumRows() << " " << mas.GetNumColumns() << "\n";
		for (int i = 0; i < mas.GetNumRows(); ++i) {
			for (int j = 0; j < mas.GetNumColumns(); ++j) {
				if (j == mas.GetNumColumns() - 1 && i < mas.GetNumRows() - 1) {
					stream << mas.At(i, j) << "\n";
				}
				if (j == mas.GetNumColumns() - 1 && i == mas.GetNumRows() - 1) {
					stream << mas.At(i, j);
				} else if (j < mas.GetNumColumns() - 1
						&& i <= mas.GetNumRows() - 1) {
					stream << mas.At(i, j) << " ";
				}
			}
		}
	return stream;
}

bool operator==(const Matrix &mat1, const Matrix mat2) {
	if (mat1.GetNumRows() == mat2.GetNumRows()
			&& mat1.GetNumColumns() == mat2.GetNumColumns()) {
		for (int i = 0; i < mat1.GetNumRows(); ++i) {
			if (mat1.mat[i] != mat2.mat[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

Matrix operator+(const Matrix &mat1, const Matrix &mat2) {
	if (mat1.GetNumRows() != mat2.GetNumRows()
			|| mat1.GetNumColumns() != mat2.GetNumColumns()) {
		throw invalid_argument("b");
	}
		Matrix mat(mat1.GetNumRows(), mat1.GetNumColumns());
		for (int i = 0; i < mat1.GetNumRows(); ++i) {
			for (int j = 0; j < mat1.GetNumColumns(); ++j) {
				mat.At(i, j) = mat1.At(i, j) + mat2.At(i, j);
			}
		}
	return mat;
}

int main() {
	Matrix one;
	Matrix two;
	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
