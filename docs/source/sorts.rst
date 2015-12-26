Sorts
=====

Merge Sort
----------

.. warning::

    NOT TESTED

.. code-block:: cpp

    #include <cstring>  // memcpy

    #define MAX 10100

    int dst[MAX];
    void merge_sort(int src[], int a, int b)
    {
        /*
            Complexity: O(n log n)
        */

        int n = b - a;
        if(n == 0)
            return;

        int mid = a + n/2;

        merge_sort(src, a, mid);
        merge_sort(src, mid + 1, b);

        int begin1 = a, begin2 = mid + 1;

        for(int i = a; i <= b; i++)
        {
            if((src[begin1] < src[begin2] || begin2 > b)  && begin1 <= mid)
            {
                dst[i] = src[begin1];
                begin1++;
            }
            else if(begin2 <= b)
            {
                dst[i] = src[begin2];
                begin2++;
            }
        }

        memcpy(src + a, dst + a, (n + 1)*sizeof(int));
    }

.. toctree::
   :maxdepth: 2
