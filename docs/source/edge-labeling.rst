Edge Labeling
=============

.. warning::

    NOT TESTED

.. code-block:: cpp

    #include <cstdio>
    #include <vector>

    using namespace std;

    #define MAX 100

    enum States {UNVISITED, VISITED, EXPLORED};

    /*
        UNVISTED - not visited yet
        VISTED   - visited and all edges checked
        EXPLORED - visited but with unchecked edges
    */

    int parent_node[MAX];
    States node_state[MAX];
    vector<int> G[MAX];

    void graphCheck(int node)
    {
        /*
            Maps every edge on a graph
            Useful for cycle detection
            Complexity: O(E + V)
        */

        node_state[node] = EXPLORED;

        for(auto adjacent: G[node])
        {
            // Edge: EXPLORED -> UNVISTED
            if(node_state[adjacent] == UNVISITED)
            {
                parent_node[adjacent] = node;
                graphCheck(adjacent);
            }
            // Edge: EXPLORED -> EXPLORED
            else if(node_state[adjacent] == EXPLORED)
            {
                if(adjacent == parent_node[node])
                {
                    // Undirected / Two ways
                }
                else
                {
                    // Back edge / Cycle
                }
            }
            // Edge: EXPLORED -> VISITED
            else if(node_state[adjacent] == VISITED)
            {
                // Foward Edge / Cycle / Cross Edge
            }
        }

        node_state[node] = VISITED;
    }

.. toctree::
   :maxdepth: 2
