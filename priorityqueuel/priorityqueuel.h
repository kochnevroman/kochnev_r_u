#pragma once
#ifndef PRIORITYQUEUEL_PRIORITYQUEUEL_H
#define PRIORITYQUEUEL_PRIORITYQUEUEL_H

#include <iosfwd>

class PriorityQueueL
{
public:
    PriorityQueueL() = default;
    explicit PriorityQueueL(const PriorityQueueL& priorityQueueL);

    ~PriorityQueueL();

    PriorityQueueL&operator=(const PriorityQueueL& priorityQueueL);

    void push(const int& value);

    void pop();

    int& top();
    const int& top() const;

    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm);

private:
    struct Node
    {
        Node(Node* pNext, const int& value);
        Node* pNext_{ nullptr };
        int data_{ int(0) };
    };

    Node* pHead_{ nullptr };
    Node* pTail_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, PriorityQueueL& priorityQueueL);

#endif //PRIORITYQUEUEL_PRIORITYQUEUEL_H