#include "matrix_r.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    Matrix_R matrix_r1(3,3);

    matrix_r1.at(0, 0) = 0; matrix_r1.at(0, 1) = 1; matrix_r1.at(0, 2) = 3;
    matrix_r1.at(1, 0) = 4; matrix_r1.at(1, 1) = 5; matrix_r1.at(1, 2) = 6;
    matrix_r1.at(2, 0) = 7; matrix_r1.at(2, 1) = 8; matrix_r1.at(2, 2) = 9;

    cout << "Исходная первая матрица: " << "\n" << matrix_r1;
    cout << "Строк: " << matrix_r1.getRowCount() << "; столбцов: " << matrix_r1.getColCount() << endl << endl;

    Matrix_R matrix_r2(3,3);

    matrix_r2.at(0, 0) = 8; matrix_r2.at(0, 1) = 10; matrix_r2.at(0, 2) = 12;
    matrix_r2.at(1, 0) = 1; matrix_r2.at(1, 1) = 3; matrix_r2.at(1, 2) = 5;
    matrix_r2.at(2, 0) = 2; matrix_r2.at(2, 1) = 4; matrix_r2.at(2, 2) = 6;

    cout << "Исходная вторая матрица: " << "\n" << matrix_r2;
    cout << "Строк: " << matrix_r2.getRowCount() << "; столбцов: " << matrix_r2.getColCount() << endl << endl;

    Matrix_R sumTwoMatrix(matrix_r1);
    sumTwoMatrix+=matrix_r2;
    cout << "Сумма matrix_r1 += matrix_r2: " << "\n" << sumTwoMatrix << endl;

    Matrix_R subTwoMatrix(matrix_r1);
    sumTwoMatrix-=matrix_r2;
    cout << "Разность matrix_r1 -= matrix_r2: " << "\n" << subTwoMatrix << endl;

    Matrix_R multiMatrixWithMatrix(matrix_r1);
    multiMatrixWithMatrix *= matrix_r2;
    cout << "Произведение matrix_r1 *= matrix_r2: " << "\n" << multiMatrixWithMatrix << endl;

    double number = 0.5;
    Matrix_R multiMatrixWithNumber(matrix_r1);
    multiMatrixWithNumber *= number;
    cout << "Произведение matrix_r1 *= number = 0,5: " << "\n" << multiMatrixWithNumber << endl;

    //matrix_r1.removeRowFirst();
    //cout << "Удаление первой строки из matrix_r1: " << "\n" << matrix_r1 << endl;

    cout << "Сумма matrix_r1 + matrix_r2: " << "\n" << matrix_r1 + matrix_r2 << endl;

    cout << "Разность matrix_r1 - matrix_r2: " << "\n" << matrix_r1 - matrix_r2 << endl;

    cout << "Произведение matrix_r1 * matrix_r2: " << "\n" << matrix_r1 * matrix_r2 << endl;

    return 0;
}

