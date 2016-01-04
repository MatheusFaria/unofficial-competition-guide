Longest Increasing Subsequence (LIS)
====================================

Quadratic Solution
------------------

.. warning::

    NOT TESTED

.. code-block:: cpp

    int longest_increasing_subsequence(int values[], int size, int parents[], int &longest_seq_i)
    {

        int * lis = new int[size];
        for(int i = 0; i < size; i++)
            parents[i] = i;

        int longest_seq = 0;

        for(int i = 0; i < size; i++)
        {
            lis[i] = 1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(values[i] > values[j])
                {
                    if(lis[i] < lis[j] + 1)
                    {
                        parents[i] = j;
                        lis[i] = lis[j] + 1;
                    }
                }
            }

            if(lis[i] > longest_seq)
            {
                longest_seq = lis[i];
                longest_seq_i = i;
            }
        }

        delete[] lis;

        return longest_seq;
    }


N log N Solution
----------------

.. toctree::
   :maxdepth: 2
