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
    AB.addFirst(-6);
    AB.addFirst(9);
    AB.addFirst(0);
    AB.addFirst(1);
    AB.addFirst(0);
    AB.addLast(1);
    cout << AB;
    int t = 5;
    cin >> t;

    return 0;
}