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

    cout << "Массив после добавления в конец последовательно 3-х элементов, потом в начало 2-х элементов: " << endl;
    cout << array << endl << endl;

    array.addToIndex(3, 31);

    cout << "Добавление в массив значение 31 по индексу 3: " << endl;
    cout << array;

    cout << " -> Размер массива = " << array.count() << endl << endl;

    array.removeFirst();
    cout << "Удаление из массива первого элемент: " << endl;
    cout << array << endl << endl;

    array.removeLast();
    cout << "Удаление из массива последнего элемент: " << endl;
    cout << array << endl << endl;

    array.removeAtIndex(4);
    cout << "Удаление из массива элемента с индексом 4: " << endl;
    cout << array << endl << endl;

    array.removeAtIndex(89);
    cout << "Удаление из массива элемента с индексом 89: " << endl;
    cout << array << endl << endl;

    array.removeAtIndex(-13);
    cout << "Удаление из массива элемента с индексом -13: " << endl;
    cout << array << endl << endl;

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

    cout << "Проверка массива array на пустоту: " << array.isEmpty() << endl << endl;

    //добавить тест resize()
    array.resize(15);
    cout << "Новый размер массива resize(15): " << endl;
    cout << " Размер массива = " << array.count() << endl << endl;

    array.resize(5);
    cout << "Новый размер массива resize(5): " << endl;
    cout << " Размер массива = " << array.count() << endl << endl;

    return 0;
}