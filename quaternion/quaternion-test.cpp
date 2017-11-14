#include "quaternion.h"
#include <iostream>
#include <sstream>

using namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Quaternion quaternion;
    istrm >> quaternion;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << quaternion << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << quaternion << endl;
    }
    return istrm.good();
}

int main()
{

    bool b_1 = Quaternion(3.1, 4.2, 7.9, 5.8) == Quaternion(3.1, 4.2, 7.9, 5.8);
    cout << "(3.1, 4.2, 7.9, 5.8) == (3.1, 4.2, 7.9, 5.8) = " << b_1 << endl;

    bool b_2 = Quaternion(3.1, 4.2, 7.9, 5.8) != Quaternion(3.1, 4.2, 7.0, 5.8);
    cout << "(3.1, 4.2, 7.9, 5.8) != (3.1, 4.2, 7.0) = " << b_2 << endl << endl;

    Quaternion quaternion(1.2, 3.4, 5.6, 1.3);
    cout << "Исходный кватернион: " << quaternion << endl << endl;

    quaternion += Quaternion(2.0, 1.1, 0.3, 0.7);
    cout << "quaternion + (2.0, 1.1, 0.3, 0.7) = " << quaternion << endl;

    quaternion -= Quaternion(2.0, 1.1, 0.3, 0.7);
    cout << "quaternion - (2.0, 1.1, 0.3, 0.7) = " << quaternion << endl;

    quaternion *= 3.14;
    cout << "quaternion * 3.14 =" << quaternion << endl << endl;

    Quaternion quaternion1(3, 4, 7, 12);
    Quaternion quaternion2(1, 2, 6, 9);

    Quaternion sumOperation = quaternion1 + quaternion2;
    cout << "Сумма кватерниона (3, 4, 7, 12) и кватерниона (1, 2, 6, 9) = " << sumOperation << endl;

    Quaternion subOperation = quaternion1 - quaternion2;
    cout << "Разность кватерниона (3, 4, 7, 12) и кватерниона (1, 2, 6, 9) = " << subOperation << endl;

    Quaternion multiOperation = quaternion1 * quaternion2;
    cout << "Умножение кватерниона (3, 4, 7, 11) и кватерниона (1, 2, 6, 9) = " << multiOperation << endl << endl;

    cout << "Сопряженный кватернион кватерниону (3, 4, 7, 12) = " << quaternion1.conjugating() << endl;

    cout << "Модуль кватерниона (3, 4, 7, 12) = " << quaternion1.module() << endl;

    cout << "Определитель матричного представления кватерниона (3, 4, 7, 12) = " << quaternion1.det() << endl << endl;

    testParse("{1.2, 3.4, 5.6, 7,9}");
    testParse("{9, 4.5, 8.2, 7}");

    return  0;
}
