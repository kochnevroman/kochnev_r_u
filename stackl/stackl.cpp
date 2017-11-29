#include "stackl.h"
#include <iostream>


StackL::StackL(const StackL& stackL)
{

}

StackL::~StackL()
{
    while (!isEmpty()) {
        pop();
    }
}

StackL::Node::Node(Node *pNext, const int& value)
        : pNext_(pNext)
        , data_(value)
{
}

StackL& StackL::operator=(const StackL& stackL)
{

}

void StackL::push(const int& value)
{
    pHead_ = new Node(pHead_, value);
}

void StackL::pop()
{

}

int& StackL::top()
{

}

const int& StackL::top() const
{

}

bool StackL::isEmpty() const
{
    return pHead_ == nullptr;
}

std::ostream& StackL::writeTo(std::ostream& ostrm)
{
    StackL stackL(*this);
        while (!stackL.isEmpty()) {
            ostrm << stackL.top() << std::endl;
            stackL.pop();
        }
    return ostrm;
}