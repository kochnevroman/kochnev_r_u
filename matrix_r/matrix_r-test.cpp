#include "matrix_r.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    Matrix_R matrix_r1(3, 3);

    matrix_r1.at(0, 0) = 0; matrix_r1.at(0, 1) = 1; matrix_r1.at(0, 2) = 3;
    matrix_r1.at(1, 0) = 4; matrix_r1.at(1, 1) = 5; matrix_r1.at(1, 2) = 6;
    matrix_r1.at(2, 0) = 7; matrix_r1.at(2, 1) = 8; matrix_r1.at(2, 2) = 9;

    cout << "Исходная первая матрица: " << "\n" << matrix_r1;
    cout << "Строк: " << matrix_r1.getRowCount() << "; столбцов: " << matrix_r1.getColCount() << endl << endl;

    cout << "Попытка задания матрице параметров строки -3, столбца 5: " << endl;
    cout << "Matrix_R testMatrix_r(-3, 5): " << endl;
    try {
        Matrix_R testMatrix_r(-3, 5);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_R matrix_r2(3, 3);

    matrix_r2.at(0, 0) = 8; matrix_r2.at(0, 1) = 10; matrix_r2.at(0, 2) = 12;
    matrix_r2.at(1, 0) = 1; matrix_r2.at(1, 1) = 3; matrix_r2.at(1, 2) = 5;
    matrix_r2.at(2, 0) = 2; matrix_r2.at(2, 1) = 4; matrix_r2.at(2, 2) = 6;

    cout << "Исходная вторая матрица: " << "\n" << matrix_r2;
    cout << "Строк: " << matrix_r2.getRowCount() << "; столбцов: " << matrix_r2.getColCount() << endl << endl;

    cout << "Попытка доступа к элементу (-100, 100) матрицы: " << endl;
    cout << "matrix_r2.at(-100, 100): " << endl;
    try {
        matrix_r2.at(-100, 100);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    const Matrix_R constMatrix_r(matrix_r2);

    cout << "Попытка доступа к элементу (1, 64) константной матрицы: " << endl;
    cout << "constMatrix_r.at(1, 64): " << endl;
    try {
        constMatrix_r.at(1, 64);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_R sumTwoMatrix(matrix_r1);
    sumTwoMatrix += matrix_r2;
    cout << "Сумма matrix_r1 += matrix_r2: " << "\n" << sumTwoMatrix << endl;

    Matrix_R matrix_r3(2, 1);
    matrix_r3.at(0, 0) = 8;
    matrix_r3.at(1, 0) = 1;

    cout << "Исходная третья матрица: " << "\n" << matrix_r3;
    cout << "Строк: " << matrix_r3.getRowCount() << "; столбцов: " << matrix_r3.getColCount() << endl << endl;

    cout << "Попытка суммы матрицы размером 3х3 и матрицы 2х1: " << endl;
    cout << "matrix_r2 += matrix_r3: " << endl;
    try {
        Matrix_R sumTwoMatrix(matrix_r2);
        sumTwoMatrix += matrix_r3;
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_R subTwoMatrix(matrix_r1);
    sumTwoMatrix -= matrix_r2;
    cout << "Разность matrix_r1 -= matrix_r2: " << "\n" << subTwoMatrix << endl;

    cout << "Попытка разности матрицы размером 3х3 и матрицы 2х1: " << endl;
    cout << "cmatrix_r2 -= matrix_r3: " << endl;
    try {
        Matrix_R sumTwoMatrix(matrix_r2);
        sumTwoMatrix -= matrix_r3;
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_R multiMatrixWithMatrix(matrix_r1);
    multiMatrixWithMatrix *= matrix_r2;
    cout << "Произведение matrix_r1 *= matrix_r2: " << "\n" << multiMatrixWithMatrix << endl;

    cout << "Попытка произведения матрицы размером 3х3 и матрицы 2х1: " << endl;
    cout << "matrix_r2 *= matrix_r3: " << endl;
    try {
        Matrix_R sumTwoMatrix(matrix_r2);
        sumTwoMatrix *= matrix_r3;
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    double number = 0.5;
    Matrix_R multiMatrixWithNumber(matrix_r1);
    multiMatrixWithNumber *= number;
    cout << "Произведение matrix_r1 *= number = 0,5: " << "\n" << multiMatrixWithNumber << endl;

    cout << "Сумма matrix_r1 + matrix_r2: " << "\n" << matrix_r1 + matrix_r2 << endl;

    cout << "Разность matrix_r1 - matrix_r2: " << "\n" << matrix_r1 - matrix_r2 << endl;

    cout << "Произведение matrix_r1 * matrix_r2: " << "\n" << matrix_r1 * matrix_r2;

    return 0;
}

