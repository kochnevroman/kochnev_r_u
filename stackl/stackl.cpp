#include "stackl.h"
#include <iostream>


StackL::StackL(const StackL& stackL)
{
    StackL temporaryStackL;
    Node* temporaryNode = stackL.pHead_;

    while (temporaryNode != nullptr) {
        temporaryStackL.push(temporaryNode -> data_);
        temporaryNode = temporaryNode -> pNext_;
    }
    temporaryNode = temporaryStackL.pHead_;
    while (temporaryNode != nullptr) {
        push(temporaryNode -> data_);
        temporaryNode = temporaryNode -> pNext_;
    }
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
    StackL temporaryStackL;
    Node* temporaryNode(stackL.pHead_);

    while (temporaryNode != nullptr) {
        temporaryStackL.push(temporaryNode -> data_);
        temporaryNode = temporaryNode -> pNext_;
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
    if (!isEmpty()) {
        Node* pDelete(pHead_);
        pHead_ = pDelete -> pNext_;
        delete pDelete;
    } else {
        throw std::invalid_argument("Can not do top() no more");
    }
}

int& StackL::top()
{
    if (!isEmpty()) {
        return  pHead_ -> data_;
    }
}

const int& StackL::top() const
{
    if (!isEmpty()) {
        return pHead_->data_;
    } else {
        throw std::invalid_argument("Can not do top() no more");
    }
}

bool StackL::isEmpty() const
{
    return pHead_ == nullptr;
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