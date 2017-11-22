#pragma once
#ifndef MATRIX_R_MATRIX_R_H
#define MATRIX_R_MATRIX_R_H

#include <cstddef>
#include <iosfwd>

class Matrix_R
{
public:
    explicit Matrix_R() = default;
    Matrix_R(const ptrdiff_t& nRow, const ptrdiff_t& nCol);
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
    Matrix_R operator*=(const double& number);

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
    ptrdiff_t  nRow_ { 0 };
    ptrdiff_t  nCol_ { 0 };
    double** pdata_ { nullptr };
};

//операции матрицы с матрицей
Matrix_R operator+(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix);
Matrix_R operator-(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix);
Matrix_R operator*(const Matrix_R& firstMatrix, const Matrix_R& secondMatrix);

//операции матрицы с вектором
//

//операции матрицы с числом
Matrix_R operator*(const Matrix_R& matrix_r, const double& number);
Matrix_R operator*(const double& number, const Matrix_R& matrix_r);


inline std::ostream& operator<<(std::ostream& ostrm, const Matrix_R& matrix_r)
{
    return matrix_r.writeTo(ostrm);
}

#endif //MATRIX_R_MATRIX_R_H