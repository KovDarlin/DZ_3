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
void moveCol(T** matrix, int col, int row, int moving, bool way) {
    for (int s = 0; s < moving; s++) {
        if (way) {
            for (int i = 0; i < col; i++) {
                T temp = matrix[i][row - 1];
                for (int j = row - 1; j > 0; j--) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = temp;
            }
        }
        else {
            for (int i = 0; i < col; i++) {
                T temp = matrix[i][0];
                for (int j = 0; j < row - 1; j++) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][row - 1] = temp;
            }
        }
    }
}

template<typename T>
void moveRow(T** matrix, int col, int row, int moving, bool way) {
    for (int s = 0; s < moving; s++) {
        if (way) { 
            T* temp = matrix[col - 1];
            for (int i = col - 1; i > 0; i--) {
                matrix[i] = matrix[i - 1];
            }
            matrix[0] = temp;
        }
        else {  
            T* temp = matrix[0];
            for (int i = 0; i < col - 1; i++) {
                matrix[i] = matrix[i + 1];
            }
            matrix[col - 1] = temp;
        }
    }
}


template<typename T>
void delete2DArray(T** matrix, int col) {
    for (size_t i = 0; i < col; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    srand(time(0));
    int col, row, moving;
    char res;
    bool way;

    cout << "Enter the number of rows: ";
    cin >> col;
    cout << "Enter the number of columns: ";
    cin >> row;

    int** matrix = create2DArray<int>(col, row);
    fill2DArray<int>(matrix, col, row);
    print2DArray<int>(matrix, col, row);

    cout << "Do you want move rows or columns? (r or c): ";
    cin >> res;
    cout << "Enter the number of move: ";
    cin >> moving;
    cout << "Enter 1 for down or right, 0 for up or left: ";
    cin >> way;

    if (res == 'r') {
        moveRow<int>(matrix, col, row, moving, way);
    }
    else if (res == 'c') {
        moveCol<int>(matrix, col, row, moving, way);
    }
    else {
        cout << "NO! Bab letter" << endl;

    }

    cout << "Your new matrix: " << endl;
    print2DArray<int>(matrix, col, row);

    delete2DArray<int>(matrix, col);
    return 0;
}