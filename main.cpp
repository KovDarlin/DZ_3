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
void delete2DArray(T** matrix, int row)
{
    for (size_t i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
T** del2DArray(T** matrix, int& row, int& col, int delPos) {
    if (delPos < 0 || delPos >= col) {
        cout << "NO! Bab number!" << endl;
        return matrix;
    }
    T** addMS = create2DArray<T>(row, col - 1);
    for (size_t i = 0; i < row; i++) {
        int addColIn = 0;
        for (size_t j = 0; j < col + 1; j++) {
            if (j != delPos) {
                addMS[i][addColIn] = matrix[i][j];
                addColIn++;
            }
        }
    }
    col--;
    delete2DArray(matrix, row);
    return addMS;
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

    int delPos;
    cout << "Enter the position for delete column (0 - " << col-1 << "): ";
    cin >> delPos;

    matrix = del2DArray<int>(matrix, row, col, delPos);
    print2DArray<int>(matrix, row, col);
    delete2DArray<int>(matrix, row);

    return 0;
}