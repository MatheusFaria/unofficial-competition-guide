#include <iostream>

using namespace std;

inline int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

inline int lcm(int a, int b)
{
    //a*b/gcd
    return (a/gcd(a, b))*b;
}

int main()
{
    // Should be 24
    cout << lcm(12, 8) << endl;

    return 0;
}
