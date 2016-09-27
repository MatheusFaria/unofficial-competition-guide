#include <cmath>

using namespace std;

#define DBL_DELTA 1e-9
#define DBL_EQ(a, b) (fabs((a) - (b)) < DBL_DELTA)  // a == b

class Line {
public:
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line(const Point& P, const Point& Q)
    {
        // General Line equation ax + by + c
        a = P.y - Q.y;
        b = Q.x - P.x;
        c = P.x * Q.y - P.y * Q.x;

        // Normalizing the general equation. It is useful for line comparision
        auto k = 1.0/(a ? a : b);

        a *= k;
        b *= k;
        c *= k;
    }

    double distance(const Point& P) const
    {
        return fabs(a * P.x +  b * P.y + c)/hypot(a, b);
    }

    double contains(const Point& P) const { return DBL_EQ(distance(P), 0); }

    Point intersect(const Line& l) const
    {
        // !! The lines must intersect, call parallel to be sure

        auto det = 1.0/(a * l.b - b * l.a);
        return Point((-c * l.b + l.c * b) * det,
                     (-a * l.c + l.a * c) * det);
    }

    bool parallel(const Line& l) const
    {
        return DBL_EQ(a, l.a) && DBL_EQ(b, l.b) && !DBL_EQ(c, l.c);
    }

    Point closest(const Point& P) const
    {
        auto det = 1.0/(a*a + b*b);
        return Point((b * ( b * P.x - a * P.y) - a * c) * det,
                     (a * (-b * P.x + a * P.y) - b * c) * det);
    }

    bool operator==(const Line& l) const
    {
        return DBL_EQ(a, l.a) && DBL_EQ(b, l.b) && DBL_EQ(c, l.c);
    }

    double a, b, c;
};

/*
distance
    Tested on: UVA191
contains
    Tested on: UVA191
intersect
    Tested on: UVA378, UVA920
parallel
    Tested on: UVA378
closest
    Tested on: UVA10263
operator==
    Tested on: UVA378
*/
