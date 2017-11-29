#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <iosfwd>
#include <cstddef>

enum choiceOfSort
{
    UP, // максимальный - последний
    DOWN // минимальный - последний
};

class Array
{
public:
    Array();
    Array(const ptrdiff_t size);
    explicit Array(const Array& array);

    ~Array();

    Array& operator=(const Array& array);

    // Доступ по индексу.
    int& operator[](const ptrdiff_t index);
    const int& operator[](const ptrdiff_t index) const;

    // Получение размера массива.
    ptrdiff_t count();

    // Новый размер массива.
    void resize(const ptrdiff_t newArraySize);

    // Добавление в любое место массива.
    void insertToIndex(const int newElement, const ptrdiff_t newIndex);
    // Добавление в начало массива.
    void insertFirst(const int newElement);
    // Добавление в конец массива.
    void insertLast(const int newElement);

    // Удаление элемента массива по индексу.
    void removeAtIndex(const ptrdiff_t removableElementIndex);
    // Удаление первого элемента массива.
    void removeFirst();
    // Удаление последнего элемента массива.
    void removeLast();

    // Сортировка массива c выбором - по возрастанию (по умолчанию) или по убыванию.
    void sort(choiceOfSort choice = UP);

    // Перестановка двух элементов массива.
    void reshuffleOfElements(const ptrdiff_t firstIndex, const ptrdiff_t secondIndex);

    // Проверка на пустоту.
    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm);

private:
    ptrdiff_t size_{ 0 };
    int* pdata_{ nullptr };

    static const char leftBrace{ '[' };
    static const char separator{ ',' };
    static const char rightBrace{ ']' };
};

inline std::ostream& operator<<(std::ostream& ostrm, Array& array)
{
    return array.writeTo(ostrm);
}

#endif //ARRAY_ARRAY_H