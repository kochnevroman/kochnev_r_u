#include "array.h"
#include <iostream>
#include <sstream>

using  namespace std;

int main()
{
    Array array(3);
    //array[0] = 1;
    //array[1] = 10;
    //array[2] = 100;
    array.addLast(5);
    array.addLast(4);
    array.addLast(110);
    array.addLast(90);
    array.resize(5);



    Array testMassive2(array);
    cout << array << endl;

    cout << array.capacity() << endl;
    cout << array.count() << endl;

    array.sort();
    cout << array << endl;

    array.sort(DOWN);
    cout << array << endl;

    array.sort(UP);
    cout << array << endl;


    cout << array.isEmpty() << endl;

    return 0;
}