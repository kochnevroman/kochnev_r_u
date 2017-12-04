#pragma once
#ifndef MATRIX_U_MATRIX_U_H
#define MATRIX_U_MATRIX_U_H

#include <cstddef>
#include <iosfwd>

class Matrix_U
{
public:
    Matrix_U() = default;
    Matrix_U(const ptrdiff_t& nRow, const ptrdiff_t& nCol);
    Matrix_U(const Matrix_U& matrix_u);

    ~Matrix_U();

    double& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const double& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;

    // Операции матрицы с матрицей.
    Matrix_U& operator=(const Matrix_U& matrix_u);
    Matrix_U& operator+=(const Matrix_U& matrix_u);
    Matrix_U& operator-=(const Matrix_U& matrix_u);
    Matrix_U& operator*=(const Matrix_U& matrix_u);

    // Операции матрицы с числом.
    Matrix_U& operator*=(const double number);

    ptrdiff_t getRowCount() const;
    ptrdiff_t getColCount() const;

    std::ostream& writeTo(std::ostream& ostrm ) const;

private:
    ptrdiff_t nRow_ { 0 };
    ptrdiff_t nCol_ { 0 };
    double*   pData_{nullptr};
};

// Операции матрицы с матрицей.
Matrix_U operator+(const Matrix_U& matrix1, const Matrix_U& matrix2);
Matrix_U operator-(const Matrix_U& matrix1, const Matrix_U& matrix2);
Matrix_U operator*(const Matrix_U& matrix1, const Matrix_U& matrix2);

// Операции матрицы с числом.
Matrix_U operator*(const Matrix_U& matrix_u, const double number);
Matrix_U operator*(const double number, const Matrix_U& matrix_u);

std::ostream& operator<<(std::ostream& ostrm, const Matrix_U& matrix_u);

#endif //MATRIX_U_MATRIX_U_H
