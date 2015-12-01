#include <iostream>

using namespace std;

/*

-- 1D Max Range Sum --

Uses dynamic programming to find the largest sum on the largest interval.

-- Complexity --

O(n^2)

*/

int main()
{
    int N = 10;
    int values[] = {9, 2, -12, 35, 2, -13, -5, 30, 11, -1};

    int sumMax = 0;
    int A = 0, B = 0;

    for(int i = 0; i < N; i++)
    {
        int sum = 0;
        for(int j = i; j < N; j++)
        {
            sum += values[j];

            if(sumMax < sum)
            {
                A = i;
                B = j;

                sumMax = sum;
            }
            else if(sumMax == sum)
            {
                if(j - i > B - A)
                {
                    A = i;
                    B = j;
                }
            }
        }
    }

    cout << "Sum: " << sumMax << " A: " << A << " B: " << B << endl;
    return 0;
}
