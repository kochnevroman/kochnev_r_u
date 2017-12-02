#include "priorityqueuel.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    PriorityQueueL priorityQueueL;

    priorityQueueL.push(1);
    priorityQueueL.push(5);
    priorityQueueL.push(15);
    priorityQueueL.push(50);
    priorityQueueL.push(-50);
    priorityQueueL.push(0);
    priorityQueueL.push(75);
    priorityQueueL.push(125);

    cout << "Исходная очередь: " << endl;
    cout << priorityQueueL << endl << endl;

    cout << "Проверка очереди на пустоту: ";
    cout << priorityQueueL.isEmpty() << endl << endl;

    priorityQueueL.pop();
    cout << "Очередь после операции pop(): " << endl;
    cout << priorityQueueL << endl << endl;

    cout << "Головной элемент очереди, top(): " << endl;
    cout << priorityQueueL.top() << endl << endl;

    priorityQueueL.top() = 4096;
    cout << "Присвоим головному элементу значение 4096: " << endl;
    cout << priorityQueueL << endl << endl;

    priorityQueueL.pop();
    priorityQueueL.pop();
    priorityQueueL.pop();
    priorityQueueL.pop();
    priorityQueueL.pop();
    priorityQueueL.pop();
    priorityQueueL.pop();

    cout << "Проверка очереди на пустоту: ";
    cout << priorityQueueL.isEmpty() << endl << endl;

    cout << "Попытка выполнения pop() с пустой очередью: " << endl;
    cout << "priorityQueueL.pop(): " << endl;

    try {
        priorityQueueL.pop();
    }
    catch (invalid_argument& e) {
        cout << "  " << e.what() << endl;
    }

    return 0;
}

