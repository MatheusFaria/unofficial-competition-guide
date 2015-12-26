Code Snippets
=============

In this section you can find several pieces of code that helps you to solve some
questions, most of them are already implemented on C++. In those cases the use
of the right functions will be presented.

Next and Prev Permutation
-------------------------

Find the next, or previous, lexicographical permutation of that array or collection.

.. code-block:: cpp

    #include <iostream>   // cout, endl
    #include <algorithm>  // next_permutation, prev_permutation

    using namespace std;

    int main()
    {
        int size = 5;
        int a[] = {1, 2, 3, 4, 5};

        cout << "Next: ";
        next_permutation(a, a + size);
        for(int i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "Prev: ";
        prev_permutation(a, a + size);
        for(int i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        return 0;
    }

Floating Point Comparison
-------------------------

To compare two floating point numbers you need to use this code, otherwise
the imprecision of the operations made using them can generate a biased result.

.. code-block:: cpp

    #include <iostream> // cout, endl
    #include <cmath>    // fabs

    using namespace std;

    #define PRECISION 0.000001

    int main()
    {
        double a = 0.2;

        // 0.2*3 == a*3
        if(fabs(0.2*3 - a*3) < PRECISION)
        {
            cout << "0.2*3 == a*3" << endl;
        }

        return 0;
    }

.. toctree::
   :maxdepth: 2
