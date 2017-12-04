#include "complex.h"
#include <iostream>
#include <sstream>

using namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Complex complex;
    istrm >> complex;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << complex << endl;
    } else {
        cout << "Read error: " << str << " -> " << complex << endl;
    }
    return istrm.good();
}

int main()
{
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");

    Complex complex(12, 6);
    cout << endl << "Исходное комплексное число: " << complex << endl << endl;

    Complex complex2(5, 8);
    bool b_1 = complex2 == complex2;
    cout << "(5 + 8*i) == (5 + 8*i) = " << b_1 << endl;

    Complex complex3(3, 5);
    bool b_2 = complex3 != complex3;
    cout << "(5 + 8*i) != (2 + 8*i) = "<< b_2 << endl << endl;

    complex += Complex(9.0, 2);
    cout << "complex + (9.0 +2*i) = " << complex << endl;

    complex += 12.0;
    cout << "complex + 12.0 = " << complex << endl;

    complex -= Complex(12.0, 2);
    cout << "complex - (12.0 + 2*i) = " << complex << endl;

    complex -= 3.0;
    cout << "complex - 11.0 = " << complex << endl;

    complex *= Complex(4.0, 6);
    cout << "complex * (4.0 + 6*i) = " << complex << endl;

    complex *= 3.0;
    cout << "complex * 3.0 = " << complex << endl;

    complex /= Complex(3.0, 3);
    cout << "complex / (3.0 + 3*i) = "<< complex << endl;

    complex /= 2.0;
    cout << "complex / 2.0 = " << complex << endl;

    cout << endl;

    Complex firstComplex(3.8, 2.1);
    Complex secondComplex(12.0, 5.5);
    double number(3.5);

    cout << "Сумма firstComplex (3.8, 2.1) и secondComplex (12.0, 5.5) = " << firstComplex + secondComplex << endl;
    cout << "Сумма firstComplex (3.8, 2.1) и number(3.5) = " << firstComplex + number << endl;
    cout << "Сумма number(3.5) и firstComplex (3.8, 2.1) = " << number + firstComplex << endl << endl;

    cout << "Разность complex1(3.8, 2.1) и secondComplex (12.0, 5.5) = " << firstComplex - secondComplex << endl;
    cout << "Разность complex1(3.8, 2.1) и number(3.5) = " << firstComplex - number << endl;
    cout << "Разность number(3.5) и firstComplex (3.8, 2.1) = " << number - firstComplex << endl << endl;

    cout << "Произведение firstComplex (3.8, 2.1) и secondComplex (12.0, 5.5) = " << firstComplex * secondComplex << endl;
    cout << "Произведение firstComplex (3.8, 2.1) и 3.5 = " << firstComplex * number << endl;
    cout << "Произведение 3.5 и firstComplex (3.8, 2.1) = " << number * firstComplex << endl << endl;

    cout << "Частное комплексных чисел complex(-2,1) и complex(1,-1) = " << Complex(-2, 1) / Complex(1, -1) << endl;
    cout << "Частное firstComplex (3.8, 2.1) и 3.5 = " << firstComplex / number << endl;
    cout << "Частное 3.5 и firstComplex (3.8, 2.1) = " << number / firstComplex << endl << endl;

    cout << "Сопряженное комплексное число к secondComplex(12.0, 5.5) = " << secondComplex.conjugateNumber() << endl;

    return 0;
}