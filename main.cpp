#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** create2DArray(int row, int col) {
    T** matrix = new T * [row];
    for (size_t i = 0; i < row; i++) {
        matrix[i] = new T[col];
    }
    return matrix;
}

template<typename T>
void fill2DArray(T** matrix, int row, int col) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

template<typename T>
void print2DArray(T** matrix, int row, int col) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void delete2DArray(T** matrix, int row) {
    for (size_t i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
T** addRow(T** matrix, int& row, int col, T* newRow) {
    T** newMatrix = create2DArray<T>(row + 1, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    for (int j = 0; j < col; j++) {
        newMatrix[row][j] = newRow[j];
    }
    row++;
    delete2DArray(matrix, row - 1);

    return newMatrix;
}

int main() {
    srand(time(0));

    int row, col;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    int** matrix = create2DArray<int>(row, col);
    fill2DArray<int>(matrix, row, col);
    print2DArray<int>(matrix, row, col);

    int* newRow = new int[col];
    cout << "Enter the elements of the new row: ";
    for (int i = 0; i < col; i++) {
        cin >> newRow[i];
    }

    matrix = addRow<int>(matrix, row, col, newRow);
    print2DArray<int>(matrix, row, col);

    delete[] newRow;
    delete2DArray(matrix, row);

    return 0;
}
