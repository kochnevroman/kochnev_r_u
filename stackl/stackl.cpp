#include "stackl.h"
#include <iostream>


StackL::StackL(const StackL& stackL)
{
    StackL temporaryStackL;
    Node* node = stackL.pHead_;

    while (node != nullptr) {
        temporaryStackL.push(node -> data_);
        node = node -> pNext_;
    }

    node = temporaryStackL.pHead_;

    while (node != nullptr) {
        push(node -> data_);
        node = node -> pNext_;
    }
}

StackL::~StackL()
{
    while ( !isEmpty() ) {
        pop();
    }
    pHead_ = nullptr;
}

StackL::Node::Node(Node* pNext, const int& value)
        : pNext_(pNext)
        , data_(value)
{
}

StackL& StackL::operator=(const StackL& stackL)
{
    StackL temporaryStackL;
    Node* node(stackL.pHead_);

    while (node != nullptr) {
        temporaryStackL.push(node -> data_);
        node = node -> pNext_;
    }
    while (!temporaryStackL.isEmpty()) {
        push(temporaryStackL.top());
        temporaryStackL.pop();
    }

    return *this;
}

void StackL::push(const int& value)
{
    pHead_ = new Node(pHead_, value);
}

void StackL::pop()
{
    if ( !isEmpty() ) {
        Node* pDelete(pHead_);
        pHead_ = pDelete -> pNext_;
        delete pDelete;
    } else {
        throw std::runtime_error("Can not do pop() no more");
    }
}

int& StackL::top()
{
    if ( !isEmpty() ) {
        return  pHead_ -> data_;
    } else {
        throw std::runtime_error("Can not do top() no more");
    }
}

const int& StackL::top() const
{
    if ( !isEmpty() ) {
        return pHead_ -> data_;
    } else {
        throw std::runtime_error("Can not do top() no more");
    }
}

bool StackL::isEmpty() const
{
    return pHead_ == nullptr;
}

std::ostream& operator<<(std::ostream& ostrm, StackL& stackL)
{
    return stackL.writeTo(ostrm);
}

std::ostream& StackL::writeTo(std::ostream& ostrm)
{
    StackL stackL(*this);
        while (!stackL.isEmpty()) {
            ostrm << stackL.top() << " ";
            stackL.pop();
        }
    return ostrm;
}