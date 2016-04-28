#include <iostream>

using namespace std;

int max_range_sum_1d(int values[], int N)
{
    /*
        Uses dynamic programming to find the largest sum on the largest interval.

        Complexity: O(n^2)
    */

    int max_sum = 0;
    int A = 0, B = 0; // The begin and end interval indices

    for(int i = 0; i < N; i++)
    {
        int sum = 0;
        for(int j = i; j < N; j++)
        {
            sum += values[j];

            if(max_sum < sum)
            {
                A = i;
                B = j;

                max_sum = sum;
            }
            else if(max_sum == sum)
            {
                if(j - i > B - A)
                {
                    A = i;
                    B = j;
                }
            }
        }
    }

    return max_sum;
}

int main()
{
    int N = 10;
    int values[] = {9, 2, -12, 35, 2, -13, -5, 30, 11, -1};

    int sumMax = max_range_sum_1d(values, N);

    cout << "Sum: " << sumMax << endl;
    return 0;
}
