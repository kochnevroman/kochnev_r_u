#pragma once
#ifndef VECTOR3D_VECTOR3D_H
#define VECTOR3D_VECTOR3D_H

#include <iosfwd>

class Vector3d
{
public:
    Vector3d() = default;
    Vector3d(const double x, const double y, const double z);
    Vector3d(const Vector3d& vector3d);

    ~Vector3d() = default;

    Vector3d operator=(const Vector3d& vector3d);

    bool operator==(const Vector3d& vector3d);
    bool operator!=(const Vector3d& vector3d);

    Vector3d& operator+=(const Vector3d& vector3d);
    Vector3d& operator-=(const Vector3d& vector3d);
    Vector3d& operator*=(const double number);
    Vector3d& operator/=(const double number);

    // Скалярное произведение двух векторов.
    double scalarProduct(const Vector3d& vector3d);
    // Длина вектора.
    double length ();
    // Косинус угла между векторами.
    double cosineOfAngle (const Vector3d& vector3d);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    double x_{ 0.0 };
    double y_{ 0.0 };
    double z_{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char space { ' ' };
    static const char rightBrace{ '}' };
};

Vector3d operator+(const Vector3d& firstVector3d, const Vector3d& secondVector3d);
Vector3d operator-(const Vector3d& firstVector3d, const Vector3d& secondVector3d);

Vector3d operator*(const Vector3d& vector3d, const double number);
Vector3d operator*(const double number, const Vector3d& vector3d);

Vector3d operator/(const Vector3d& vector3d, const double number);


inline std::ostream& operator << (std::ostream& ostrm, const Vector3d& vector3d)
{
    return vector3d.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Vector3d& vector3d)
{
    return vector3d.readFrom(istrm);
}

#endif //VECTOR3D_VECTOR3D_H
