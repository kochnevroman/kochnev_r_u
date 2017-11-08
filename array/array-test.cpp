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