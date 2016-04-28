#include <iostream> // cout, endl
#include <cmath>    // fabs

using namespace std;

#define PRECISION 0.000001

int main()
{
    double a = 0.2;

    // 0.2*3 == a*3
    if(fabs(0.2*3 - a*3) < PRECISION)
    {
        cout << "0.2*3 == a*3" << endl;
    }

    return 0;
}
