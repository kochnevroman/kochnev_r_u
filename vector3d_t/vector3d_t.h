#pragma once
#ifndef VECTOR3D_T_VECTOR3D_T_H
#define VECTOR3D_T_VECTOR3D_T_H

#include <iosfwd>
#include <sstream>
#include <cmath>

template <typename T>

class Vector3d_T
{
public:
    Vector3d_T() = default;
    Vector3d_T(const T x, const T y, const T z);
    Vector3d_T(const Vector3d_T& vector3d_t);

    ~Vector3d_T() = default;

    Vector3d_T<T>& operator=(const Vector3d_T& vector3d_t);

    bool operator==(const Vector3d_T& vector3d_t);
    bool operator!=(const Vector3d_T& vector3d_t);

    Vector3d_T<T>& operator+=(const Vector3d_T<T>& vector3d_t);
    Vector3d_T<T>& operator-=(const Vector3d_T<T>& vector3d_t);
    Vector3d_T<T>& operator*=(const T number);
    Vector3d_T<T>& operator/=(const T number);

    bool compareTo(const Vector3d_T<T>& vector3d_t);

    // Скалярное произведение двух векторов.
    double scalarProduct(const Vector3d_T<T>& vector3d_t);
    // Длина вектора.
    double length ();
    // Косинус угла между векторами.
    double cosineOfAngle (const Vector3d_T<T>& vector3d_t);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    T x_{ T() };
    T y_{ T() };
    T z_{ T() };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char space { ' ' };
    static const char rightBrace{ '}' };

};

template <typename T>
inline std::ostream& operator << (std::ostream& ostrm, const Vector3d_T<T>& vector3d_t)
{
    return vector3d_t.writeTo(ostrm);
}

template <typename T>
inline std::istream& operator >> (std::istream& istrm, Vector3d_T<T>& vector3d_t)
{
    return vector3d_t.readFrom(istrm);
}

template <typename T>
Vector3d_T<T>::Vector3d_T(const T x, const T y, const T z)
        : x_(x)
        , y_(y)
        , z_(z)
{
}

