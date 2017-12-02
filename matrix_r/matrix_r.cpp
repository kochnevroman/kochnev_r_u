#include "matrix_r.h"
#include <iostream>

Matrix_R::Matrix_R(const ptrdiff_t& nRow, const ptrdiff_t& nCol)
        : nRow_(nRow)
        , nCol_(nCol)
{
    if (nRow_ > 0 && nCol_ > 0) {

        pData_ = new double *[nRow_];
        for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

            pData_[iRow] = new double[nCol_];
        }

    } else {
        throw std::invalid_argument("The number of rows or columns can not be less than zero");
    }

}

Matrix_R::Matrix_R(const Matrix_R& matrix_r)
        : nRow_(matrix_r.nRow_)
        , nCol_(matrix_r.nCol_)
{
    pData_ = new double* [nRow_];

    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

        pData_[iRow] = new double[nCol_];
    }

    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

        for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {

            pData_[iRow][iCol] = matrix_r.pData_[iRow][iCol];
        }
    }
}

Matrix_R::~Matrix_R()
{
    for (int i = 0; i < nRow_; i++) {
        delete[] pData_[i];
        pData_[i] = nullptr;
    }
    nRow_ = 0;
    nCol_ = 0;
    delete[] pData_;
    pData_ = nullptr;
}

double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_) {
        return pData_[iRow][iCol];
    } else {
        throw std::invalid_argument("Invalid element index");
    }

}

const double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_) {
        return pData_[iRow][iCol];
    } else {
        throw std::invalid_argument("Invalid element index");
    }
}

Matrix_R& Matrix_R::operator=(const Matrix_R& matrix_r)
{
    nCol_ = matrix_r.nCol_;
    nRow_ = matrix_r.nRow_;
    pData_ = new double* [nRow_];

    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {
        pData_[iRow] = new double[nCol_];
    }

    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {
        for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {
            pData_[iRow][iCol] = matrix_r.pData_[iRow][iCol];
        }
    }

    return *this;
}

Matrix_R& Matrix_R::operator+=(const Matrix_R& matrix_r)
{
    if (nRow_ == matrix_r.nRow_ && nCol_ == matrix_r.nCol_) {

        for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

            for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {

                pData_[iRow][iCol] += matrix_r.pData_[iRow][iCol];
            }
        }
        return *this;

    } else {
        throw std::invalid_argument("Matrices of different sizes");
    }
}

Matrix_R& Matrix_R::operator-=(const Matrix_R& matrix_r)
{
    if (nRow_ == matrix_r.nRow_ || nCol_ == matrix_r.nCol_) {

        for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

            for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {

                pData_[iRow][iCol] -= matrix_r.pData_[iRow][iCol];
            }
        }
        return *this;

    } else {
        throw std::invalid_argument("Matrices of different sizes");
    }
}

Matrix_R& Matrix_R::operator*=(const Matrix_R& matrix_r)
{
    double** newMatrix = new double*[nRow_];

    for (ptrdiff_t i = 0; i < nRow_; i++) {
        newMatrix[i] = new double[nCol_];
    }

    if (nRow_ == matrix_r.nCol_) {

        for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

            for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {

                for (ptrdiff_t inner(0); inner < nRow_; inner += 1) {

                    newMatrix[iRow][iCol] += pData_[iRow][inner] * matrix_r.pData_[inner][iCol];
                }
            }
        }

        for (int i = 0; i < nRow_; i++) {
            delete[] pData_[i];
            pData_[i] = nullptr;
        }

        delete[] pData_;
        pData_ = nullptr;
        pData_ = newMatrix;

        return *this;

    } else {
        throw std::invalid_argument("Matrices can not be multiplied");
    }
}

Matrix_R& Matrix_R::operator*=(const double number)
{
    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

        for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {

            pData_[iRow][iCol] *= number;
        }
    }
    return *this;
}

ptrdiff_t Matrix_R::getRowCount() const
{
    return nRow_;
}

ptrdiff_t Matrix_R::getColCount() const
{
    return nCol_;
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

Matrix_R operator*(const Matrix_R& matrix_r, const double number)
{
    Matrix_R matrix(matrix_r);
    return  matrix *= number;
}

Matrix_R operator*(const double number, const Matrix_R& matrix_r)
{
    Matrix_R matrix(matrix_r);
    return  matrix *= number;
}

std::ostream& operator<<(std::ostream& ostrm, const Matrix_R& matrix_r)
{
    return matrix_r.writeTo(ostrm);
}

std::ostream& Matrix_R::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t iRow(0); iRow < nRow_; iRow += 1) {

        for (ptrdiff_t iCol(0); iCol < nCol_; iCol += 1) {

            ostrm << pData_[iRow][iCol] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}