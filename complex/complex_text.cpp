#include "complex.h"
#include <iostream>
#include <sstream>

using namespace std;

bool testParse(const std::string& str) {
    istringstream istrm(str);
    Complex complex;
    istrm >> complex;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << complex << endl;
    }
    else {
        cout << "Read error: " << str << " -> " << complex << endl;
    }
    return istrm.good();
}

int main() {
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");

    Complex complex(0.0, 0);
    cout << endl << "Исходное комплексное число: " << complex << endl << endl;

    Complex z_2(5, 8);
    bool b_1 = complex == z_2;
    cout << "(5 + 8*i) == (5 + 8*i) = " << (bool)b_1 << endl;

    Complex z_3(3, 5);
    bool b_2 = complex != z_3;
    cout << "(5 + 8*i) != (2 + 8*i) = "<< (bool)b_2 << endl << endl;

    complex += Complex(9.0, 2);
    cout << "complex + (9.0 +2*i) = " << complex << endl;

    complex -= Complex(12.0, 2);
    cout << "complex - (12.0 + 2*i) = " << complex << endl;

    complex *= 3.0;
    cout << "complex * 3.0 = " << complex << endl;

    complex *= Complex(4.0, 6);
    cout << "complex * (4.0 + 6*i) = " << complex << endl;

    complex /= 2.0;
    cout << "complex / 2.0 = " << complex << endl;

    complex /= Complex(3.0, 3);
    cout << "complex / (3.0 + 3*i) = "<< complex << endl;

    cout << endl;

    complex += 12.0;
    cout << "complex + 12.0 = " << complex << endl;

    complex -= 11.0;
    cout << "complex - 11.0 = " << complex << endl;

    complex += 5;
    cout << "complex + 5 = " << complex << endl;

    complex -= 4;
    cout << "complex - 4 = " << complex << endl;

    complex *= 7;
    cout << "complex * 7 = " << complex << endl;

    complex /= 2;
    cout << "complex / 2 = " << complex << endl;

    complex += Complex(12);
    cout << "12 + complex = " << complex << endl;

    complex += Complex(3.14);
    cout << "3.14 + complex = " << complex << endl;

    complex += Complex(-1);
    cout << "(-1) + complex = " << complex << endl;

    complex += Complex(-9.8);
    cout << "(-9.8) + complex = " << complex << endl << endl;

    Complex complex1(3.8, 2.1);
    Complex complex2(12.0, 5.5);
    double number(3.5);

    cout << "Сумма complex1(3.8, 2.1) и complex2(12.0, 5.5) = " << complex1 + complex2 << endl;
    cout << "Сумма complex1(3.8, 2.1) и number(3.5) = " << complex1 + number << endl;
    cout << "Сумма number(3.5) и complex1(3.8, 2.1) = " << number + complex1 << endl << endl;

    cout << "Разность complex1(3.8, 2.1) и complex2(12.0, 5.5) = " << complex1 - complex2 << endl;
    cout << "Разность complex1(3.8, 2.1) и number(3.5) = " << complex1 - number << endl;
    cout << "Разность number(3.5) и complex1(3.8, 2.1) = " << number - complex1 << endl << endl;

   // cout << "Произведение complex1(3.8, 2.1) и complex2(12.0, 5.5) = " << complex1 * complex2 << endl;
    cout << "Произведение complex1(3.8, 2.1) и 3.5 = " << complex1 * number << endl;
    cout << "Произведение 3.5 и complex1(3.8, 2.1) = " << number * complex1 << endl << endl;

    cout << "Сопряженное комплексное число к complex2(12.0, 5.5) = " << complex2.conjugateNumber() << endl << endl;

    return 0;
}