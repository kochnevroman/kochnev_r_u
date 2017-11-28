#include "rational.h"
#include <iostream>
#include <sstream>

using  namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Rational rational;
    istrm >> rational;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << rational << endl;
    } else {
        cout << "Read error: " << str << " -> " << rational << endl;
    }
    return istrm.good();
}

int main()
{
    testParse("{12/13}");
    testParse("{7/ 11}");
    testParse("{4/ 3");

    Rational rational(3, 4);
    cout << endl << "Исходное рациональное число: " << rational << endl << endl;

    cout << "Попытка задать знаменателю значение 0: " << endl;
    try {
        Rational testRational(3, 0);
    }
    catch (invalid_argument &e) {
        cout << e.what() << endl << endl;
    }

    rational += Rational(1, 4);
    cout << "rational += Rational (1/4) = " << rational << endl;

    rational -= Rational(3, 4);
    cout << "rational -= 3/4 = " << rational << endl;

    rational *= Rational(1, 3);
    cout << "rational *= 1/3 = " << rational << endl;

    rational /= Rational(3);
    cout << "rational /= 3 = " << rational << endl;

    rational += Rational(35, 36);
    cout << "rational + 35/36 =" << rational << endl << endl;

    Rational rational1(3, 4);
    Rational rational2(1, 2);

    cout << "Сумма rational1 (3, 4) и rational2 (1, 2) = " << rational1 + rational2 << endl;
    cout << "Разность rational1 (3, 4) и rational2 (1, 2) = " << rational1 - rational2 << endl;
    cout << "Произведение rational1 (3, 4) и rational2 (1, 2) = " << rational1 * rational2 << endl;
    cout << "Отношение (3, 4) и rational2 (1, 2) = " << rational1 / rational2 << endl << endl;

    Rational rational3(5, 8);
    Rational rational4(3, 8);

    cout << "Сумма rational3 (5, 8) и rational4 (3, 8) = " << rational3 + rational4 << endl;

    return 0;
}
