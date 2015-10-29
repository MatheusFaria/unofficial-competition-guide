#include <iostream>   // cout, endl
#include <algorithm>  // next_permutation, prev_permutation

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    cout << "Next: ";
    next_permutation(a, a + 5);
    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Prev: ";
    prev_permutation(a, a + 5);
    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
