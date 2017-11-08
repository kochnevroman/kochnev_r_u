//
// Created by Roman Kochnev on 25.10.2017.
//

#include <opencl-c.h>

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <iosfwd>

class Array
{
public:
    Array() = default; //дефолтный конструктор

    Array(const ptrdiff_t & size) //конструктор
    {
        pdata = new int[size];
        size_ = size;
    }

    Array(const Array & rhs) //конструктор копирования
    {
        pdata = new int[rhs.size_];
        for (ptrdiff_t i(0); i < rhs.length_; i++)
        {
            pdata[i] = rhs[i];
        }
        size_ = rhs.size_;
        length_ = rhs.length_;
    }

    ~Array() //деструктор
    {
        delete[] pdata;
        pdata = nullptr;

        size_ = 0;
        length_ = 0;
    }

    Array& operator=(const Array& a); //оператор присваивания

    int& operator[](const ptrdiff_t index); //доступ по индексу
    const int& operator[](const ptrdiff_t index) const;

    ptrdiff_t count() const { return size_; }
    ptrdiff_t length() const { return length_; }

    void resize(const int& newArraySize);
    void add(const int& newElement); //добавление в начало массива
    void append(const int& newElement); //добавление в конец массива
    void remove(const int& removableElementIndex); //удаление элемента массива по индексу

    void sort(); //сортировка массива
    void reshuffleElements(const int& firstIndex, const int& secondIndex); //перестановка двух элементов массива

    std::ostream& writeTo(std::ostream& ostrm);
    std::istream& readFrom(std::istream& istrm);

private:
    ptrdiff_t size_{ 0 };
    ptrdiff_t length_{ 0 };
    int* pdata{ nullptr };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

inline std::ostream& operator << (std::ostream& ostrm, Array& b)
{
    return b.writeTo(ostrm);
}


inline std::istream& operator >> (std::istream& istrm, Array& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //ARRAY_ARRAY_H