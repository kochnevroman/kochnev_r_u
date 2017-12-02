#include "matrix_u.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix_U matrix_u1(3, 3);

    matrix_u1.at(0, 0) = 0; matrix_u1.at(0, 1) = 1; matrix_u1.at(0, 2) = 3;
    matrix_u1.at(1, 0) = 4; matrix_u1.at(1, 1) = 5; matrix_u1.at(1, 2) = 6;
    matrix_u1.at(2, 0) = 7; matrix_u1.at(2, 1) = 8; matrix_u1.at(2, 2) = 9;

    cout << "Исходная первая матрица: " << "\n" << matrix_u1;
    cout << "Строк: " << matrix_u1.getRowCount() << "; столбцов: " << matrix_u1.getColCount() << endl << endl;

    cout << "Попытка задания матрице параметров строки -5, столбца 28: " << endl;
    cout << "Matrix_U testMatrix_u(-5, 28): " << endl;
    try {
        Matrix_U testMatrix_u(-5, 28);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_U matrix_u2(3, 3);

    matrix_u2.at(0, 0) = 8; matrix_u2.at(0, 1) = 10; matrix_u2.at(0, 2) = 12;
    matrix_u2.at(1, 0) = 1; matrix_u2.at(1, 1) = 3; matrix_u2.at(1, 2) = 5;
    matrix_u2.at(2, 0) = 2; matrix_u2.at(2, 1) = 4; matrix_u2.at(2, 2) = 6;

    cout << "Исходная вторая матрица: " << "\n" << matrix_u2;
    cout << "Строк: " << matrix_u2.getRowCount() << "; столбцов: " << matrix_u2.getColCount() << endl << endl;

    cout << "Попытка доступа к элементу (-256, 512) матрицы: " << endl;
    cout << "matrix_u2.at(-256, 512): " << endl;
    try {
        matrix_u2.at(-256, 512);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    const Matrix_U constMatrix_u(matrix_u2);

    cout << "Попытка доступа к элементу (10, -127) константной матрицы: " << endl;
    cout << "constMatrix_r.at(10, -127): " << endl;
    try {
        constMatrix_u.at(10, -127);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_U matrix_u3(2, 1);
    matrix_u3.at(0, 0) = 5;
    matrix_u3.at(1, 0) = 39;

    cout << "Исходная третья матрица: " << "\n" << matrix_u3;
    cout << "Строк: " << matrix_u3.getRowCount() << "; столбцов: " << matrix_u3.getColCount() << endl << endl;

    Matrix_U sumTwoMatrix(matrix_u1);
    sumTwoMatrix += matrix_u2;
    cout << "Сумма matrix_u1 += matrix_u2: " << "\n" << sumTwoMatrix << endl;

    cout << "Попытка суммы матрицы размером 3х3 и матрицы 2х1: " << endl;
    cout << "matrix_u2 += matrix_u3: " << endl;
    try {
        Matrix_U sumTwoMatrix(matrix_u2);
        sumTwoMatrix += matrix_u3;
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_U subTwoMatrix(matrix_u1);
    sumTwoMatrix -= matrix_u2;
    cout << "Разность matrix_u1 -= matrix_u2: " << "\n" << subTwoMatrix << endl;

    cout << "Попытка разности матрицы размером 3х3 и матрицы 2х1: " << endl;
    cout << "cmatrix_u2 -= matrix_u3: " << endl;
    try {
        Matrix_U sumTwoMatrix(matrix_u2);
        sumTwoMatrix -= matrix_u3;
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    Matrix_U multiMatrixWithMatrix(matrix_u1);
    multiMatrixWithMatrix *= matrix_u2;
    cout << "Произведение matrix_u1 *= matrix_u2: " << "\n" << multiMatrixWithMatrix << endl;

    cout << "Попытка произведения матрицы размером 3х3 и матрицы 2х1: " << endl;
    cout << "matrix_u2 *= matrix_u3: " << endl;
    try {
        Matrix_U sumTwoMatrix(matrix_u2);
        sumTwoMatrix *= matrix_u3;
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    double number = 0.5;
    Matrix_U multiMatrixWithNumber(matrix_u1);
    multiMatrixWithNumber *= number;
    cout << "Произведение matrix_u1 *= number = 0,5: " << "\n" << multiMatrixWithNumber << endl;

    cout << "Сумма matrix_u1 + matrix_u2: " << "\n" << matrix_u1 + matrix_u2 << endl;

    cout << "Разность matrix_u1 - matrix_u2: " << "\n" << matrix_u1 - matrix_u2;

    //cout << "Произведение matrix_u1 * matrix_u2: " << "\n" << matrix_u1 * matrix_u2 << endl;

    return 0;
}