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

    //операции матриц с матрицей
    Matrix_U operator=(const Matrix_U& matrix_u);
    Matrix_U operator+=(const Matrix_U& matrix_u);
    Matrix_U operator-=(const Matrix_U& matrix_u);
    Matrix_U operator*=(const Matrix_U& matrix_u);

    //операции матрицы с вектором
    //

    //операции матрицы с числом
    Matrix_U operator*=(const double& number);

    const ptrdiff_t& getRowCount() const;
    const ptrdiff_t& getColCount() const;

/*
    void determinant();
    void transpose();
    void resize(const ptrdiff_t& newNumberOfLines, const ptrdiff_t& newNumberOfColumns);

    //добавление строки
    void addRow(const ptrdiff_t& newRowIndex, const double& newRow);
    //добавление столбца
    void addCol(const ptrdiff_t& newColIndex, const double& newCol);

    //удаление первой строки
    void removeRowFirst();
    //удаление последней строки
    void removeRowLast();
    //удаление произвольной строки
    void removeRow(const ptrdiff_t& removableRowIndex);

    //удаление первого столбца
    void removeColFirst();
    //удаление последнего столбца
    void removeColLast();
    //удаление произвольного столбца
    void removeCol(const ptrdiff_t& removableColIndex);

    //умножение строки на число
    void multiplyNumberToRow(const double& number);

    //умножение столбца на число
    void multiplyNumberToCol(const double& number);

    //перестановка двух строк
    void reshuffleTwoRows(const ptrdiff_t& firstRow, const ptrdiff_t& secondRow);

    //перестановка двух столбцов
    void reshuffleTwoCols(const ptrdiff_t& firstCol, const ptrdiff_t& secondCol);
     */

    std::ostream& writeTo(std::ostream& ostrm ) const;

private:
    ptrdiff_t nRow_ { 0 };
    ptrdiff_t nCol_ { 0 };
    double* pdata_ {nullptr};

};

//операции матрицы с матрицей
Matrix_U operator+(const Matrix_U& matrix1, const Matrix_U& matrix2);
Matrix_U operator-(const Matrix_U& matrix1, const Matrix_U& matrix2);
Matrix_U operator*(const Matrix_U& matrix1, const Matrix_U& matrix2);

//операции матрицы с вектором
//

//операции матрицы с числом
Matrix_U operator*(const Matrix_U& matrix_u, const double& number);
Matrix_U operator*(const double& number, const Matrix_U& matrix_u);


inline std::ostream& operator<<(std::ostream& ostrm, const Matrix_U& matrix_u)
{
    return  matrix_u.writeTo(ostrm);
}

#endif //MATRIX_U_MATRIX_U_H
