#include <iostream>
#include <limits>

#define MAX 108

using namespace std;

// No initialization needed
// This matrix will be overwrited in the process
int matrix[MAX][MAX];

/*
TESTED ON:
UVA: 108
*/

int max_range_sum_2D(int n_lines, int n_colunms)
{
    int max_sum = numeric_limits<int>::lowest();

    // Computing the partial sum matrix
    for(int i = 0; i < n_lines; i++)
    {
        for(int j = 0; j < n_colunms; j++)
        {
            if(j) matrix[i][j] += matrix[i][j - 1];
            if(i) matrix[i][j] += matrix[i - 1][j];
            if(i && j) matrix[i][j] -= matrix[i - 1][j - 1];

            max_sum = max(max_sum, matrix[i][j]);
        }
    }

    for(int a = 0; a < n_lines; a++)
    {
        for(int b = 0; b < n_colunms; b++)
        {
            for(int c = a; c < n_lines; c++)
            {
                for(int d = b; d < n_colunms; d++)
                {
                    int sum = matrix[c][d];
                    if(a) sum -= matrix[a - 1][d];
                    if(b) sum -= matrix[c][b - 1];
                    if(a && b) sum += matrix[a - 1][b - 1];

                    max_sum = max(max_sum, sum);
                }
            }
        }
    }

    return max_sum;
}

int main()
{
    int N = 30;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matrix[i][j] = (i - j)*(i + j);

    cout << max_range_sum_2D(N, N) << endl;

    return 0;
}
