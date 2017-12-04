#include "array.h"
#include <iostream>
#include <sstream>

using  namespace std;

int main()
{
    Array array(3);

    cout << "Попытка задания размера массиву значения -3: " << endl;
    cout << "Array array(-3): " << endl;
    try {
        Array array(-3);
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl << endl;
    }

    array[0] = 1;
    array[1] = 10;
    array[2] = 12;

    const Array constArray(array);
    cout << "Доступ к элементу с индексом 2 константного массива, constArray[2]: " << constArray[2] << endl << endl;

    cout << "Попытка доступа к элементу массива с индексом -25: " << endl;
    cout << "array[-25] = 100: " << endl;
    try {
        array[-25] = 100;
    }
    catch (const invalid_argument& error) {
        cout << "  " << error.what() << endl << endl;
    }

    cout << "Попытка доступа к элементу массива с индексом 256: " << endl;
    cout << "array[256] = 100: " << endl;
    try {
        array[256] = 100;
    }
    catch (const invalid_argument& error) {
        cout << "  " << error.what() << endl << endl;
    }

    cout << "Исходный массив: " << array << endl << endl;
    array.insertLast(15);
    array.insertLast(17);
    array.insertLast(19);
    array.insertLast(21);

    array.insertFirst(25);
    array.insertFirst(29);

    cout << "Массив после добавления в конец последовательно 3-х элементов, затем в начало 2-х элементов: " << endl;
    cout << array << endl << endl;

    array.insertToIndex(31, 3);

    cout << "Добавление в массив значение 31 по индексу 3: " << endl;
    cout << array;
    cout << "->  Размер массива = " << array.count() << endl << endl;

    cout << "Попытка добавления в массив значение 512 по индексу 1024: " << endl;
    cout << "array[1024] = 512 " << endl;
    try {
        array[1024] = 512;
    }
    catch (const invalid_argument& error) {
        cout << "  " << error.what() << endl << endl;
    }

    array.removeFirst();
    cout << "Удаление из массива первого элемент: " << endl;
    cout << array << endl << endl;

    array.removeLast();
    cout << "Удаление из массива последнего элемент: " << endl;
    cout << array << endl << endl;

    array.removeAtIndex(4);
    cout << "Удаление из массива элемента с индексом 4: " << endl;
    cout << array << endl << endl;

    cout << "Попытка удаления из массива элемента с индексом 89: " << endl;
    cout << "array.removeAtIndex(89): " << endl;
    try {
        array.removeAtIndex(89);
    }
    catch (const invalid_argument& error) {
        cout << "  " << error.what() << endl << endl;
    }

    cout << "Попытка удаления из массива элемента с индексом -13: " << endl;
    cout << "array.removeAtIndex(-13): " << endl;
    try {
        array.removeAtIndex(-13);
    }
    catch (const invalid_argument& error) {
        cout << "  " << error.what() << endl << endl;
    }

    cout << "Перестановка элементов array[1] и array[5]: " << endl;
    array.reshuffleOfElements(1, 5);
    cout << array << endl << endl;

    cout << "Попытка перестановки элементов array[-1] и array[99]: " << endl;
    cout << "array.removeAtIndex(-13): " << endl;
    try {
        array.reshuffleOfElements(-1, 99);
    }
    catch (const invalid_argument& error) {
        cout << "  " << error.what() << endl << endl;
    }

    cout << "Умолчательная сортировка массива по возрастанию: " << endl;
    array.sort();
    cout << array << endl << endl;

    cout << "Выбор сортировки массива по убыванию: " << endl;
    array.sort(DOWN);
    cout << array << endl << endl;

    cout << "Выбор сортировки массива по возрастанию : " << endl;
    array.sort(UP);
    cout << array << endl << endl;

    cout << "Проверка массива array на пустоту: " << array.isEmpty() << endl << endl;

    array.resize(15);
    cout << "Новый размер массива resize(15): " << endl;
    cout << array << endl;
    cout << " Размер массива = " << array.count() << endl << endl;

    array.resize(5);
    cout << "Новый размер массива resize(5): " << endl;
    cout << array << endl;
    cout << " Размер массива = " << array.count() << endl;

    return 0;
}