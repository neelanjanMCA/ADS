#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[10][10], rows, cols;
public:
    void getMatrix() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix m) {
        Matrix result;
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix addition not possible (dimensions must be the same).\n";
            return result;
        }
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix m) {
        Matrix result;
        if (cols != m.rows) {
            cout << "Matrix multiplication not possible (columns of A must match rows of B).\n";
            return result;
        }
        result.rows = rows;
        result.cols = m.cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix A, B, sum, product;

    cout << "Enter Matrix A:\n";
    A.getMatrix();

    cout << "Enter Matrix B:\n";
    B.getMatrix();

    cout << "\nMatrix A:\n";
    A.displayMatrix();

    cout << "\nMatrix B:\n";
    B.displayMatrix();

    // Matrix Addition
    sum = A.add(B);
    cout << "\nMatrix Addition (A + B):\n";
    sum.displayMatrix();

    // Matrix Multiplication
    product = A.multiply(B);
    cout << "\nMatrix Multiplication (A * B):\n";
    product.displayMatrix();

    return 0;
}
