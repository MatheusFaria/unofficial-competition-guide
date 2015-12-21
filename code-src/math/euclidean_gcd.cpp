#include <iostream>

using namespace std;

inline int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
    // Should be 4
    cout << gcd(12, 8) << endl;

    return 0;
}
