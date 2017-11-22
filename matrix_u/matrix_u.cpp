#include "matrix_u.h"
#include <iostream>

Matrix_U::Matrix_U(const ptrdiff_t& nRow, const ptrdiff_t& nCol)
{
    nRow_ = nRow;
    nCol_ = nCol;
    pdata_ = new double[nRow_* nCol_];
}

Matrix_U::Matrix_U(const Matrix_U &matrix_u)
{
    nRow_ = matrix_u.nRow_;
    nCol_ = matrix_u.nCol_;
    pdata_ = new double[nRow_ * nCol_];

    for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++)
    {
        pdata_[i] = matrix_u.pdata_[i];
    }
}

Matrix_U::~Matrix_U()
{
    nRow_ = 0;
    nCol_ = 0;
    delete[] pdata_;
    pdata_ = nullptr;
}

double& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pdata_[nCol_ * iRow + iCol];
    }
    else
        throw("Неправильный индекс элемента");
}

const double& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pdata_[nCol_ * iRow + iCol];
    }
    else
        throw("Неправильный индекс элемента");
}

//операции матрицы с матрицей
Matrix_U Matrix_U::operator=(const Matrix_U &matrix_u)
{
    for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++)
    {
        pdata_[i] = matrix_u.pdata_[i];
    }

    return *this;
}

Matrix_U Matrix_U::operator+=(const Matrix_U &matrix_u)
{
    if (nRow_ == matrix_u.nRow_ && nCol_ == matrix_u.nCol_)
    {
        for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++)
        {
            pdata_[i] += matrix_u.pdata_[i];
        }
        return *this;
    }

    else {
        throw ("Матрицы разного размера");
    }
}

Matrix_U Matrix_U::operator-=(const Matrix_U &matrix_u)
{
    if (nRow_ == matrix_u.nRow_ && nCol_ == matrix_u.nCol_)
    {
        for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++)
        {
            pdata_[i] -= matrix_u.pdata_[i];
        }
        return *this;
    }

    else {
        throw ("Матрицы разного размера");
    }
}


Matrix_U Matrix_U::operator*=(const Matrix_U &matrix_u)
{
   // /*
    double* newMatrix = new double[nRow_*nCol_];

    if (nRow_ == matrix_u.nCol_)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                for (ptrdiff_t inner = 0; inner < 3; inner++)
                {
                    newMatrix[inner] += pdata_[inner] * matrix_u.pdata_[inner];
                }
            }
        }

        delete[] pdata_;
        pdata_ = nullptr;
        pdata_ = newMatrix;

        return *this;
    }
    else {
        throw ("Матрицы невозможно перемножить");
    }
     //*/
}

//операции матрицы с числом
Matrix_U Matrix_U::operator*=(const double &number)
{
    for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++)
    {
        pdata_[i] *= number;
    }
    return *this;
}

const ptrdiff_t& Matrix_U::getRowCount() const
{
    return nRow_;
}

const ptrdiff_t& Matrix_U::getColCount() const
{
    return nCol_;
}

/*
void Matrix_U::determinant() {

}

void Matrix_U::transpose() {

}

void Matrix_U::resize(const ptrdiff_t &newNumberOfLines, const ptrdiff_t & newNumberOfColumns) {

}
*/

//операции матрицы с матрицей
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

//операции матрицы с вектором
//

//операции матрицы с числом
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


std::ostream& Matrix_U::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t j = 0; j < nRow_ * nCol_; j += nCol_)
    {
        for (ptrdiff_t i = j; i < j + nCol_; i++)
        {
            ostrm << pdata_[i] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}