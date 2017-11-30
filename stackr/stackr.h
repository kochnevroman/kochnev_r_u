#pragma once
#ifndef STACKR_STACKR_H
#define STACKR_STACKR_H

#include <iosfwd>

class StackR
{
public:
    StackR() = default;
    explicit StackR(const StackR& stackR);

    ~StackR();

    void push(const int& value);

    void pop();

    int& top();
    const int& top() const;

    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm);

private:
// some some sad or not, let it know...
};

inline std::ostream& operator<<(std::ostream& ostrm, StackR& stackR);

#endif //STACKR_STACKR_H
