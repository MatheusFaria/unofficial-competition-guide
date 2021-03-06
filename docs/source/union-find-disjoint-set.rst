Union-Find Disjoint Set
=======================

.. note::

    Tested on: UVA599, UVA10583, UVA11503, URI1764


.. code-block:: cpp

    #include <algorithm>

    using namespace std;

    #define MAX 40010

    class UFDS {
    public:
        int parents[MAX];
        int heights[MAX]; // the size of each set
        int n_sets;       // how many sets are in the UFDS

        UFDS(int size)
        {
            // Zero base union find, the elements goes from 0 to N - 1
            // If you need to change the the interval, increase the size OR
            // change the for below
            for(int i = 0; i < size; ++i)
            {
                heights[i] = 1;
                parents[i] = i;
            }

            n_sets = size;
        }

        int find_set(int i) // find the set of node i
        {
            if(parents[i] != i)
                parents[i] = find_set(parents[i]);
            return parents[i];
        }

        inline bool same_set(int x, int y) // checks if x and y are in the same set
        {
            return find_set(x) == find_set(y);
        }

        void union_set(int x, int y) // unite x and y in the same set
        {
            int root1 = find_set(x), root2 = find_set(y);

            if(root1 != root2) // x and y are not in the same set
            {
                // The larger set absorb the smaller set
                if(heights[root1] < heights[root2]) swap(root1, root2);

                parents[root2] = root1;
                heights[root1] += heights[root2];

                n_sets--; // On each union the UFDS reduces one set in size
            }
        }
    };


Usage:

.. code-block:: cpp

    int main()
    {
        UFDS ufds(8);

        ufds.union_set(1, 2);
        ufds.union_set(5, 3);
        ufds.union_set(6, 8);
        ufds.union_set(5, 8);

        return 0;
    }

Usage graphical representation:

After class instantiation:

.. image:: _static/ufds-initial-state.png
   :width: 600 px
   :align: center

After unions:

.. image:: _static/ufds-final-state.png
   :width: 600 px
   :align: center

.. toctree::
   :maxdepth: 2
