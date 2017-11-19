#pragma once
#ifndef MATRIX_R_MATRIX_R_H
#define MATRIX_R_MATRIX_R_H

#include <cstddef>
#include <iosfwd>

class Matrix_R
{
public:
    explicit Matrix_R() = default;
    Matrix_R(const double nRow, const double nCol);
    Matrix_R(const Matrix_R& matrix_r);
    ~Matrix_R();

    double& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const double& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;

    //операции матрицы с матрицей
    Matrix_R operator=(const Matrix_R& matrix_r);
    Matrix_R operator+=(const Matrix_R& matrix_r);
    Matrix_R operator-=(const Matrix_R& matrix_r);
    Matrix_R operator*=(const Matrix_R& matrix_r);

    //операции матрицы с вектором
    //

    //операции матрицы с числом
    Matrix_R operator+=(const double& number);
    Matrix_R operator-=(const double& number);
    Matrix_R operator*=(const double& number);

    const ptrdiff_t getnRow() const;
    const ptrdiff_t getnCol() const;

    std::ostream& writeTo(std::ostream& ostrm ) const;

private:
    ptrdiff_t  nRow_ { 0 };
    ptrdiff_t  nCol_ { 0 };
    int** pRows_ ( nullptr );

    void determinant();
    void transpose();
    void resize(const ptrdiff_t& newNumberOfLines, const ptrdiff_t& newNumberOfColumns);
};

//операции матрицы с матрицей
Matrix_R operator+(const Matrix_R& matrix1, const Matrix_R& matrix2);
Matrix_R operator-(const Matrix_R& matrix1, const Matrix_R& matrix2);
Matrix_R operator*(const Matrix_R& matrix1, const Matrix_R& matrix2);

//операции матрицы с вектором
//

//операции матрицы с числом
Matrix_R operator+(const Matrix_R& matrix1, const double& number);
Matrix_R operator+(const double& number, const Matrix_R& matrix2);

Matrix_R operator-(const Matrix_R& matrix1, const double& number);
Matrix_R operator-(const double& number, const Matrix_R& matrix2);

Matrix_R operator*(const Matrix_R& matrix1, const double& number);
Matrix_R operator*(const double& number, const Matrix_R& matrix2);


inline std::ostream& operator<<(std::ostream& ostrm, const Matrix_R& matrix_r)
{
    return matrix_r.writeTo(ostrm);
}

#endif //MATRIX_R_MATRIX_R_H