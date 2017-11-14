#pragma once
#ifndef QUATERNION_QUATERNION_H
#define QUATERNION_QUATERNION_H

#include <iosfwd>

struct Quaternion
{
    Quaternion() = default;
    Quaternion(const double a, const double b, const double c, const double d);
    Quaternion(const Quaternion& quaternion);

    ~Quaternion() = default;

    double a_ { 0.0 };
    double b_ { 0.0 };
    double c_ { 0.0 };
    double d_ { 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char space{' '};
    static const char rightBrace{ '}' };

    Quaternion operator=(const Quaternion& quaternion);

    bool operator==(const Quaternion& quaternion);
    bool operator!=(const Quaternion& quaternion);

    Quaternion& operator+=(const Quaternion& quaternion);
    Quaternion& operator-=(const Quaternion& quaternion);
    Quaternion& operator*=(const Quaternion& quaternion);

    Quaternion& operator*=(const double number);
    Quaternion& operator/=(const double number);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    //кватернионное сопряжение
    Quaternion conjugating();
    //модуль
    double module();
    //детерминант квартериона, представимого в матричном виде
    double det();
};


Quaternion operator+(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion);
Quaternion operator-(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion);

Quaternion operator*(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion);
Quaternion operator*(const Quaternion& quaternion, const double number);
Quaternion operator*(const double number, const Quaternion& quaternion);


inline std::ostream& operator << (std::ostream& ostrm, const Quaternion& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Quaternion& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //QUATERNION_QUATERNION_H
