#include "array.h"
#include <iostream>
#include <sstream>

using  namespace std;

int main()
{
    Array array(3);
    array[0] = 1;
    array[1] = 10;
    array[2] = 12;

    cout << "Исходный массив: " << array << endl << endl;

    array.addLast(15);
    array.addLast(17);
    array.addLast(19);
    array.addLast(21);
    array.addFirst(25);
    array.addFirst(29);
    //array.resize(5);
    //array.addToIndex(3, 31);

    //добавить тест resize()

    Array testMassive2(array);
    cout << testMassive2 << endl;

    cout << array.capacity() << endl;
    cout << array.count() << endl << endl;

    array.removeFirst();
    cout << array << endl;

    cout << array.capacity() << endl;
    cout << array.count() << endl << endl;

    array.removeLast();
    cout << array << endl;

    cout << array.capacity() << endl;
    cout << array.count() << endl << endl;

    array.removeAtIndex(4);
    cout << array << endl;

    cout << array.capacity() << endl;
    cout << array.count() << endl << endl;

    cout << "Перестановка элементов array[1] и array[5]: " << endl;
    array.reshuffleOfElements(1, 5);
    cout << array << endl << endl;

    cout << "Умолчательная сортировка массива по возрастанию: " << endl;
    array.sort();
    cout << array << endl << endl;

    cout << "Выбор сортировки массива по убыванию: " << endl;
    array.sort(DOWN);
    cout << array << endl << endl;

    cout << "Выбор сортировки массива по возрастанию: " << endl;
    array.sort(UP);
    cout << array << endl << endl;

    cout << "Проверка массива array на пустоту: " << array.isEmpty() << endl;

    return 0;
}