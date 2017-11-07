#include "complex.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();
}
int main()
{
    using namespace std;
    Complex z(0.0, 0);
    cout << endl << "Исходное комплексное число: " << z << endl << endl;

    z += Complex(9.0, 2);
    cout << "z + (9.0 +2*i) = " << z << endl;

    z -= Complex(12.0, 2);
    cout << "z - (12.0 + 2*i) = " << z << endl;

    z *= 3.0;
    cout << "z * 3.0 = " << z << endl;

    z *= Complex(4.0, 6);
    cout << "z * (4.0 + 6*i) = " << z << endl;

    z /= 2.0;
    cout << " z / 2.0 = " << z << endl;

    z /= Complex(3.0, 3);
    cout << " z / (3.0 + 3*i) = "<< z << endl;

    cout << endl;

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");

    cout << endl;

    z += 12.0;
    cout << " z + 12.0 = " << z << endl;

    z -= 11.0;
    cout << " z - 11.0 = " << z << endl;

    z += 5;
    cout << " z + 5 = " << z << endl;

    z -= 4;
    cout << " z - 4 = " << z << endl;

    z *= 7;
    cout << "z * 7 = " << z << endl;

    z /= 2;
    cout << " z / 2 = " << z << endl;

    z += Complex(12);
    cout << " 12 + z = " << z << endl;

    z += Complex(3.14);
    cout << " 3.14 + z = " << z << endl;

    z += Complex(-1);
    cout << " (-1) + z = " << z << endl;

    z += Complex(-9.8);
    cout << " (-9.8) + z = " << z << endl;

    Complex z_2(5, 8);
    bool b_1 = z == z_2;
    cout << " z == (5 + 8*i) = " << (bool)b_1 << endl;

    Complex z_3(3, 5);
    bool b_2 = z != z_3;
    cout << " z != (2 + 8*i) = "<< (bool)b_2 << endl;

    return 0;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good())
    {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace))
        {
            re = real;
            im = imaginary;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}