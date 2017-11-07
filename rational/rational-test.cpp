//
// Created by Roman Kochnev on 29.09.2017.
//

#include "rational.h"
#include <iostream>
#include <sstream>

using  namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Rational r;
    istrm >> r;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << r << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << r << endl;
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

ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << num_ << separator << denom_ << rightBrace;
    return ostrm;
}

istream& Rational::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int num(0);
    char s(0);
    int denom(0);
    char rightBrace(0);
    istrm >> leftBrace >> num_ >> s >> denom_ >> rightBrace;
    if (istrm.good())
    {
        if ((Rational::leftBrace == leftBrace) && (Rational::separator == s)
            && (Rational::rightBrace == rightBrace))
        {
            num_ = num;
            denom_ = denom;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
