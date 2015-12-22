Segment Tree
============

.. note::

    Tested on: UVA10324


Below you can find a Sum Segment Tree implementation. In order to adapt it to
other kinds of segment trees, you need to look for where this trees is using
the `+` operator to update the values, and change it to other operator.

.. code-block:: cpp

    #include <cstdio> // scanf

    #define MAX 10000000

    // Special input, should put the elements from the last posisition to the
    // top
    int tree[2 * MAX];
    int n;

    void build()
    {
        /*
            Builds the tree backwards, the values of the original array should be
            stored in the last position

            Complexity: O(n)
        */

        for (int i = n - 1; i > 0; --i)
            // Merges the left and right child in positions i
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void modify(int p, int value)
    {
        /*
            Changes the value in postion p, p should be in the interval [0, n - 1]
            Complexity: O(log n)
        */

        // tree[p += n] = value :: Adjust p for its real position in the tree
        // while p is in the tree, go to its father and update it
        for (tree[p += n] = value; p > 1; p >>= 1)
            // Merges the node and its brother in parent position
            tree[p >> 1] = tree[p] + tree[p ^ 1];
    }

    int query(int l, int r)
    {
        /*
            Sum on interval [l, r), where l and r are on the interval [0, n - 1]
            Complexity: O(log n)
        */

        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }

        return res;
    }

    int main() {
        // Special input and build
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) scanf("%d", tree + n + i);
            build();

        modify(0, 1);
        query(0, 1);

        return 0;
    }

.. toctree::
   :maxdepth: 2
