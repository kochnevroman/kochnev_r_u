#include "vector3d_t.h"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Vector3d_T<T> vector3d_t;
    istrm >> vector3d_t;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << vector3d_t << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << vector3d_t << endl;
    }
    return istrm.good();
}

int main() {
    cout << "------------------Начало теста Vector3D_T с типом double------------------" << endl;

    testParse<double>("{1.2, 3.4, 5.6}");
    testParse<double>("{9, 4,5, 8.2}");

    bool b_1 = Vector3d_T<double>(3.1, 4.2, 7.9) == Vector3d_T<double>(3.1, 4.2, 7.9);
    cout << endl << "(3.1, 4.2, 7.9) == (3.1, 4.2, 7.9) = " << b_1 << endl;

    bool b_2 = Vector3d_T<double>(3.1, 4.2, 7.9) != Vector3d_T<double>(3.1, 4.2, 7.0);
    cout << "(3.1, 4.2, 7.9) != (3.1, 4.2, 7.0) = " << b_2 << endl << endl;

    Vector3d_T<double> vector3d_t(1.2, 3.4, 5.6);
    cout << "Исходный вектор: " << vector3d_t << endl;

    vector3d_t += Vector3d_T<double>(2.0, 1.1, 0.3);
    cout << "vector3d_t + (2.0, 1.1, 0.3) = " << vector3d_t << endl;

    vector3d_t -= Vector3d_T<double>(1.2, 3.8, 0.2);
    cout << "vector3d_t - (2.0, 1.1, 0.3) = " << vector3d_t << endl;

    vector3d_t *= 3.14;
    cout << "vector3d_t * 3.14 =" << vector3d_t << endl;

    vector3d_t /= 3.14;
    cout << "vector3d_t / 3.14 =" << vector3d_t << endl << endl;

    Vector3d_T<double> vec_a(3, 4, 5);
    Vector3d_T<double> vec_b(1, 2, 6);
    Vector3d_T<double> vec_c(5, 7.5, 25);
    Vector3d_T<double> vec_d(0, 0, 0);
    double number(2.5);

    cout << "Сумма вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a + vec_b << endl;
    cout << "Разность вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a - vec_b << endl << endl;

    cout << "Произведение вектора (3, 4, 5) и числа 2.5 = " << vec_a * number << endl;
    cout << "Произведение числа 2.5 и вектора (3, 4, 5) = " << number * vec_a << endl << endl;

    cout << "Отношение вектора (5, 7.5, 25) и числа 2.5 = " << vec_c / number << endl;

    double vec_a_b(vec_a.scalarProduct(vec_b));
    cout << "Скалярное произведение vec_a(3, 4, 5) на vec_b(1, 2, 6) = " << vec_a_b << endl;

    double resultOfLength(vec_a.length());
    cout << "Длина вектора vec_a(3, 4, 5) = " << resultOfLength << endl << endl;

    double resultOfCosineAngle(vec_a.cosineOfAngle(vec_b));
    cout << "Косинус между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = cos(" << resultOfCosineAngle << ')' << endl;
    cout << "Угол между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = " << acos(resultOfCosineAngle) << " градусов" << endl
         << endl;

    double resultOfCosineAnglewithZeroLength(vec_c.cosineOfAngle(vec_d));
    cout << "Косинус между вектором vec_c(5, 7.5, 25) и vec_d(0, 0, 0) = cos(" << resultOfCosineAnglewithZeroLength
         << ')' << endl;
    cout << "Угол между вектором vec_c(5, 7.5, 25) и vec_d(0, 0, 0) = " << acos(resultOfCosineAnglewithZeroLength)
         << " градусов" << endl << endl;

    cout << "------------------Конец теста Vector3D_T с типом double------------------" << endl;


    cout << endl << "-------------------Начало теста Vector3D_T с типом int-------------------" << endl;

    testParse<int>("{1, 3, 6}");
    testParse<int>("{9, 4, 8}");

    bool b_1_int = Vector3d_T<int>(3, 4, 9) == Vector3d_T<int>(3, 4, 9);
    cout << endl << "(3, 4, 9) == ((3, 4, 9) = " << b_1_int << endl;

    bool b_2_int = Vector3d_T<int>(3, 4, 9) != Vector3d_T<int>(3, 4, 7);
    cout << "(3, 4, 9) != (3, 4, 7) = " << b_2_int << endl << endl;

    Vector3d_T<int> vector3d_t_int(1, 3, 5);
    cout << "Исходный вектор: " << vector3d_t << endl;

    vector3d_t_int += Vector3d_T<int>(2, 1, 3);
    cout << "vector3d_t + (2, 1, 3) = " << vector3d_t << endl;

    vector3d_t_int -= Vector3d_T<int>(1, 3, 0);
    cout << "vector3d_t - (2.0, 1.1, 0.3) = " << vector3d_t << endl;

    vector3d_t_int *= 3;
    cout << "vector3d_t * 3.14 =" << vector3d_t << endl;

    vector3d_t_int /= 3;
    cout << "vector3d_t / 3.14 =" << vector3d_t << endl << endl;

    Vector3d_T<int> vec_a_int(3, 4, 5);
    Vector3d_T<int> vec_b_int(1, 2, 6);
    Vector3d_T<int> vec_c_int(5, 7, 25);
    Vector3d_T<int> vec_d_int(0, 0, 0);
    int number_int(5);

    cout << "Сумма вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a_int + vec_b_int << endl;
    cout << "Разность вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a_int - vec_b_int << endl << endl;

    cout << "Произведение вектора (3, 4, 5) и числа 5 = " << vec_a_int * number_int << endl;
    cout << "Произведение числа 5 и вектора (3, 4, 5) = " << number_int * vec_a_int << endl << endl;

    cout << "Отношение вектора (5, 7, 25) и числа 5 = " << vec_c_int / number_int << endl;

    double vec_a_b_int(vec_a_int.scalarProduct(vec_b_int));
    cout << "Скалярное произведение vec_a(3, 4, 5) на vec_b(1, 2, 6) = " << vec_a_b_int << endl;

    double resultOfLengthInt(vec_a_int.length());
    cout << "Длина вектора vec_a(3, 4, 5) = " << resultOfLengthInt << endl << endl;

    double resultOfCosineAngleInt(vec_a.cosineOfAngle(vec_b));
    cout << "Косинус между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = cos(" << resultOfCosineAngleInt << ')' << endl;
    cout << "Угол между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = " << acos(resultOfCosineAngleInt) << " градусов"
         << endl
         << endl;

    double resultOfCosineAnglewithZeroLengthInt(vec_c_int.cosineOfAngle(vec_d_int));
    cout << "Косинус между вектором vec_c(5, 7, 25) и vec_d(0, 0, 0) = cos(" << resultOfCosineAnglewithZeroLengthInt
         << ')' << endl;
    cout << "Угол между вектором vec_c(5, 7, 25) и vec_d(0, 0, 0) = " << acos(resultOfCosineAnglewithZeroLengthInt)
         << " градусов" << endl << endl;

    cout << "------------------Конец теста Vector3D_T с типом int------------------" << endl;


    cout << endl << "-----------------Начало теста Vector3D_T с типом float----------------" << endl;

    testParse<float>("{1.2, 3.4, 5.6}");
    testParse<float>("{9, 4,5, 8.2}");

    bool b_1_float = Vector3d_T<float>(3.1, 4.2, 7.9) == Vector3d_T<float>(3.1, 4.2, 7.9);
    cout << endl << "(3.1, 4.2, 7.9) == (3.1, 4.2, 7.9) = " << b_1_float << endl;

    bool b_2_float = Vector3d_T<float>(3.1, 4.2, 7.9) != Vector3d_T<float>(3.1, 4.2, 7.0);
    cout << "(3.1, 4.2, 7.9) != (3.1, 4.2, 7.0) = " << b_2 << b_2_float << endl << endl;

    Vector3d_T<float> vector3d_t_float(1.2, 3.4, 5.6);
    cout << "Исходный вектор: " << vector3d_t << endl;

    vector3d_t_float += Vector3d_T<float>(2.0, 1.1, 0.3);
    cout << "vector3d_t + (2.0, 1.1, 0.3) = " << vector3d_t << endl;

    vector3d_t_float -= Vector3d_T<float>(1.2, 3.8, 0.2);
    cout << "vector3d_t - (2.0, 1.1, 0.3) = " << vector3d_t << endl;

    vector3d_t_float *= 3.14;
    cout << "vector3d_t * 3.14 =" << vector3d_t << endl;

    vector3d_t_float /= 3.14;
    cout << "vector3d_t / 3.14 =" << vector3d_t << endl << endl;

    Vector3d_T<float> vec_a_float(3, 4, 5);
    Vector3d_T<float> vec_b_float(1, 2, 6);
    Vector3d_T<float> vec_c_float(5, 7.5, 25);
    Vector3d_T<float> vec_d_float(0, 0, 0);
    float number_float(2.5);

    cout << "Сумма вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a_float + vec_b_float << endl;
    cout << "Разность вектора (3, 4, 5) и вектора (1, 2, 6) = " << vec_a_float - vec_b_float << endl << endl;

    cout << "Произведение вектора (3, 4, 5) и числа 2.5 = " << vec_a_float * number_float << endl;
    cout << "Произведение числа 2.5 и вектора (3, 4, 5) = " << number_float * vec_a_float << endl << endl;

    cout << "Отношение вектора (5, 7.5, 25) и числа 2.5 = " << vec_c_float / number_float << endl;

    double vec_a_b_float(vec_a_float.scalarProduct(vec_b_float));
    cout << "Скалярное произведение vec_a(3, 4, 5) на vec_b(1, 2, 6) = " << vec_a_b_float << endl;

    double resultOfLengthFloat(vec_a_float.length());
    cout << "Длина вектора vec_a(3, 4, 5) = " << resultOfLengthFloat << endl << endl;

    double resultOfCosineAngleFloat(vec_a_float.cosineOfAngle(vec_b_float));
    cout << "Косинус между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = cos(" << resultOfCosineAngleFloat << ')' << endl;
    cout << "Угол между вектором vec_a(3, 4, 5) и vec_b(1, 2, 6) = " << acos(resultOfCosineAngleFloat) << " градусов"
         << endl
         << endl;

    double resultOfCosineAnglewithZeroLengthFloat(vec_c_float.cosineOfAngle(vec_d_float));
    cout << "Косинус между вектором vec_c(5, 7.5, 25) и vec_d(0, 0, 0) = cos(" << resultOfCosineAnglewithZeroLengthFloat
         << ')' << endl;
    cout << "Угол между вектором vec_c(5, 7.5, 25) и vec_d(0, 0, 0) = " << acos(resultOfCosineAnglewithZeroLengthFloat)
         << " градусов" << endl << endl;

    cout << "------------------Конец теста Vector3D_T с типом float------------------" << endl;

    return 0;
}