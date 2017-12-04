#include "stackr.h"
#include <iostream>

using namespace std;

int main()
{
    StackR stackR;
    
    stackR.push(1);
    stackR.push(5);
    stackR.push(15);
    stackR.push(50);
    stackR.push(-50);
    stackR.push(0);
    stackR.push(75);
    stackR.push(125);

    cout << "Исходный стек: " << endl;
    cout << stackR << endl << endl;

    cout << "Проверка стека на пустоту: ";
    cout << stackR.isEmpty() << endl << endl;

    stackR.pop();
    cout << "Стек после операции pop(): " << endl;
    cout << stackR << endl << endl;

    cout << "Смотрим, что лежит на верхушке стека, top(): " << endl;
    cout << stackR.top() << endl << endl;

    stackR.top() = 1024;
    cout << "Присвоим верхушке значение 1024: " << endl;
    cout << stackR << endl << endl;

    const StackR stackRConst(stackR);
    cout << "Головной элемент константного стека, top(): " << endl;
    cout << stackRConst.top() << endl << endl;

    stackR.pop();
    stackR.pop();
    stackR.pop();
    stackR.pop();

    cout << "Стек после 4 операций pop(): " << endl;
    cout << stackR << endl << endl;

    stackR.pop();
    stackR.pop();
    stackR.pop();

    cout << "Проверка стека на пустоту после еще 3 операций pop(): ";
    cout << stackR.isEmpty() << endl << endl;

    cout << "Попытка выполнения pop() с пустым стеком: " << endl;
    cout << "stackR.pop(): " << endl;

    try {
        stackR.pop();
    }
    catch (const runtime_error& error) {
        cout << "  " << error.what() << endl;
    }
    
    return 0;
}
