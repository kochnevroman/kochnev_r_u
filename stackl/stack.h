#pragma once
#ifndef STACKL_STACK_H
#define STACKL_STACK_H

#include <iosfwd>

class StackL
{
public:
    StackL() = default;
    StackL(const StackL& rhs);
    ]
    ~StackL();

    StackL& operator=(const StackL& rhs);

    void push(const int& v);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;

private:
    struct Node
    {
        Node* pNext_{ nullptr };
        int data_{ int(0) };
    };

    Node* pHead_{ nullptr };
};

#endif //STACKL_STACK_H
