#include "stackr.h"
#include <iostream>

StackR::StackR()
        : size_{1}
        , pData_{new int[size_]}
{
}

StackR::StackR(const StackR& stackR)
{
    if (!stackR.isEmpty()) {

        pData_ = new int[stackR.size_];
        for (int i(0); i <= stackR.head_; i += 1) {
            pData_[i] = stackR.pData_[i];
        }
        head_ = stackR.head_;

    } else {
        delete[] pData_;
        head_ = -1;
    }
}

StackR::~StackR()
{
    delete[] pData_;
    pData_ = nullptr;
}

void StackR::push(const int& value)
{
    if (isEmpty()) {
        pData_ = new int[size_];
    }

    if (head_ == (size_ - 1)) {
        int* tempData = new int[size_+1];

        for (int i(0); i <= head_; i += 1) {
            tempData[i] = pData_[i];
        }

        delete[] pData_;
        pData_ = tempData;
        size_ += 1;
    }

    head_ += 1;
    pData_[head_] = value;
}

void StackR::pop()
{
    if ( !isEmpty() ) {
        head_ -= 1;
    } else {
        throw std::runtime_error("Can not do pop() no more");
    }
}

int& StackR::top()
{
    if (!isEmpty()) {
        return pData_[head_];
    } else {
        throw std::runtime_error("Can not do top() no more");
    }
}

const int& StackR::top() const
{
    if (!isEmpty()) {
        return pData_[head_];
    } else {
        throw std::runtime_error("Can not do top() no more");
    }
}

bool StackR::isEmpty() const
{
    pData_ == nullptr;
}

std::ostream& operator<<(std::ostream& ostrm, StackR& stackR)
{
    return stackR.writeTo(ostrm);
}

std::ostream& StackR::writeTo(std::ostream& ostrm)
{
    if (!isEmpty()) {
        for (int i(head_); i >= 0; i -= 1) {
            ostrm << pData_[i] << "  ";
        }
    }
    return ostrm;
}
