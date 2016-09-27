#include <cmath>

using namespace std;

#define DBL_DELTA 1e-9
#define DBL_EQ(a, b) (fabs((a) - (b)) < DBL_DELTA)  // a == b

class Segment {
public:
    Segment(const Point& _A, const Point& _B) : A(_A), B(_B) {}

    inline double length() const { return A.distance(B); }

    bool contains(const Point& P) const
    {
        // Checks if P is in the AB line, if so, it checks the segment bounds
        // !! You can create this Line instace on the constructor

        if(DBL_EQ(D(A, B, P), 0))
        {
            if(DBL_EQ(A.x, B.x))
                return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
            else
                return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
        }

        return false;
    }

    bool intersect(const Segment& s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);

        if((DBL_EQ(d1, 0) && contains(s.A)) || (DBL_EQ(d2, 0) && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);

        if((DBL_EQ(d3, 0) && s.contains(A)) || (DBL_EQ(d4, 0) && s.contains(B)))
            return true;

        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }
    
    Point closest(const Point& P)                                                  
    {                                                                              
        Line r(A, B);                                                                       
        auto Q = r.closest(P);                                                     
                                                                                   
        if (this->contains(Q))                                                     
            return Q;                                                              
                                                                                   
        auto distA = P.distance(A);                                                
        auto distB = P.distance(B);                                                
                                                                                   
        if (distA <= distB) return A;                                              
        else return B;                                                             
    } 

    Point A, B;
};


/*
contains
    Tested on: UVA191, UVA10263
intersect
    Tested on: UVA191
closest
    Tested on: UVA10263
*/
