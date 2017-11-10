#include "rational.h"
#include <iostream>
#include <sstream>

using  namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Rational rational;
    istrm >> rational;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << rational << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << rational << endl;
    }
    return istrm.good();
}

int main()
{
    Rational rational(3, 4);
    cout << endl << "Исходное число: " << rational << endl << endl;

    rational += Rational(1, 4);
    cout << "rational + 1/4 = " << rational << endl;

    rational -= Rational(3, 4);
    cout << "rational - 3/4 = " << rational << endl;

    rational *= Rational(1, 3);
    cout << "rational * 1/3 = " << rational << endl;

    rational /= Rational(3);
    cout << "rational / 3 = " << rational << endl;

    rational += Rational(35, 36);
    cout << "rational + 35/36 =" << rational << endl << endl;

    testParse("{12/13}");
    testParse("{7/ 11}");
    testParse("{4/ 3");

    return 0;
}
