#include <iostream>
#include <cstddef>

class Matrix_R
{
public:
    Matrix_R();
    Matrix_R(const double row, const double col);
    Matrix_R(const Matrix_R& rhs);
    ~Matrix_R();

    double& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const double& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    std::ostream& WriteTo(std::ostream& ostrm ) const;

private:
    ptrdiff_t  nRow_ { 0 };
    ptrdiff_t  nCow_ { 0 };
    int** pRows ( nullptr );
};

Matrix_R::Matrix_R()
{

}

Matrix_R::~Matrix_R()
{

}



int main() {
    std::cout << " ~| _ o-0 _ |~" << std::endl;
    return 0;
}