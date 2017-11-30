#include "priorityqueuel.h"
#include <iostream>

PriorityQueueL::PriorityQueueL(const PriorityQueueL &priorityQueueL)
{

}

PriorityQueueL::~PriorityQueueL()
{
    while( !isEmpty() ) {
        pop();
    }
}

PriorityQueueL& PriorityQueueL::operator=(const PriorityQueueL &priorityQueueL)
{

}

void PriorityQueueL::push(const int &value)
{

}

void PriorityQueueL::pop()
{

}

int& PriorityQueueL::top()
{

}

const int& PriorityQueueL::top() const
{

}

bool PriorityQueueL::isEmpty() const
{
    return  pTail_ == nullptr;
}

inline std::ostream& operator<<(std::ostream& ostrm, PriorityQueueL& priorityQueueL)
{
    return  priorityQueueL.writeTo(ostrm);
}

std::ostream& PriorityQueueL::writeTo(std::ostream &ostrm)
{

}
