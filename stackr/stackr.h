#pragma once
#ifndef STACKR_STACKR_H
#define STACKR_STACKR_H

#include <iosfwd>
#include <cstddef>

class StackR
{
public:
    StackR();
    explicit StackR(const StackR& stackR);

    ~StackR();

    void push(const int& value);

    void pop();

    int& top();
    const int& top() const;

    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm);

private:
    int* pData_{ nullptr };
    ptrdiff_t size_{ 1 };
    ptrdiff_t head_{ 0 };

};

std::ostream& operator<<(std::ostream& ostrm, StackR& stackR);

#endif //STACKR_STACKR_H
