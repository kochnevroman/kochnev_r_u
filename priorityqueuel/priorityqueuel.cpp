#include "priorityqueuel.h"
#include <iostream>

PriorityQueueL::PriorityQueueL(const PriorityQueueL& priorityQueueL)
{
        Node* node = priorityQueueL.pHead_;

        while (node != nullptr) {
            push(node -> data_);
            node = node -> pNext_;
        }
}

PriorityQueueL::~PriorityQueueL()
{
    while( !isEmpty() ) {
        pop();
    }
    pTail_ = nullptr;
}

PriorityQueueL::Node::Node(Node* pNext, const int &value)
        : pNext_(pNext)
        , data_(value)
{
}

PriorityQueueL& PriorityQueueL::operator=(const PriorityQueueL& priorityQueueL)
{
    Node* node = priorityQueueL.pHead_;
    while (node != nullptr) {
        push(node -> data_);
        node = node -> pNext_;
    }
}

void PriorityQueueL::push(const int& value)
{
    Node* node = new Node(nullptr, value);

    if ( !isEmpty() ) {

        pTail_ -> pNext_ = node;
        pTail_ = pTail_ -> pNext_;

    } else {
        pTail_ = node;
        pHead_ = pTail_;
    }
}

void PriorityQueueL::pop()
{
    if ( !isEmpty() )
    {
        Node* pDeleted(pHead_);
        pHead_ = pDeleted -> pNext_;
        delete pDeleted;
    } else {
        throw std::runtime_error("Can not do pop() no more");
    }
}

int& PriorityQueueL::top()
{
    if ( !isEmpty() ) {
        return pHead_ -> data_;
    } else {
        throw std::runtime_error("Can not do top() no more");
    }
}

const int& PriorityQueueL::top() const
{
    if ( !isEmpty() ) {
        return pHead_ -> data_;
    } else {
        throw std::runtime_error("Can not do top() no more");
    }
}

bool PriorityQueueL::isEmpty() const
{
    return  pHead_ == nullptr;
}

std::ostream& operator<<(std::ostream& ostrm, PriorityQueueL& priorityQueueL)
{
    return priorityQueueL.writeTo(ostrm);
}

std::ostream& PriorityQueueL::writeTo(std::ostream& ostrm)
{
    if ( !isEmpty() ) {
        PriorityQueueL priorityQueueL(*this);

        while ( !priorityQueueL.isEmpty() ) {

            ostrm << priorityQueueL.top() << "  ";
            priorityQueueL.pop();
        }
    }
    return ostrm;
}