template <typename T>
Vector3d_T<T>::Vector3d_T(const Vector3d_T<T>& vector3d_t)
        : x_(vector3d_t.x_)
        , y_(vector3d_t.y_)
        , z_(vector3d_t.z_)
{
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>::operator=(const Vector3d_T<T>& vector3d_t)
{
    x_ = vector3d_t.x_;
    y_ = vector3d_t.y_;
    z_ = vector3d_t.z_;
    return *this;
}

/*
template <typename T>
bool Vector3d_T<T>::compareTo(const Vector3d_T<T>& vector3d_t)
{
    if ((x_ == vector3d_t.x_) && (y_ == vector3d_t.y_) && (z_ == vector3d_t.z_)) {
        return true;
    } else {
        return false;
    }
}

bool Vector3d_T<double>::compareTo(const Vector3d_T<double>& vector3d_t)
{
    const double eps0 = 1e-12;
    if ((x_ - vector3d_t.x_) < eps0 && (y_ - vector3d_t.y_) < eps0 && (z_ - vector3d_t.z_) < eps0) {
        return true;
    } else {
        return false;
    }
}

bool Vector3d_T<float>::compareTo(const Vector3d_T<float>& vector3d_t)
{
    const float eps0 = 1e-12;
    if ((x_ - vector3d_t.x_) < eps0 && (y_ - vector3d_t.y_) < eps0 && (z_ - vector3d_t.z_) < eps0) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool Vector3d_T<T>::operator==(const Vector3d_T<T>& vector3d_t)
{
    return compareTo(vector3d_t);
}
*/

template <typename T>
bool Vector3d_T<T>::operator==(const Vector3d_T<T>& vector3d_t)
{
    double eps0 = 0.000001;
    return((abs(vector3d_t.x_ - x_) < eps0) && (abs(vector3d_t.y_ - y_) < eps0) && (abs(vector3d_t.z_ - z_) < eps0));
}

template <typename T>
bool Vector3d_T<T>::operator!=(const Vector3d_T<T> &vector3d_t)
{
    return !operator==(vector3d_t);
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>::operator+=(const Vector3d_T<T>& vector3d_t)
{
    x_ = vector3d_t.x_ + x_;
    y_ = vector3d_t.y_ + y_;
    z_ = vector3d_t.z_ + z_;
    return *this;
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>::operator-=(const Vector3d_T<T>& vector3d_t)
{
    x_ = x_ - vector3d_t.x_;
    y_ = y_ - vector3d_t.y_;
    z_ = z_ - vector3d_t.z_;
    return *this;
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>::operator*=(const T number)
{
    x_ = x_ * number;
    y_ = y_ * number;
    z_ = z_ * number;
    return *this;
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>::operator/=(const T number)
{
    x_ = x_ / number;
    y_ = y_ / number;
    z_ = z_ / number;
    return *this;
}

template <typename T>
double Vector3d_T<T>::scalarProduct(const Vector3d_T<T> &vector3d_t)
{
    return (x_ * vector3d_t.x_, y_ * vector3d_t.y_, z_ * vector3d_t.z_);
}

template <typename T>
double Vector3d_T<T>::length()
{
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

template <typename T>
double Vector3d_T<T>::cosineOfAngle(const Vector3d_T<T> &vector3d_t)
{
    double firstLength = length();
    double secondLength = sqrt(pow(vector3d_t.x_, 2) + pow(vector3d_t.y_, 2) + pow(vector3d_t.z_, 2));

    if (firstLength != 0 && secondLength != 0) {
        return scalarProduct(vector3d_t) / (firstLength * secondLength);
    }
    return 1;
}

template <typename T>
Vector3d_T<T> operator+(const Vector3d_T<T>& firstVector3d_T, const Vector3d_T<T>& secondVector3d_T)
{
    Vector3d_T<T> vector3d(firstVector3d_T);
    vector3d += secondVector3d_T;
    return vector3d;
}

template <typename T>
Vector3d_T<T> operator-(const Vector3d_T<T>& firstVector3d_T, const Vector3d_T<T>& secondVector3d_T)
{
    Vector3d_T<T> vector3d(firstVector3d_T);
    vector3d -= secondVector3d_T;
    return vector3d;
}

template <typename T>
Vector3d_T<T> operator*(const Vector3d_T<T>& vector3d_t, const T number)
{
    Vector3d_T<T> vector3d_t_(vector3d_t);
    vector3d_t_ *= number;
    return vector3d_t_;
}

template <typename T>
Vector3d_T<T> operator*(const T number, const Vector3d_T<T>& vector3d_t)
{
    Vector3d_T<T> vector3d_t_(vector3d_t);
    vector3d_t_ *= number;
    return vector3d_t_;
}

template <typename T>
Vector3d_T<T> operator/(const Vector3d_T<T>& vector3d_t, const T number)
{
    Vector3d_T<T> vector3d_t_(vector3d_t);
    vector3d_t_ /= number;
    return vector3d_t_;
}

template <typename T>
std::ostream& Vector3d_T<T>::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << space << y_ << separator << space << z_ << rightBrace;
    return ostrm;
}

template <typename T>
std::istream& Vector3d_T<T>::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int x(0);
    char separator(0);
    char space(0);
    int y(0);
    int z(0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> separator >> space >> y_ >> separator >> space >> z_ >> rightBrace;
    if (istrm.good()) {
        if ((Vector3d_T<T>::leftBrace == leftBrace) && (Vector3d_T<T>::separator == separator)
            && (Vector3d_T<T>::rightBrace == rightBrace)) {
            x_ = x;
            y_ = y;
            z_ = z;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

#endif //VECTOR3D_T_VECTOR3D_T_H
