Binomial
========

Iterative Formula
-----------------

.. warning::

    NOT TESTED

.. code-block:: cpp

    #include <algorithm> //  min

    using namespace std;

    // O(n) formula, product of (n - (k - i))/i for i going from 1 to k
    // !! Overflows depeding on n and k
    int binomial(int n, int k)
    {
        /*
            Complexity: O(min(n, k))
        */

        k = min(k, n - k);

        if(n < 0 || k < 0 || k > n) return 0;
        if(k == 0 || n == k) return 1;
        else if(k == 1) return n;

        int fat = 1;

        for(int i = 1; i <= k; i++)
        {
            fat = fat * (n - (k - i))/i;
        }

        return fat;
    }



Dynamic Programming
-------------------

.. note::

    Tested on: UVA530



.. code-block:: cpp

    #include <vector>    // vector
    #include <algorithm> //  min

    using namespace std;

    vector< vector<int> > C;

    // Dynamic Programming Solution, avoids overflow and saves spaces
    int binomial(int n, int k)
    {
        /*
            Complexity: O(min(n, k))
        */

        k = min(k, n - k);
        if(n < 0 || k < 0 || k > n) return 0;

        if(k == 0 || n == k)
            return 1;
        else if(k == 1)
            return n;

        for(int i = C.size(); i <= n; i++) C.push_back(vector<int>());
        for(int i = C[n].size(); i <= k; i++) C[n].push_back(0);

        if(C[n][k] == 0)
            C[n][k] = binomial(n - 1, k - 1) + binomial(n - 1, k);

        return C[n][k];
    }


.. toctree::
   :maxdepth: 2
