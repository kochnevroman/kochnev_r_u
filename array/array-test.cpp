//
// Created by Roman Kochnev on 25.10.2017.
//

#include "array.h"
#include <iostream>
#include <sstream>

using  namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Array array;
    istrm >> array;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << array << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << array << endl;
    }
    return istrm.good();
}

int main()
{
    Array AB(5);
    AB.Add(-6);
    AB.Add(9);
    AB.Add(0);
    AB.Add(1);
    AB.Add(0);
    AB.Add(1);
    cout << AB;
    int t = 5;
    cin >> t;
    return 0;
}

std::ostream& Array::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}

std::istream& Array::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int x(0);
    char s(0);
    int y(0);
    int z(0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> s >> y_ >> s >> z_ >> rightBrace;
    if (istrm.good())
    {
        if ((Array::leftBrace == leftBrace) && (Array::separator == s)
            && (Array::rightBrace == rightBrace))
        {
            x_ = x;
            y_ = y;
            z_ = z;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}