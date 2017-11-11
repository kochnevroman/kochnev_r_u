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
    Matrix_R(const Matrix_R& rhs);
    ~Matrix_R();

    double& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const double& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;

    Matrix_R operator=(const Matrix_R& matrix_r);
    Matrix_R operator+=(const Matrix_R& matrix_r);
    Matrix_R operator-=(const Matrix_R& matrix_r);

    const ptrdiff_t getnRow() const;
    const ptrdiff_t getnCol() const;

    std::ostream& writeTo(std::ostream& ostrm ) const;

private:
    ptrdiff_t  nRow_ { 0 };
    ptrdiff_t  nCow_ { 0 };
    int** pRows_ ( nullptr );
};

Matrix_R operator*(const Matrix_R& m, const Matrix_R& n);


inline std::ostream& operator<<(std::ostream& ostrm, const Matrix_R& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif //MATRIX_R_MATRIX_R_H