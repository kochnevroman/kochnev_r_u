#pragma once
#ifndef MATRIX_U_MATRIX_U_H
#define MATRIX_U_MATRIX_U_H

#include <cstddef>
#include <iosfwd>

class Matrix_U
{
    Matrix_U() = default;
    Matrix_U(const int nRol, const int nCol);
    Matrix_U(const Matrix_U& matrix_u);

    ~Matrix_U();

    double& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const double& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;

    //операции матриц с матрицей
    Matrix_U operator=(const Matrix_U& matrix_u);
    Matrix_U operator+=(const Matrix_U& matrix_u);
    Matrix_U operator-=(const Matrix_U& matrix_u);
    Matrix_U operator*=(const Matrix_U& matrix_u);

    //операции матрицы с вектором
    //

    //операции матрицы с числом
    Matrix_U operator+=(const double& number);
    Matrix_U operator-=(const double& number);
    Matrix_U operator*=(const double& number);

    std::ostream& writeTo(std::ostream& ostrm ) const;

private:
    ptrdiff_t nRow_ { 0 };
    ptrdiff_t nCol_ { 0 };
    int** pRows {nullptr};

    void determinant();
    void transpose();
    void resize(const ptrdiff_t& newNumberOfLines, const ptrdiff_t& newNumberOfColumns);

};

//операции матрицы с матрицей
Matrix_U operator+(const Matrix_U& matrix1, const Matrix_U& matrix2);
Matrix_U operator-(const Matrix_U& matrix1, const Matrix_U& matrix2);
Matrix_U operator*(const Matrix_U& matrix1, const Matrix_U& matrix2);

//операции матрицы с вектором
//

//операции матрицы с числом
Matrix_U operator+(const Matrix_U& matrix1, const double& number);
Matrix_U operator+(const double& number, const Matrix_U& matrix2);

Matrix_U operator-(const Matrix_U& matrix1, const double& number);
Matrix_U operator-(const double& number, const Matrix_U& matrix2);

Matrix_U operator*(const Matrix_U& matrix1, const double& number);
Matrix_U operator*(const double& number, const Matrix_U& matrix2);


inline std::ostream& operator<<(std::ostream& ostrm, const Matrix_U& matrix_u)
{
    return  matrix_u.writeTo(ostrm);
}

#endif //MATRIX_U_MATRIX_U_H
