Max Range Sum
=============

1D Range Sum
------------

.. warning::

    NOT TESTED

.. code-block:: cpp

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

1D Range Sum (kadane)
---------------------

.. note::

    Tested on: UVA507

.. code-block:: cpp

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

2D Range Sum
------------

Finds in a matrix the rectangule tha sums the max value in the matrix

.. note::

    Tested on: UVA108

.. code-block:: cpp

    #include <limits>   // numeric_limits
    #include <algorithm> // max

    #define MAX 108

    using namespace std;

    // No initialization needed
    // This matrix will be overwrited in the process
    int matrix[MAX][MAX];

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

.. toctree::
   :maxdepth: 2
