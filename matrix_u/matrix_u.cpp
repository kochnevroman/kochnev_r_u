#include "matrix_u.h"
#include <iostream>

Matrix_U::Matrix_U(const int nRol, const int nCol)
{
}

Matrix_U::Matrix_U(const Matrix_U &matrix_r)
{

}

Matrix_U::~Matrix_U()
{

}

double& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol) {

}

const double& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const {

}

//операции матрицы с матрицей
Matrix_U Matrix_U::operator=(const Matrix_U &matrix_r) {

}

Matrix_U Matrix_U::operator+=(const Matrix_U &matrix_r) {

}

Matrix_U Matrix_U::operator-=(const Matrix_U &matrix_r) {

}

Matrix_U Matrix_U::operator*=(const Matrix_U &matrix_r) {

}

//операции матрицы с числом
Matrix_U Matrix_U::operator+=(const double &number) {

}

Matrix_U Matrix_U::operator-=(const double &number) {

}

Matrix_U Matrix_U::operator*=(const double &number) {

}

void Matrix_U::determinant() {

}

void Matrix_U::transpose() {

}

void Matrix_U::resize(const ptrdiff_t &newNumberOfLines, const ptrdiff_t & newNumberOfColumns) {

}


std::ostream& Matrix_U::writeTo(std::ostream& ostrm) const
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