#include "matrix_r.h"
#include <iostream>
#include <stdexcept>

Matrix_R::Matrix_R(const ptrdiff_t &nRow, const ptrdiff_t &nCol)
{
    if (nRow > 0 && nCol > 0) {
        nRow_ = nRow;
        nCol_ = nCol;

        pdata_ = new double *[nRow_];
        for (ptrdiff_t i = 0; i < nRow_; i++) {
            pdata_[i] = new double[nCol_];
        }
    }
    else
        throw ("Число строк или столбцов не может быть отрицательным");

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

double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pdata_[iRow][iCol];
    }
    else
        throw("Неправильный индекс элемента");

}

const double& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pdata_[iRow][iCol];
    }
    else
        throw("Неправильный индекс элемента");
}

//операции матрицы с матрицей
Matrix_R Matrix_R::operator=(const Matrix_R &matrix_r)
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

    return *this;
}

Matrix_R Matrix_R::operator+=(const Matrix_R& matrix_r)
{
    if (nRow_ == matrix_r.nRow_ && nCol_ == matrix_r.nCol_)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pdata_[i][j] += matrix_r.pdata_[i][j];
            }
        }
        return *this;
    }

    else {
        throw ("Матрицы разного размера");
    }
}

Matrix_R Matrix_R::operator-=(const Matrix_R &matrix_r) {
    if (nRow_ == matrix_r.nRow_ || nCol_ == matrix_r.nCol_)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pdata_[i][j] -= matrix_r.pdata_[i][j];
            }
        }
        return *this;
    }

    else {
        throw ("Матрицы разного размера");
    }
}

Matrix_R Matrix_R::operator*=(const Matrix_R &matrix_r)
{
    if (nRow_ == matrix_r.nCol_ && nCol_ == matrix_r.nRow_)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                for (ptrdiff_t inner = 0; inner < 3; inner++)
                {
                    pdata_[i][j] += pdata_[i][inner] * matrix_r.pdata_[inner][j];
                }
            }
        }
        return *this;
    }
    else {
        throw ("Матрицы невозможно перемножить");
    }
}

//операции матрицы с числом
Matrix_R Matrix_R::operator*=(const double &number)
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            pdata_[i][j] *= number;
        }
    }
    return *this;
}

const ptrdiff_t& Matrix_R::getRowCount() const
{
    return nRow_;
}

const ptrdiff_t& Matrix_R::getColCount() const
{
    return nCol_;
}

void Matrix_R::determinant() {

}

void Matrix_R::transpose()
{
    double** newMatrix = new double*[nRow_];

    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        newMatrix[i] = new double[nCol_];
    }

    for (ptrdiff_t i = 0; i < nCol_; i++)
    {
        for (ptrdiff_t j = 0; j < nRow_; j++)
        {
            newMatrix[i][j] = pdata_[i][j];
        }
    }
    delete[] pdata_;
    pdata_ = newMatrix;
}

void Matrix_R::resize(const ptrdiff_t &newNumberOfLines, const ptrdiff_t & newNumberOfColumns) {

}

void Matrix_R::addRow(const ptrdiff_t &newRowIndex, const double& newRow) {

}

void Matrix_R::addCol(const ptrdiff_t &newColIndex, const double& newCol) {

}

void Matrix_R::removeRowFirst()
{
    double **newMatrix = new double *[nRow_ - 1];

    for (ptrdiff_t i = 0; i < nRow_ - 1; i++)
    {
        newMatrix[i] = new double[nCol_];
    }

    for (ptrdiff_t i = 0; i < nRow_ - 1; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            newMatrix[i][j] = pdata_[i + 1][j];
        }

        delete[] pdata_;
        pdata_ = newMatrix;
    }
}

void Matrix_R::removeRowLast() {

}

void Matrix_R::removeRow(const ptrdiff_t &removableRowIndex)
{
    if (removableRowIndex >= 0 && removableRowIndex < nRow_)
    {
        double **newMatrix = new double *[nRow_ - 1];

        for (ptrdiff_t i = 0; i < nRow_ - 1; i++)
        {
            newMatrix[i] = new double[nCol_];
        }

        for (ptrdiff_t i = 0; i < removableRowIndex; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                newMatrix[i][j] = pdata_[i][j];
            }
        }

        for (ptrdiff_t i = removableRowIndex; i < nRow_ - 1; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                newMatrix[i][j] = pdata_[i + 1][j];
            }
        }

        delete[] pdata_;
        pdata_ = newMatrix;
    }
    else {
        throw ("неправильный номер строки");
    }

}

void Matrix_R::removeColFirst() {

}

void Matrix_R::removeColLast() {

}

void Matrix_R::removeCol(const ptrdiff_t &removableColIndex)
{
    if (removableColIndex > 0 && removableColIndex < nCol_)
    {
        double **newMatrix = new double *[nRow_ - 1];

        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            newMatrix[i] = new double[nCol_ - 1];
        }

        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pdata_[i][j] = pdata_[i][j];
            }
        }

        delete[] pdata_;
        pdata_ = newMatrix;
    }
    else {
        throw ("неправильный номер столбца");
    }
}

void Matrix_R::multiplyNumberToRow(const double &number) {

}

void Matrix_R::multiplyNumberToCol(const double &number) {

}

void Matrix_R::reshuffleTwoRows(const ptrdiff_t &firstRow, const ptrdiff_t &secondRow)
{
    if (firstRow > 0 && firstRow < nRow_ && secondRow > 0 && secondRow < nRow_)
    {
    }
    else
        throw("Неправильный номер строки");

}

void Matrix_R::reshuffleTwoCols(const ptrdiff_t &firstCol, const ptrdiff_t &secondCol)
{
    if (firstCol > 0 && firstCol < nRow_ && secondCol > 0 && secondCol < nRow_)
    {
    }
    else
        throw("Неправильный номер столбца");

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

Matrix_R operator*(const Matrix_R& matrix_r, const double& number)
{
    Matrix_R matrix(matrix_r);
    return  matrix *= number;
}

Matrix_R operator*(const double& number, const Matrix_R& matrix_r)
{
    Matrix_R matrix(matrix_r);
    return  matrix *= number;
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