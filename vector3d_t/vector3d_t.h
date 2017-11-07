//
// Created by Roman Kochnev on 25.10.2017.
//

#ifndef VECTOR3D_T_VECTOR3D_T_H
#define VECTOR3D_T_VECTOR3D_T_H

#include <iosfwd>
#include <iostream>

template <typename T>

struct Vector3d_T
{
public:
    Vector3d_T() = default;

    Vector3d_T(const T x, const T y, const T z) //конструктор
    {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    Vector3d_T(const Vector3d_T<T>& vector3d_t) //конструктор копирования
    {
        x_ = vector3d_t.x_;
        y_ = vector3d_t.y_;
        z_ = vector3d_t.z_;
    }

    ~Vector3d_T() = default; //деструктор, уничтожение

    Vector3d_T<T> operator=(const Vector3d_T<T>& vector3d_t) //присваивание
    {
        x_ = vector3d_t.x_;
        y_ = vector3d_t.y_;
        z_ = vector3d_t.z_;
        return *this;
    }

    bool operator==(const Vector3d_T<T>& rhs); //равно
    bool operator!=(const Vector3d_T<T>& rhs) { return !operator==(rhs); } //не равно

    Vector3d_T<T>& operator+=(const Vector3d_T<T>& rhs); //прибавление к текущему вектору вектор
    Vector3d_T<T>& operator-=(const Vector3d_T<T>& rhs); //вычитание из текущего вектора вектор
    Vector3d_T<T>& operator*=(const double& rhs); //умножение вектора на число
    Vector3d_T<T>& operator/=(const double& rhs); //деление вектора на число

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    T x_{ T() };
    T y_{ T() };
    T z_{ T() };


    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

template <typename T>
Vector3d_T<T> operator+(const Vector3d_T<T>& lhs, const Vector3d_T<T>& rhs); //сложение двух векторов
template <typename T>
Vector3d_T<T> operator-(const Vector3d_T<T>& lhs, const Vector3d_T<T>& rhs); //вычитание двух векторов

template <typename T>
Vector3d_T<T> scalarProduct(const Vector3d_T<T>& lhs, const Vector3d_T<T>& rhs); //скалярное произведение двух векторов

template <typename T>
double length (const Vector3d_T<T>& rhs); //длина вектора

template <typename T>
inline std::ostream& operator << (std::ostream& ostrm, const Vector3d_T<T>& rhs)
{
    return rhs.writeTo(ostrm);
}

template <typename T>
inline std::istream& operator >> (std::istream& istrm, Vector3d_T<T>& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //VECTOR3D_T_VECTOR3D_T_H
