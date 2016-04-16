Strongly Connected Components
=============================

Tarjan's Algorithm
------------------

.. note::

    Tested on: UVA11838

.. code-block:: cpp

    #include <vector>    // vector
    #include <cstring>   // memset
    #include <algorithm> // min

    using namespace std;

    #define MAX 2010
    #define UNVISITED 0

    int node_state[MAX];    // memset to UNVISITED
    int node_low[MAX];      // memset to UNVISITED

    // flags if a node doesn't have its SCC defined yet
    bool not_in_a_scc[MAX]; // memset to false

    vector<int> node_stack;

    vector<int> G[MAX];
    int n_nodes; // Graph Size

    int dfs_counter; // initiliaze with 0
    int scc_counter; // initiliaze with 0

    void tarjan_SCC(int node)
    {
        /*
            Counts and identifies the Strogly Connected Components

            Complexity: O(E + V)
        */

        node_low[node] = node_state[node] = ++dfs_counter;
        node_stack.push_back(node);
        not_in_a_scc[node] = true; // the node is looking for its scc

        for(auto adjacent: G[node])
        {
            if(node_state[adjacent] == UNVISITED)
                tarjan_SCC(adjacent);

            if(not_in_a_scc[adjacent])
                node_low[node] = min(node_low[node], node_low[adjacent]);
        }

        if(node_low[node] == node_state[node])
        {
            scc_counter++;
            while(1)
            {
                auto adjacent = node_stack.back();
                node_stack.pop_back();
                not_in_a_scc[adjacent] = false; // the adjacent found its scc
                if(node == adjacent) break;
            }
        }
    }

    void find_all_SCC()
    {
        /*
            Runs the Tarjan SCC Algorithm in the whole graph
        */

        scc_counter = dfs_counter = 0;
        memset(not_in_a_scc, false, sizeof not_in_a_scc);
        memset(node_state, UNVISITED, sizeof node_state);
        memset(node_low, UNVISITED, sizeof node_low);

        for(int i = 0; i < n_nodes; ++i)
        {
            if(node_state[i] == UNVISITED)
            {
                tarjan_SCC(i);
            }
        }
    }


.. toctree::
   :maxdepth: 2
