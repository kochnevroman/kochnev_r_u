#pragma once
#ifndef VECTOR3D_VECTOR3D_H
#define VECTOR3D_VECTOR3D_H

#include <iosfwd>

struct Vector3d
{
public:
    Vector3d() = default;
    Vector3d(const double x, const double y, const double z); //конструктор
    Vector3d(const Vector3d& vector3d); //конструктор копирования

    ~Vector3d() = default; //деструктор, уничтожение

    Vector3d operator=(const Vector3d& vector3d) //присваивание
    {
        x_ = vector3d.x_;
        y_ = vector3d.y_;
        z_ = vector3d.z_;
        return *this;
    }

    bool operator==(const Vector3d& rhs); //равно
    bool operator!=(const Vector3d& rhs) { return !operator==(rhs); } //не равно

    Vector3d& operator+=(const Vector3d& rhs); //прибавление к текущему вектору вектор
    Vector3d& operator-=(const Vector3d& rhs); //вычитание из текущего вектора вектор
    Vector3d& operator*=(const double& rhs); //умножение вектора на число
    Vector3d& operator/=(const double& rhs); //деление вектора на число

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

//private:
    double x_{ 0.0 };
    double y_{ 0.0 };
    double z_{ 0.0 };


    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };

    //friend Vector3d scalarProduct(const Vector3d& lhs, const Vector3d& rhs); //скалярное произведение двух векторов
    //friend double length (const Vector3d& rhs); //длина вектора
};

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs); //сложение двух векторов
Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs); //вычитание двух векторов

Vector3d scalarProduct(const Vector3d& lhs, const Vector3d& rhs); //скалярное произведение двух векторов
double length (const Vector3d& rhs); //длина вектора

inline std::ostream& operator << (std::ostream& ostrm, const Vector3d& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Vector3d& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //VECTOR3D_VECTOR3D_H
