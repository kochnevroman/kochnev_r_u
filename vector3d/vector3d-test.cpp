#include "vector3d.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Vector3d vector3d;
    istrm >> vector3d;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << vector3d << endl;
    } else {
        cout << "Read error: " << str << " -> " << vector3d << endl;
    }
    return istrm.good();
}

int main()
{
    testParse("{1.2, 3.4, 5.6}");
    testParse("{9, 4,5, 8.2}");

    bool b_1 = Vector3d(3.1, 4.2, 7.9) == Vector3d(3.1, 4.2, 7.9);
    cout << endl << "(3.1, 4.2, 7.9) == (3.1, 4.2, 7.9) = " << b_1 << endl;

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
    Vector3d vec_c(5, 7.5, 25);
    Vector3d vec_d(0, 0, 0);
    double number(2.5);

    cout << "Сумма вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a + vec_b << endl;
    cout << "Разность вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a - vec_b << endl << endl;

    cout << "Произведение вектора (3, 4, 5) и числа 2.5 = " << vec_a * number << endl;
    cout << "Произведение числа 2.5 и вектора (3, 4, 5) = " << number * vec_a << endl << endl;

    cout << "Отношение вектора (5, 7.5, 25) и числа 2.5 = " << vec_c / number << endl;

    double vec_a_b(vec_a.scalarProduct(vec_b));
    cout << "Скалярное произведение vec_a(3, 4, 5) на vec_b(1, 2, 6) = " << vec_a_b << endl;

    double resultOfLength( vec_a.length() );
    cout << "Длина вектора vec_a(3, 4, 5) = " << resultOfLength << endl << endl;

    double resultOfCosineAngle( vec_a.cosineOfAngle(vec_b) );
    cout << "Косинус между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = cos(" << resultOfCosineAngle << ')' << endl;
    cout << "Угол между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = " << acos(resultOfCosineAngle) << " градусов" << endl
         << endl;

    double resultOfCosineAnglewithZeroLength( vec_c.cosineOfAngle(vec_d) );
    cout << "Косинус между вектором vec_c(5, 7.5, 25) и vec_d(0, 0, 0) = cos(" << resultOfCosineAnglewithZeroLength
         << ')' << endl;
    cout << "Угол между вектором vec_c(5, 7.5, 25) и vec_d(0, 0, 0) = " << acos(resultOfCosineAnglewithZeroLength)
         << " градусов" << endl;
}