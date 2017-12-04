#include "stackr.h"
#include <iostream>

StackR::StackR(const StackR &stackR)
{

}

StackR::~StackR()
{

}

void StackR::push(const int &value)
{

}

void StackR::pop()
{

}

int& StackR::top()
{

}

const int& StackR::top() const
{

}

bool StackR::isEmpty() const
{
    return 0;
}

inline std::ostream& operator<<(std::ostream& ostrm, StackR& stackR)
{
    return stackR.writeTo(ostrm);
}

std::ostream& StackR::writeTo(std::ostream &ostrm)
{
    StackR stackR(*this);
    while (!stackR.isEmpty()) {
        ostrm << stackR.top() << " ";
        stackR.pop();
    }
    return ostrm;
}
