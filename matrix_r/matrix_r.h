#pragma once
#ifndef MATRIX_R_MATRIX_R_H
#define MATRIX_R_MATRIX_R_H

#include <cstddef>
#include <iosfwd>

class Matrix_R
{
public:
    Matrix_R() = default;
    Matrix_R(const ptrdiff_t& nRow, const ptrdiff_t& nCol);
    Matrix_R(const Matrix_R& matrix_r);

    ~Matrix_R();

    double& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const double& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;

    // Операции матрицы с матрицей.
    Matrix_R& operator=(const Matrix_R& matrix_r);
    Matrix_R& operator+=(const Matrix_R& matrix_r);
    Matrix_R& operator-=(const Matrix_R& matrix_r);
    Matrix_R& operator*=(const Matrix_R& matrix_r);

    // Операции матрицы с числом.
    Matrix_R& operator*=(const double number);

    ptrdiff_t getRowCount() const;
    ptrdiff_t getColCount() const;

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    ptrdiff_t  nRow_ { 0 };
    ptrdiff_t  nCol_ { 0 };
    double** pData_  { nullptr };
};

// Операции матрицы с матрицей.
Matrix_R operator+(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix);
Matrix_R operator-(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix);
Matrix_R operator*(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix);

// Операции матрицы с числом.
Matrix_R operator*(const Matrix_R& matrix_r, const double number);
Matrix_R operator*(const double number, const Matrix_R& matrix_r);

std::ostream& operator<<(std::ostream& ostrm, const Matrix_R& matrix_r);

#endif //MATRIX_R_MATRIX_R_H