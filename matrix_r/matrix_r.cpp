#include "matrix_r.h"
#include <iostream>

Matrix_R::Matrix_R()
{

}

Matrix_R::~Matrix_R()
{

}


std::ostream& Matrix_R::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCow_; j++)
        {
            ostrm << pRows_[i][j] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}