#include <iostream>

using namespace std;

int max_1D_range_sum_kadane(int values[], int N)
{
    /*
        Uses dynamic programming to find the largest sum on the largest interval.

        Complexity: O(n)
    */

    int sum = 0, max_sum = 0;
    int a = 0;
    int sequence_init = 0, sequence_end = 0;

    for(int i = 0; i < N; i++)
    {
        sum += values[i];
        if(sum < 0)
        {
            a = i + 1;
            sum = 0;
        }

        if(max_sum < sum)
        {
            sequence_init = a;
            sequence_end = i;

            max_sum = sum;
        }
        else if(max_sum == sum)
        {
            if(i - a > sequence_end - sequence_init)
            {
                sequence_init = a;
                sequence_end = i;
            }
        }
    }

    return max_sum;
}

int main()
{
    int N = 10;
    int values[] = {9, 2, -12, 35, 2, -13, -5, 30, 11, -1};

    cout << "Sum: " << max_1D_range_sum_kadane(values, N) << endl;
    return 0;
}

/*
    Tested on: UVA507
*/
