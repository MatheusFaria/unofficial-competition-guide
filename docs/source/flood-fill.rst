Flood Fill
==========

Useful to traverse an implicit graph, that can be represented on a N dimensional
array. But the idea can be applied to any kind of graph.

.. note::

    Tested on: UVA469

.. code-block:: cpp

    #define MAX 110
    char G[MAX][MAX];

    int flood_fill(int i, int j, int n, int m, char color, char new_color)
    {
        /*
            Measures the size of the component that (i, j) are in. And recolors
            the component to the new_color

            Complexity: O(V + E)
        */

        if(i < 0 || j < 0 || i >= n || j >= m) return 0;

        // Arrays to move in the grid
        // {up, down, right, left} + {diagonals}
        int drow[8] = {0,  0, 1, -1, 1,  1, -1, -1};
        int dcol[8] = {1, -1, 0,  0, 1, -1,  1, -1};

        if(G[i][j] != color) return 0;

        G[i][j] = new_color;

        int size = 1;
        for(int di = 0; di < 8; ++di)
            size += flood_fill(i + drow[di], j + dcol[di], n, m, color, new_color);

        return size;
    }

.. toctree::
   :maxdepth: 2
