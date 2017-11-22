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

    Matrix_U matrix_u2(3,3);

    matrix_u2.at(0, 0) = 8; matrix_u2.at(0, 1) = 10; matrix_u2.at(0, 2) = 12;
    matrix_u2.at(1, 0) = 1; matrix_u2.at(1, 1) = 3; matrix_u2.at(1, 2) = 5;
    matrix_u2.at(2, 0) = 2; matrix_u2.at(2, 1) = 4; matrix_u2.at(2, 2) = 6;

    cout << "Исходная вторая матрица: " << "\n" << matrix_u2;
    cout << "Строк: " << matrix_u2.getRowCount() << "; столбцов: " << matrix_u2.getColCount() << endl << endl;

    Matrix_U sumTwoMatrix(matrix_u1);
    sumTwoMatrix+=matrix_u2;
    cout << "Сумма matrix_u1 += matrix_u2: " << "\n" << sumTwoMatrix << endl;

    Matrix_U subTwoMatrix(matrix_u1);
    sumTwoMatrix-=matrix_u2;
    cout << "Разность matrix_u1 -= matrix_u2: " << "\n" << subTwoMatrix << endl;

    Matrix_U multiMatrixWithMatrix(matrix_u1);
    multiMatrixWithMatrix *= matrix_u2;
    cout << "Произведение matrix_u1 *= matrix_u2: " << "\n" << multiMatrixWithMatrix << endl;

    double number = 0.5;
    Matrix_U multiMatrixWithNumber(matrix_u1);
    multiMatrixWithNumber *= number;
    cout << "Произведение matrix_u1 *= number = 0,5: " << "\n" << multiMatrixWithNumber << endl;

    //matrix_u1.removeRowFirst();
    //cout << "Удаление первой строки из matrix_u1: " << "\n" << matrix_u1 << endl;

    cout << "Сумма matrix_u1 + matrix_u2: " << "\n" << matrix_u1 + matrix_u2 << endl;

    cout << "Разность matrix_u1 - matrix_u2: " << "\n" << matrix_u1 - matrix_u2 << endl;

    //cout << "Произведение matrix_u1 * matrix_u2: " << "\n" << matrix_u1 * matrix_u2 << endl;

    return 0;
}