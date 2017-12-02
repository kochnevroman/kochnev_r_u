#include "priorityqueuel.h"
#include <iostream>

PriorityQueueL::PriorityQueueL(const PriorityQueueL& priorityQueueL)
{
    if ( !priorityQueueL.isEmpty() ) {

        Node* node = priorityQueueL.pHead_;

        while (node != nullptr) {
            push(node -> data_);
            node = node -> pNext_;
        }
    }
}

PriorityQueueL::~PriorityQueueL()
{
    while( !isEmpty() ) {
        pop();
    }
    pHead_ = nullptr;
}

PriorityQueueL::Node::Node(Node* pNext, const int &value)
        : pNext_(pNext)
        , data_(value)
{
}

PriorityQueueL& PriorityQueueL::operator=(const PriorityQueueL& priorityQueueL)
{
}

void PriorityQueueL::push(const int& value)
{
    if ( !isEmpty() ) {

        pHead_ -> pNext_ = new Node(nullptr, value);
        pHead_ = pHead_ -> pNext_;

    } else {
        pHead_ = new Node(nullptr, value);
        pTail_ = pHead_;
    }
}

void PriorityQueueL::pop()
{
    if ( !isEmpty() )
    {
        Node* pDeleted(pTail_);
        pTail_ = pTail_ -> pNext_;
        delete pDeleted;
    } else {
        throw std::invalid_argument("Can not do pop() no more");
    }
}

int& PriorityQueueL::top()
{
    if ( !isEmpty() ) {
        return pHead_ -> data_;
    } else {
        throw std::invalid_argument("Can not do top() no more");
    }
}

const int& PriorityQueueL::top() const
{
    if ( !isEmpty() ) {
        return pHead_ -> data_;
    } else {
        throw std::invalid_argument("Can not do top() no more");
    }
}

bool PriorityQueueL::isEmpty() const
{
    return  pTail_ == nullptr;
}

std::ostream& operator<<(std::ostream& ostrm, PriorityQueueL& priorityQueueL)
{
    return priorityQueueL.writeTo(ostrm);
}

std::ostream& PriorityQueueL::writeTo(std::ostream &ostrm)
{
    if ( !isEmpty() ) {
        PriorityQueueL priorityQueueL(*this);

        while ( !priorityQueueL.isEmpty() ) {

            ostrm << priorityQueueL.top() << std::endl;
            priorityQueueL.pop();
        }
    }
    return ostrm;
}
