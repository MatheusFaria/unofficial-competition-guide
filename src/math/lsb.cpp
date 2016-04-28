#include <iostream>

using namespace std;

#define LSB(x) ((x) & (-(x)))

int main()
{
    // Should be 2
    cout << LSB(10) << endl;

    return 0;
}

/*
    Tested on: URI1500, URI1804, UVA12086
*/
