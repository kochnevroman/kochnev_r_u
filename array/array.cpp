#include "array.h"
#include <iostream>

Array::Array(const ptrdiff_t & size) //конструктор
{
    pdata = new int[size];
    size_ = size;
}

Array::Array(const Array & array) //конструктор копирования
{
    pdata = new int[array.size_];

    for (ptrdiff_t i(0); i < array.size_; i++)
    {
        pdata[i] = array[i];
    }

    size_ = array.size_;
}

Array::~Array() //деструктор
{
    delete[] pdata;
    pdata = nullptr;

    size_ = 0;
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
    if (pdata == array.pdata && array.size_ == size_)
    {
        return *this;
    }

    pdata = new int[array.size_];

    for (ptrdiff_t i(0); i < array.size_; i++)
    {
        pdata[i] = array[i];
    }

    size_ = array.size_;
    return *this;
}

void Array::resize(const int& newArraySize)
{
    if (size_ < newArraySize)
    {
        int *newArray = new int[newArraySize];

        for (ptrdiff_t i(0); i < size_; i++)
        {
            newArray[i] = pdata[i];
        }

        delete[] pdata;
        pdata = newArray;
        size_ = newArraySize;
    }
    else {
        int *newArray = new int[newArraySize];

        for (ptrdiff_t i(0); i < newArraySize; i++)
        {
            newArray[i] = pdata[i];
        }

        delete[] pdata;
        pdata = newArray;
        size_ = newArraySize;
    }
}

//проверить, что-то работает направильно, в конец всегда ставляет ноль (0)
void Array::addToIndex(const ptrdiff_t &newIndex, const int &newElement)
{
    if (newIndex < 0) //если индекс < 0, вставить первым элементом
    {
        addFirst(newElement);
    }

    if (newIndex > size_) //если индекс > size_ вставить последним элементом
    {
        addLast(newElement);
    }

    else {
        int *newArray = new int[size_ + 1];

        for (ptrdiff_t i(0); i < newIndex; i++) {
            newArray[i] = pdata[i];
        }

        newArray[newIndex] = newElement;

        for (ptrdiff_t i(newIndex + 1); i < size_ + 1; i++) {
            newArray[i] = pdata[i - 1];
        }

        size_ += 1;
        delete[] pdata;
        pdata = newArray;
    }
}

void Array::addFirst(const int &newElement)
{
    int* newArray = new int[size_ + 1];

    newArray[0] = newElement;

    for (ptrdiff_t i(1); i < size_ + 1; i++)
    {
        newArray[i] = pdata[i-1];
    }

    size_ += 1;
    delete[] pdata;
    pdata = newArray;
}

void Array::addLast(const int &newElement)
{
    int* newArray = new int[size_ + 1];

    for (ptrdiff_t i(0); i < size_; i++)
    {
        newArray[i] = pdata[i];
    }

    newArray[size_] = newElement;

    size_ += 1;
    delete[] pdata;
    pdata = newArray;
}

void Array::removeAtIndex(const ptrdiff_t &removableElementIndex)
{
    if (removableElementIndex > 0 && removableElementIndex < size_)
    {
        int *newArray = new int[size_ - 1];

        for (ptrdiff_t i(0); i < removableElementIndex; i++)
        {
            newArray[i] = pdata[i];
        }

        for (ptrdiff_t i(removableElementIndex); i < size_; i++)
        {
            newArray[i] = pdata[i + 1];
        }

        size_ -= 1;
        delete[] pdata;
        pdata = newArray;
    }

    if (removableElementIndex > size_)
    {
        removeLast();
    }

    if (removableElementIndex < 0)
    {
        removeFirst();
    }
}

void Array::removeFirst()
{
    int *newArray = new int[size_ - 1];

    for (ptrdiff_t i(1); i < size_ - 1; i++)
    {
        newArray[i - 1] = pdata[i];
    }

    size_ -= 1;
    delete[] pdata;
    pdata = newArray;
}

void Array::removeLast()
{
    int *newArray = new int[size_ - 1];

    for (ptrdiff_t i(0); i < size_ - 1; i++)
    {
        newArray[i] = pdata[i];
    }

    size_ -= 1;
    delete[] pdata;
    pdata = newArray;
}

void Array::sort() {
    for (ptrdiff_t i = 0; i < size_ - 1; i++)
    {

        int elementMin = pdata[i];
        ptrdiff_t indexMin = i;
        for (ptrdiff_t j = i + 1; j < size_; j++)
        {
            if (pdata[j] < elementMin)
            {
                elementMin = pdata[j];
                indexMin = j;
            }
        }
        pdata[indexMin] = pdata[i];
        pdata[i] = elementMin;
    }
}

void Array::sort(choiceOfSort choice) {
    switch (choice) {
        case UP:
            Array::sort();
            break;
        case DOWN:
            for (ptrdiff_t i = 0; i < size_ - 1; i++)
            {

                int elementMax = pdata[i];
                ptrdiff_t indexMax = i;
                for (ptrdiff_t j = i + 1; j < size_; j++)
                {
                    if (pdata[j] > elementMax)
                    {
                        elementMax = pdata[j];
                        indexMax = j;
                    }
                }
                pdata[indexMax] = pdata[i];
                pdata[i] = elementMax;
            }
            break;
    }
}

void Array::reshuffleOfElements(const ptrdiff_t &firstIndex, const ptrdiff_t &secondIndex)
{
    //добавить проверку на соответствие secondIndex границе массива
    int *newArray = new int[size_];

    for (ptrdiff_t i(0); i < size_; i++)
    {
        newArray[i] = pdata[i];
    }

    int bufferVariable = newArray[firstIndex];
    newArray[firstIndex] = newArray[secondIndex];
    newArray[secondIndex] = bufferVariable;

    delete[] pdata;
    pdata = newArray;
}

bool Array::isEmpty() {
    if (size_ ==  0)
        return true;
    return false;
}


std::ostream& Array::writeTo(std::ostream& ostrm)
{
    for (ptrdiff_t i(0); i < size_; i++)
        ostrm << "A[" << i << "] = " << pdata[i] << "  ";
    return ostrm;
}

