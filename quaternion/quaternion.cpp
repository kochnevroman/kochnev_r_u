#include "quaternion.h"

Quaternion::Quaternion(const double a, const double b, const double c, const double d)
        : a_(a), b_(b), c_(c), d_(d)
{
}

Quaternion::Quaternion(const Quaternion &quaternion)
        : a_(quaternion.a_),
          b_(quaternion.b_),
          c_(quaternion.c_),
          d_(quaternion.d_)
{
}

Quaternion Quaternion::operator=(const Quaternion &quaternion)
{

}

bool Quaternion::operator==(const Quaternion &quaternion)
{

}

bool bool Quaternion::operator!=(const Quaternion &quaternion)
{

}

Quaternion& Quaternion::operator+=(const Quaternion &quaternion)
{

}

Quaternion& Quaternion::operator-=(const Quaternion &quaternion)
{

}

Quaternion& Quaternion::operator*=(const Quaternion &quaternion)
{

}

Quaternion& Quaternion::operator*=(const double number)
{

}

double Quaternion::det()
{

}

Quaternion operator+(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{

}

Quaternion operator-(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{

}

Quaternion operator*(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{

}

Quaternion operator*(const Quaternion& quaternion, const double number)
{

}

Quaternion operator*(const double number, const Quaternion& quaternion)
{

}

Quaternion operator/(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{

}

Quaternion operator/(const Quaternion& quaternion, const double number)
{

}


std::ostream& Quaternion::writeTo(std::ostream& ostrm) const
{

}

std::istream& Quaternion::readFrom(std::istream& istrm)
{

}
