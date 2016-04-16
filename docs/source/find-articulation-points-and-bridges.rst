Find Articulation Points and Bridges
====================================

.. note::

    Tested on: UVA315

.. code-block:: cpp

    #include <cstdio>
    #include <vector>
    #include <cstring>

    using namespace std;

    #define MAX 110
    #define UNVISITED -1

    int node_state[MAX];     // memset to UNVISITED
    int node_low_state[MAX]; // memset to UNVISITED
    int parent_node[MAX];    // memset to -1
    bool articulation[MAX];  // memset to false

    vector<int> G[MAX];
    int n_nodes; // Graph Size

    int dfs_counter;   // initialize with 0
    int root_children; // initialize with 0

    int dfs_root;

    void find_articulation_point_and_bridge(int node) {
        node_state[node] = node_low_state[node] = dfs_counter++;

        for(auto adjacent: G[node])
        {
            if(node_state[adjacent] == UNVISITED)
            {
                parent_node[adjacent] = node;
                if(node == dfs_root)
                {
                    root_children++;
                }

                find_articulation_point_and_bridge(adjacent);

                if(node_low_state[adjacent] >= node_state[node])
                {
                    articulation[node] = true;
                }
                if(node_low_state[adjacent] > node_state[node])
                {
                    // Bridge
                }

                node_low_state[node] = min(node_low_state[node],
                                           node_low_state[adjacent]);
            }
            else if(adjacent != parent_node[node])
                node_low_state[node] = min(node_low_state[node], node_state[adjacent]);
        }
    }

    void find_all_articulation_and_bridges()
    {
        memset(articulation, false, sizeof articulation);
        memset(node_state, UNVISITED, sizeof node_state);
        memset(node_low_state, UNVISITED, sizeof node_low_state);
        memset(parent_node, -1, sizeof parent_node);

        dfs_counter = 0;
        root_children = 0;

        for(int i = 0; i < n_nodes; ++i)
        {
            if(node_state[i] == UNVISITED)
            {
                dfs_root = i;
                root_children = 0;
                find_articulation_point_and_bridge(i);

                articulation[dfs_root] = root_children > 1;
            }
        }

    }


.. toctree::
   :maxdepth: 2
