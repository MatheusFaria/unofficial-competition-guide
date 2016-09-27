#include <cmath>

using namespace std;

#define DBL_DELTA 1e-9
#define DBL_EQ(a, b) (fabs((a) - (b)) < DBL_DELTA)  // a == b
#define DBL_LT(a, b) (((b) - (a)) > DBL_DELTA)      // a < b

#define SQUARE(x) ((x) * (x))

class Point {
public:
    Point(double xx = 0, double yy = 0, double zz = 0)
        : x(xx), y(yy), z(zz) {}

    inline double distance(const Point& p) const
    {
        return sqrt(SQUARE(x - p.x) + SQUARE(y - p.y) + SQUARE(z - p.z));
    }

    inline Point rotate2D(double angle)
    {
        return Point(cos(angle) * x - sin(angle) * y,
                     sin(angle) * x + cos(angle) * y);
    }

    Point translate(const Point& P) const
    {
        return Point(P.x + x, P.y + y, P.z + z);
    }

    Point scale(const Point& P)
    {
        return Point(x * P.x, y * P.y, z * P.z);
    }

    double length() const
    {
        return sqrt(SQUARE(x) + SQUARE(y) + SQUARE(z));
    }

    Point normalize()
    {
        auto len = length();
        return (*this/len);
    }

    double angle() const
    {
        return atan(y / x) + (x < 0 ? M_PI : 0);
    }

    double dot_product(const Point& v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    Point cross_product(const Point& v)
    {
        return Point(y * v.z - z * v.y,
                     z * v.x - x * v.z,
                     x * v.y - y * v.x);
    }

    inline bool operator==(const Point& p) const
    {
        return DBL_EQ(x, p.x) && DBL_EQ(y, p.y) && DBL_EQ(z, p.z);
    }

    inline bool operator<(const Point& p) const
    {
        return (DBL_EQ(x, p.x) ?
                   (DBL_EQ(y, p.y) ?
                       DBL_LT(z, p.z)
                       : DBL_LT(y, p.y))
                   : DBL_LT(x, p.x));
    }
    inline bool operator>(const Point& p) const { return p < (*this); }

    inline Point operator+(const Point& p) const
    {
        return Point(x + p.x, y + p.y, z + p.z);
    }
    inline Point& operator+=(const Point& p)
    {
        x += p.x; y += p.y; z += p.z;
        return *this;
    }

    inline Point operator-(const Point& p) const
    {
        return Point(x - p.x, y - p.y, z - p.z);
    }
    inline Point& operator-=(const Point& p)
    {
        x -= p.x; y -= p.y; z -= p.z;
        return *this;
    }

    inline Point operator/(double n) const
    {
        return Point(x/n, y/n, z/n);
    }
    inline Point& operator/=(double n)
    {
        x /= n; y /= n; z /= n;
        return *this;
    }

    inline Point operator*(double n) const
    {
        return Point(x*n, y*n, z*n);
    }
    inline Point& operator*=(double n)
    {
        x *= n; y *= n; z *= n;
        return *this;
    }

    double x, y, z;
};

inline double D(const Point& P, const Point& Q, const Point& R)
{
    // This function calculate the matrix determinant where each point is a line
    // It has several interpretations:
    //   1) D = 0: the point are colinear
    //      D > 0: R is above the line PQ, or in the counterclockwise direction
    //      D < 0: R is under the line PQ, or in the clockwise direction
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) -
           (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

/*
distance
    Tested on: UVA152, UVA587, UVA920
rotate2D
    Tested on: UVA10466, UVA11505
operator+
    Tested on: UVA10466
operator+=
    Tested on: UVA10585
operator*
    Tested on: UVA10585
operator-
    Tested on: UVA10585
operator/=
    Tested on: UVA10585
operator<
    Tested on: UVA10585
operator>
    Tested on: UVA920
D
    Tested on: UVA191
*/
