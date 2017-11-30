#include "stackl.h"
#include <iostream>

using namespace std;

int main()
{
    StackL stackL;

    stackL.push(1);
    stackL.push(5);
    stackL.push(15);
    stackL.push(50);
    stackL.push(-50);
    stackL.push(0);
    stackL.push(75);
    stackL.push(125);

    cout << "Исходный стек: " << endl;
    cout << stackL << endl << endl;

    cout << "Проверка стека на пустоту: ";
    cout << stackL.isEmpty() << endl << endl;

    stackL.pop();
    cout << "Стек после операции pop(): " << endl;
    cout << stackL << endl << endl;

    cout << "Смотрим, что лежит на верхушке стека, top(): " << endl;
    cout << stackL.top() << endl << endl;

    stackL.top() = 1024;
    cout << "Присвоим верхушке значение 1024: " << endl;
    cout << stackL << endl << endl;

    stackL.pop();
    stackL.pop();
    stackL.pop();
    stackL.pop();
    stackL.pop();
    stackL.pop();
    stackL.pop();

    cout << "Проверка стека на пустоту: ";
    cout << stackL.isEmpty() << endl << endl;

    cout << "Попытка выполнения pop() с пустым стеком: " << endl;
    cout << "stackL.pop(): " << endl;

    try {
        stackL.pop();
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl;
    }

    return 0;
}
