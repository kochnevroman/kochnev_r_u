#include "array.h"
#include <iostream>
#include <stdexcept>

Array::Array()
        : pdata_(new int[size_ + 1])
{

}

Array::Array(const ptrdiff_t size)
        : size_(size)
{
    if (size > 0) {
        pdata_ = new int[size_];
    } else {
        throw std::invalid_argument("Size can't be less or equal to 0");
    }
}

Array::Array(const Array & array)
        : size_(array.size_)
        , pdata_(new int[array.size_])
{
    for (ptrdiff_t i(0); i < array.size_; i += 1) {
        pdata_[i] = array[i];
    }
}

Array::~Array()
{
    delete[] pdata_;
    pdata_ = nullptr;
    size_ = 0;
}

int& Array::operator[](const ptrdiff_t index)
{
    if (index >= 0 && index < size_) {
        return pdata_[index];
    } else {
        throw std::invalid_argument("Index is out of range");
    }
}

const int& Array::operator[](const ptrdiff_t index) const
{
    if (index >= 0 && index < size_) {
        return pdata_[index];
    } else {
        throw std::invalid_argument("Index is out of range");
    }
}

ptrdiff_t Array::count()
{
    return size_;
}

Array& Array::operator=(const Array & array)
{
    if (pdata_ == array.pdata_ && array.size_ == size_) {
        return *this;
    }

    pdata_ = new int[array.size_];

    for (ptrdiff_t i(0); i < array.size_; i += 1) {
        pdata_[i] = array[i];
    }

    size_ = array.size_;
    return *this;
}

void Array::resize(const ptrdiff_t newArraySize)
{
    if (size_ < newArraySize) {
        int *newArray = new int[newArraySize];

        for (ptrdiff_t i(0); i < size_; i += 1) {
            newArray[i] = pdata_[i];
        }

        for (ptrdiff_t i(size_); i < newArraySize; i += 1) {
            newArray[i] = 0;
        }

        delete[] pdata_;
        pdata_ = newArray;
        size_ = newArraySize;
    } else {
        int *newArray = new int[newArraySize];

        for (ptrdiff_t i(0); i < newArraySize; i += 1) {
            newArray[i] = pdata_[i];
        }

        delete[] pdata_;
        pdata_ = newArray;
        size_ = newArraySize;
    }
}

void Array::insertToIndex(const int newElement, const ptrdiff_t newIndex)
{
    if (newIndex >= 0 && newIndex < size_) {
        int *newArray = new int[size_ + 1];

        for (ptrdiff_t i(0); i < newIndex; i += 1) {
            newArray[i] = pdata_[i];
        }

        newArray[newIndex] = newElement;

        for (ptrdiff_t i(newIndex + 1); i < size_ + 1; i += 1) {
            newArray[i] = pdata_[i - 1];
        }

        size_ += 1;
        delete[] pdata_;
        pdata_ = newArray;
    } else {
        throw std::invalid_argument("Can not insert an element to an array with size less than New Index");
    }
}

void Array::insertFirst(const int newElement)
{
    int* newArray = new int[size_ + 1];

    newArray[0] = newElement;

    for (ptrdiff_t i(1); i < size_ + 1; i++) {
        newArray[i] = pdata_[i - 1];
    }

    size_ += 1;
    delete[] pdata_;
    pdata_ = newArray;
}

void Array::insertLast(const int newElement)
{
    int* newArray = new int[size_ + 1];

    for (ptrdiff_t i(0); i < size_; i += 1)
    {
        newArray[i] = pdata_[i];
    }

    newArray[size_] = newElement;

    size_ += 1;
    delete[] pdata_;
    pdata_ = newArray;
}

void Array::removeAtIndex(const ptrdiff_t removableElementIndex)
{
    if (removableElementIndex > 0 && removableElementIndex < size_) {
        int *newArray = new int[size_ - 1];

        for (ptrdiff_t i(0); i < removableElementIndex; i += 1) {
            newArray[i] = pdata_[i];
        }

        for (ptrdiff_t i(removableElementIndex); i < size_; i += 1) {
            newArray[i] = pdata_[i + 1];
        }

        size_ -= 1;
        delete[] pdata_;
        pdata_ = newArray;
    } else {
        throw std::invalid_argument("Index is out of range");
    }
}

void Array::removeFirst()
{
    if ( !isEmpty() ) {
        int *newArray = new int[size_ - 1];

        for (ptrdiff_t i(1); i < size_ - 1; i += 1) {
            newArray[i - 1] = pdata_[i];
        }

        size_ -= 1;
        delete[] pdata_;
        pdata_ = newArray;
    } else {
        throw std::invalid_argument("Can not remove an element from an empty array");
    }
}

void Array::removeLast()
{
    if ( !isEmpty() ) {
        int *newArray = new int[size_ - 1];

        for (ptrdiff_t i(0); i < size_ - 1; i += 1) {
            newArray[i] = pdata_[i];
        }

        size_ -= 1;
        delete[] pdata_;
        pdata_ = newArray;
    } else {
        throw std::invalid_argument("Can not remove an element from an empty array");
    }
}

void Array::sort(choiceOfSort choice)
{
    switch (choice) {
        case UP:
            for (ptrdiff_t i = 0; i < size_ - 1; i += 1) {
                int elementMin = pdata_[i];
                ptrdiff_t indexMin = i;
                for (ptrdiff_t j = i + 1; j < size_; j += 1) {
                    if (pdata_[j] < elementMin) {
                        elementMin = pdata_[j];
                        indexMin = j;
                    }
                }
                pdata_[indexMin] = pdata_[i];
                pdata_[i] = elementMin;
            }
            break;

        case DOWN:
            for (ptrdiff_t i = 0; i < size_ - 1; i += 1) {
                int elementMax = pdata_[i];
                ptrdiff_t indexMax = i;
                for (ptrdiff_t j = i + 1; j < size_; j += 1) {
                    if (pdata_[j] > elementMax) {
                        elementMax = pdata_[j];
                        indexMax = j;
                    }
                }
                pdata_[indexMax] = pdata_[i];
                pdata_[i] = elementMax;
            }
            break;
    }
}

void Array::reshuffleOfElements(const ptrdiff_t firstIndex, const ptrdiff_t secondIndex)
{
    if (firstIndex > 0 && firstIndex < size_ && secondIndex > 0 && secondIndex < size_) {
        int *newArray = new int[size_];

        for (ptrdiff_t i(0); i < size_; i += 1) {
            newArray[i] = pdata_[i];
        }

        int bufferVariable = newArray[firstIndex];
        newArray[firstIndex] = newArray[secondIndex];
        newArray[secondIndex] = bufferVariable;

        delete[] pdata_;
        pdata_ = newArray;
    } else {
        throw std::invalid_argument("One or two indexes are out of range");
    }
}

bool Array::isEmpty() const
{
    return pdata_ == nullptr;
}


std::ostream& Array::writeTo(std::ostream& ostrm)
{
    for (ptrdiff_t i(0); i < size_; i += 1) {
        ostrm << "A[" << i << "] = " << pdata_[i] << "  ";
    }
    return ostrm;
}

