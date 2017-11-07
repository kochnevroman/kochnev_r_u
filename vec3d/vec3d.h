#ifndef VEC3D_VEC3D_H
#define VEC3D_VEC3D_H

struct Vec3d {

public:
    Vec3d() = default;

    Vec3d::Vec3d(const double x, double y, double z) : x_(x), y_(y), z_(z)
    {
    }

    ~Vec3d() = default;

    Vec3d(const Vec3d& v) : x_(v.x_), y_(v.y_), z_(v.z_)
    {

    }

    bool operator==(const Vec3d& rhs) const { return (re == rhs.re) && (im == rhs.im); }

    bool operator!=(const Vec3d& rhs) const { return !operator==(rhs); }

    Vec3d& operator+=(const Vec3d& rhs);
    Vec3d& operator+=(const double rhs) { return operator+=(Vec3d(rhs)); }

    Vec3d& operator-=(const Vec3d& rhs);
    Vec3d& operator-=(const double rhs) { return operator-=(Vec3d(rhs)); }

    Vec3d& operator*=(const Vec3d& rhs);
    Vec3d& operator*=(const double rhs);

    Vec3d& operator/=(const double rhs);
    Vec3d& operator/=(const Vec3d& rhs);

    Vec3d operator=(const Vec3d& v) {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
        return *this;

    }

public:
    double x_{ 0.0 };
    double y_{ 0.0 };
    double z_{ 0.0 };

};

std::ostream& writeTo(std::ostream& ostrm) const;
std::istream& readFrom(std::istream& istrm);

double re{ 0.0 };
double im{ 0.0 };

static const char leftBrace{ '{' };
static const char separator{ ',' };
static const char rightBrace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //VEC3D_VEC3D_H
