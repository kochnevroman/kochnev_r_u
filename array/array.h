#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <iosfwd>
#include <cstddef>

enum choiceOfSort
{
    UP,
    DOWN
};

class Array
{
public:
    Array() = default; //дефолтный конструктор
    Array(const ptrdiff_t & size); //конструктор
    Array(const Array & array); //конструктор копирования

    ~Array(); //деструктор

    Array& operator=(const Array& a); //оператор присваивания

    //доступ по индексу
    int& operator[](const ptrdiff_t index);
    const int& operator[](const ptrdiff_t index) const;

    ptrdiff_t count() const { return size_; }
    ptrdiff_t capacity() const { return capacity_; }

    //новый размер массива
    void resize(const int& newArraySize);

    //добавление в любое место массива
    void addToIndex(const ptrdiff_t& newIndex, const int& newElement);
    //добавление в начало массива
    void addFirst(const int& newElement);
    //добавление в конец массива
    void addLast(const int& newElement);

    //удаление элемента массива по индексу
    void removeAtIndex(const ptrdiff_t& removableElementIndex);
    //удаление элемента массива по индексу
    void removeFirst();
    //удаление элемента массива по индексу
    void removeLast();

    //сортировка массива по возрастанию (по умолчанию)
    void sort();

    //сортировка массива c выбором - по возрастанию или по убыванию
    void sort(choiceOfSort choice);

    //перестановка двух элементов массива
    void reshuffleOfElements(const ptrdiff_t& firstIndex, const ptrdiff_t& secondIndex);

    //Проверка на пустоту
    bool isEmpty();

    std::ostream& writeTo(std::ostream& ostrm);

private:
    ptrdiff_t size_{ 0 };
    ptrdiff_t capacity_{ 0 };
    int* pdata{ nullptr };

    static const char leftBrace{ '[' };
    static const char separator{ ',' };
    static const char rightBrace{ ']' };
};

inline std::ostream& operator << (std::ostream& ostrm, Array& b)
{
    return b.writeTo(ostrm);
}


#endif //ARRAY_ARRAY_H