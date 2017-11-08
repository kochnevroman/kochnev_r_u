//
// Created by Roman Kochnev on 25.10.2017.
//

#include "array.h"
#include <iostream>

int& Array::operator[](const ptrdiff_t index)
{
    return pdata[index];
}

const int & Array::operator[](const ptrdiff_t index) const
{
    return pdata[index];
}

Array & Array::operator=(const Array & array)
{
    if (pdata == array.pdata && array.size_ == size_ && array.length == length)
    {
        return *this;
    }
    pdata = new int[array.size_];
    for (ptrdiff_t i(0); i < array.length_; i++)
    {
        pdata[i] = array[i];
    }
    size_ = array.size_;
    length_ = array.length_;
    return *this;
}

void Array::resize(const int& newArraySize)
{
    if (length_ < newArraySize) {
        int *newarr = new int[newArraySize];

        for (ptrdiff_t i(0); i < length_; i++) {
            newarr[i] = pdata[i];
        }

        delete[] pdata;
        pdata = newarr;
        size_ = newArraySize;
    }
    else {
        int *newarr = new int[newArraySize];
        for (ptrdiff_t i(0); i < newArraySize; i++) {
            newarr[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newarr;
        size_ = newArraySize;
        length_ = newArraySize;
    }
}

void Array::append(const int &newElement)
{
    if (length_ < size_) {
        pdata[length_++] = newElement;
    }
    else {
        resize(size_ * 2);
        pdata[length_++] = newElement;
    }
}

std::ostream& Array::writeTo(std::ostream& ostrm)
{
    for (ptrdiff_t i(0); i < length_; i++)
        ostrm << "A[" << i << "] = " << pdata[i] << " ";
    return ostrm;
}

std::istream& Array::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int x(0);
    char s(0);
    int y(0);
    int z(0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> s >> y_ >> s >> z_ >> rightBrace;
    if (istrm.good())
    {
        if ((Array::leftBrace == leftBrace) && (Array::separator == s)
            && (Array::rightBrace == rightBrace))
        {
            x_ = x;
            y_ = y;
            z_ = z;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}