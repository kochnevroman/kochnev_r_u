#include "array.h"
#include <iostream>

Array::Array(const ptrdiff_t & size) //конструктор
{
    pdata = new int[size];
    size_ = size;
}

Array::Array(const Array & rhs) //конструктор копирования
{
    pdata = new int[rhs.size_];
    for (ptrdiff_t i(0); i < rhs.capacity_; i++)
    {
        pdata[i] = rhs[i];
    }
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
}

Array::~Array() //деструктор
{
    delete[] pdata;
    pdata = nullptr;

    size_ = 0;
    capacity_ = 0;
}

int& Array::operator[](const ptrdiff_t index)
{
    return pdata[index];
}

const int& Array::operator[](const ptrdiff_t index) const
{
    return pdata[index];
}

Array& Array::operator=(const Array & array)
{
    if (pdata == array.pdata && array.size_ == size_ && array.capacity_ == capacity_)
    {
        return *this;
    }
    pdata = new int[array.size_];
    for (ptrdiff_t i(0); i < array.capacity_; i++)
    {
        pdata[i] = array[i];
    }
    size_ = array.size_;
    capacity_ = array.capacity_;
    return *this;
}

void Array::resize(const int& newArraySize)
{
    if (capacity_ < newArraySize) {
        int *newarr = new int[newArraySize];

        for (ptrdiff_t i(0); i < capacity_; i++) {
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
        capacity_ = newArraySize;
    }
}

void Array::addToIndex(const ptrdiff_t &newIndex, const int &newElement)
{

}

void Array::addFirst(const int &newElement)
{
    resize(size_ * 2);
    for (int i = capacity_; i > 1; i++)
    {
        pdata[i] = pdata[i - 1];
    }
    pdata[0] = newElement;

}

void Array::addLast(const int &newElement)
{
    if (capacity_ < size_) {
        pdata[capacity_++] = newElement;
    }
    else {
        resize(size_ * 2);
        pdata[capacity_++] = newElement;
    }
}

void Array::removeAtIndex(const ptrdiff_t &removableElementIndex) {

}

void Array::removeFirst() {

}

void Array::removeLast() {

}

void Array::sort() {

}

void Array::reshuffleElements(const ptrdiff_t &firstIndex, const ptrdiff_t &secondIndex) {

}

std::ostream& Array::writeTo(std::ostream& ostrm)
{
    for (ptrdiff_t i(0); i < capacity_; i++)
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