#include "matrix_u.h"
#include <iostream>

Matrix_U::Matrix_U(const ptrdiff_t& nRow, const ptrdiff_t& nCol)
{
    if (nRow > 0 && nCol > 0) {

    nRow_ = nRow;
    nCol_ = nCol;
    pData_ = new double[nRow_* nCol_];

    } else {
        throw std::invalid_argument("The number of rows or columns can not be less than zero");
    }
}

Matrix_U::Matrix_U(const Matrix_U &matrix_u)
{
    nRow_ = matrix_u.nRow_;
    nCol_ = matrix_u.nCol_;
    pData_ = new double[nRow_ * nCol_];

    for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {
        pData_[i] = matrix_u.pData_[i];
    }
}

Matrix_U::~Matrix_U()
{
    nRow_ = 0;
    nCol_ = 0;
    delete[] pData_;
    pData_ = nullptr;
}

double& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_) {
        return pData_[nCol_ * iRow + iCol];
    } else {
        throw std::invalid_argument("Invalid element index");
    }
}

const double& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_) {
        return pData_[nCol_ * iRow + iCol];
    } else {
        throw std::invalid_argument("Invalid element index");
    }
}

Matrix_U Matrix_U::operator=(const Matrix_U &matrix_u)
{
    for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {
        pData_[i] = matrix_u.pData_[i];
    }
    return *this;
}

Matrix_U Matrix_U::operator+=(const Matrix_U &matrix_u)
{
    if (nRow_ == matrix_u.nRow_ && nCol_ == matrix_u.nCol_) {

        for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {

            pData_[i] += matrix_u.pData_[i];
        }
        return *this;

    } else {
        throw std::invalid_argument("Matrices of different sizes");
    }
}

Matrix_U Matrix_U::operator-=(const Matrix_U &matrix_u)
{
    if (nRow_ == matrix_u.nRow_ && nCol_ == matrix_u.nCol_) {

        for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {

            pData_[i] -= matrix_u.pData_[i];
        }
        return *this;

    } else {
        throw std::invalid_argument("Matrices of different sizes");
    }
}

// Something always goes wrong.
Matrix_U Matrix_U::operator*=(const Matrix_U &matrix_u)
{
    double* newMatrix = new double[nRow_*nCol_];

    if (nRow_ == matrix_u.nCol_) {

        for (ptrdiff_t iRow(0); iRow < nRow_ * nCol_; iRow += 1) {

            for (ptrdiff_t jCol(0); jCol < nCol_; jCol += 1) {

                for (ptrdiff_t inner(0); inner < nRow_; inner += 1) {

                    newMatrix[inner] += pData_[inner] * matrix_u.pData_[inner];
                }
            }
        }

        delete[] pData_;
        pData_ = nullptr;
        pData_ = newMatrix;

        return *this;

    } else {
        throw std::invalid_argument("Matrices can not be multiplied");
    }
}

Matrix_U Matrix_U::operator*=(const double &number)
{
    for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {
        pData_[i] *= number;
    }
    return *this;
}

ptrdiff_t Matrix_U::getRowCount() const
{
    return nRow_;
}

ptrdiff_t Matrix_U::getColCount() const
{
    return nCol_;
}

Matrix_U operator+(const Matrix_U& matrix1, const Matrix_U& matrix2)
{
    Matrix_U matrix_u(matrix1);
    return matrix_u += matrix2;
}

Matrix_U operator-(const Matrix_U& matrix1, const Matrix_U& matrix2)
{
    Matrix_U matrix_u(matrix1);
    return matrix_u -= matrix2;
}

Matrix_U operator*(const Matrix_U& matrix1, const Matrix_U& matrix2)
{
    Matrix_U matrix_u(matrix1);
    return matrix_u *= matrix2;
}

Matrix_U operator*(const Matrix_U& matrix_u, const double& number)
{
    Matrix_U matrix(matrix_u);
    return matrix *=number;
}

Matrix_U operator*(const double& number, const Matrix_U& matrix_u)
{
    Matrix_U matrix(matrix_u);
    return matrix *=number;
}

std::ostream& operator<<(std::ostream& ostrm, const Matrix_U& matrix_u)
{
    return  matrix_u.writeTo(ostrm);
}

std::ostream& Matrix_U::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t iRow(0); iRow < nRow_ * nCol_; iRow += nCol_) {

        for (ptrdiff_t jCol(iRow); jCol < iRow + nCol_; jCol += 1) {

            ostrm << pData_[jCol] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}