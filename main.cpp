#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** create2DArray(int col, int row) {
    T** matrix = new T * [col];
    for (size_t i = 0; i < col; i++) {
        matrix[i] = new T[row];
    }
    return matrix;
}

template<typename T>
void fill2DArray(T** matrix, int col, int row) {
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

template<typename T>
void print2DArray(T** matrix, int col, int row) {
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void delete2DArray(T** matrix, int col) {
    for (size_t i = 0; i < col; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
T** del2DArray(T** matrix, int& col, int row, int delPos) {
    if (delPos < 0 || delPos >= col) {
        cout << "Invalid row position!" << endl;
        return matrix;
    }

    T** newMatrix = create2DArray<T>(col - 1, row);
    for (int i = 0, newRow = 0; i < col; i++) {
        if (i != delPos) { 
            for (int j = 0; j < row; j++) {
                newMatrix[newRow][j] = matrix[i][j];
            }
            newRow++;
        }
    }

    col--; 
    delete2DArray(matrix, col + 1); 

    return newMatrix;
}

int main() {
    srand(time(0));

    int col, row;

    cout << "Enter the number of rows: ";
    cin >> col;
    cout << "Enter the number of columns: ";
    cin >> row;

    int** matrix = create2DArray<int>(col, row);
    fill2DArray<int>(matrix, col, row);
    print2DArray<int>(matrix, col, row);

    int delPos;
    cout << "Enter the position for delete row (0 - " << col - 1 << "): ";
    cin >> delPos;

    matrix = del2DArray<int>(matrix, col, row, delPos);
    print2DArray<int>(matrix, col, row); 

    delete2DArray<int>(matrix, col); 

    return 0;
}
