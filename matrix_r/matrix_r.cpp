#include "matrix_r.h"
#include <iostream>
#include <stdexcept>

Matrix_R::Matrix_R(const ptrdiff_t &nRow, const ptrdiff_t &nCol) {
    if (nRow < 0 || nCol < 0)
    {
        throw ("Количество строк или столбцов не может быть отрицательным");
    }
    else {
        nRow_ = nRow;
        nCol_ = nCol;

        pdata_ = new double*[nRow_];
        pdata_[0] = new double[nRow_ * nCol_];
        for (ptrdiff_t i = 0; i < nCol_ - 2; i += 1)
        {
            pdata_[i + 1] = pdata_[i] + nCol_;
        }
    }

}

Matrix_R::Matrix_R(const Matrix_R &matrix_r)
{
    nCol_ = matrix_r.nCol_;
    nRow_ = matrix_r.nRow_;
    pdata_ = new double* [nRow_];

    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        pdata_[i] = new double[nCol_];
    }

    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            pdata_[i][j] = matrix_r.pdata_[i][j];
        }
    }
}

Matrix_R::~Matrix_R()
{
    nRow_ = 0;
    nCol_ = 0;
    delete[] pdata_;
    pdata_ = nullptr;
}

double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) {

}

const double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const {

}

//операции матрицы с матрицей
Matrix_R Matrix_R::operator=(const Matrix_R &matrix_r)
{
    nCol_ = matrix_r.nCol_;
    nRow_ = matrix_r.nRow_;
    pdata_ = new double* [nRow_];

    for (ptrdiff_t i = 0; i < nRow_; i += 1)
    {
        pdata_[i] = new double[nCol_];
    }
    for (ptrdiff_t i = 0; i < nRow_; i += 1)
    {
        for (ptrdiff_t j = 0; j < nCol_; j += 1)
        {
            pdata_[i][j] = matrix_r.pdata_[i][j];
        }
    }

    return *this;
}

Matrix_R Matrix_R::operator+=(const Matrix_R &matrix_r)
{
    if (nRow_ == matrix_r.nRow_ || nCol_ == matrix_r.nRow_)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pdata_[i][j] += matrix_r.pdata_[i][j];
            }
        }
    }

    else {
        throw ("Матрицы разного размера");
    }
}

Matrix_R Matrix_R::operator-=(const Matrix_R &matrix_r) {
    if (nRow_ == matrix_r.nRow_ || nCol_ == matrix_r.nRow_)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pdata_[i][j] -= matrix_r.pdata_[i][j];
            }
        }
    }

    else {
        throw ("Матрицы разного размера");
    }
}

Matrix_R Matrix_R::operator*=(const Matrix_R &matrix_r) {

}

//операции матрицы с числом
Matrix_R Matrix_R::operator*=(const double &number) {

}

const ptrdiff_t& Matrix_R::nRow() const
{
    return nRow_;
}

const ptrdiff_t& Matrix_R::nCol() const
{
    return nCol_;
}

void Matrix_R::determinant() {

}

void Matrix_R::transpose() {

}

void Matrix_R::resize(const ptrdiff_t &newNumberOfLines, const ptrdiff_t & newNumberOfColumns) {

}

void Matrix_R::addRow(const ptrdiff_t &newRowIndex, const double &*newRow) {

}

void Matrix_R::addCol(const ptrdiff_t &newColIndex, const int &*newCol) {

}

void Matrix_R::removeRow(const ptrdiff_t &removableRowIndex) {

}

void Matrix_R::removeCol(const ptrdiff_t &removableColIndex) {

}

void Matrix_R::multiplyNumberToRow(const double &number) {

}

void Matrix_R::multiplyNumberToCol(const double &number) {

}

void Matrix_R::reshuffleTwoRows(const ptrdiff_t &firstRow, const ptrdiff_t &secondRow) {

}

void Matrix_R::reshuffleTwoCols(const ptrdiff_t &firstCol, const ptrdiff_t &secondCol) {

}

Matrix_R operator+(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix)
{
    Matrix_R matrix_r(firstMatrix);
    return  matrix_r += secondMatrix;
}

Matrix_R operator-(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix)
{
    Matrix_R matrix_r(firstMatrix);
    return  matrix_r -= secondMatrix;
}

Matrix_R operator*(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix)
{
    Matrix_R matrix_r(firstMatrix);
    return  matrix_r *= secondMatrix;
}

std::ostream& Matrix_R::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            ostrm << pdata_[i][j] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}