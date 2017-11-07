//
// Created by Roman Kochnev on 19.10.2017.
//

#include "vector3d.h"
#include <iostream>
#include <sstream>

using namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Vector3d vector3d;
    istrm >> vector3d;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << vector3d << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << vector3d << endl;
    }
    return istrm.good();
}

int main()
{
    bool b_1 = Vector3d(3.1, 4.2, 7.9) == Vector3d(3.1, 4.2, 7.9);
    cout << "(3.1, 4.2, 7.9) == (3.1, 4.2, 7.9) = " << b_1 << endl;

    bool b_2 = Vector3d(3.1, 4.2, 7.9) != Vector3d(3.1, 4.2, 7.0);
    cout << "(3.1, 4.2, 7.9) != (3.1, 4.2, 7.0) = " << b_2 << endl << endl;

    Vector3d vector3d(1.2, 3.4, 5.6);
    cout << "Исходный вектор: " << vector3d << endl;

    vector3d += Vector3d(2.0, 1.1, 0.3);
    cout << "vector3d + (2.0, 1.1, 0.3) = " << vector3d << endl;

    vector3d -= Vector3d(1.2, 3.8, 0.2);
    cout << "vector3d - (2.0, 1.1, 0.3) = " << vector3d << endl;

    vector3d *= 3.14;
    cout << "vector3d * 3.14 =" << vector3d << endl;

    vector3d /= 3.14;
    cout << "vector3d / 3.14 =" << vector3d << endl << endl;

    Vector3d vec_a(3, 4, 5);
    Vector3d vec_b(1, 2, 6);

    Vector3d vec_a_b(scalarProduct(vec_a, vec_b));
    cout << "Скалярное произведение vec_a (3, 4, 5) на vec_b (1, 2, 6) = " << vec_a_b  << endl;

    double resultOfLength = length(vec_a);
    cout << "Длина вектора vec_a = " << resultOfLength  << endl << endl;

    testParse("{1.2, 3.4, 5.6}");
    testParse("{9, 4,5, 8.2}");
}

std::ostream& Vector3d::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}

std::istream& Vector3d::readFrom(std::istream& istrm)
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
        if ((Vector3d::leftBrace == leftBrace) && (Vector3d::separator == s)
            && (Vector3d::rightBrace == rightBrace))
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