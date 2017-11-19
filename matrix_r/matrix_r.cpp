#include "matrix_r.h"
#include <iostream>

Matrix_R::Matrix_R(const double nRow, const double nCow)
{
}

Matrix_R::Matrix_R(const Matrix_R &matrix_r)
{

}

Matrix_R::~Matrix_R()
{

}

double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) {

}

const double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const {

}

//операции матрицы с матрицей
Matrix_R Matrix_R::operator=(const Matrix_R &matrix_r) {

}

Matrix_R Matrix_R::operator+=(const Matrix_R &matrix_r) {

}

Matrix_R Matrix_R::operator-=(const Matrix_R &matrix_r) {

}

Matrix_R Matrix_R::operator*=(const Matrix_R &matrix_r) {

}

//операции матрицы с числом
Matrix_R Matrix_R::operator+=(const double &number) {

}

Matrix_R Matrix_R::operator-=(const double &number) {

}

Matrix_R Matrix_R::operator*=(const double &number) {

}

void Matrix_R::determinant() {

}

void Matrix_R::transpose() {

}

void Matrix_R::resize(const ptrdiff_t &newNumberOfLines, const ptrdiff_t & newNumberOfColumns) {

}

std::ostream& Matrix_R::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            ostrm << pRows_[i][j] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}