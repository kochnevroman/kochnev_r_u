#pragma once
#ifndef STACKL_STACK_H
#define STACKL_STACK_H

#include <iosfwd>

class StackL
{
public:
    StackL() = default;
    explicit StackL(const StackL& stackL);

    ~StackL();

    StackL& operator=(const StackL& stackL);

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
};

std::ostream& operator<<(std::ostream& ostrm, StackL& stackL);

#endif //STACKL_STACK_H
