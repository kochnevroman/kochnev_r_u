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
    testParse("{1.2, 3.4, 5.6}");
    testParse("{9, 4,5, 8.2}");

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

    Vector3d sumOperation = vec_a + vec_b;
    cout << "Сумма вектора (3, 4, 5) и вектора (1, 2, 6) = " << sumOperation << endl;

    Vector3d subOperation = vec_a - vec_b;
    cout << "Разность вектора (3, 4, 5) и вектора (1, 2, 6) = " << subOperation << endl;

    //добавить остальные операции

    double vec_a_b(scalarProduct(vec_a, vec_b));
    cout << "Скалярное произведение vec_a (3, 4, 5) на vec_b (1, 2, 6) = " << vec_a_b  << endl;

    double resultOfLength = length(vec_a);
    cout << "Длина вектора vec_a = " << resultOfLength  << endl << endl;
}