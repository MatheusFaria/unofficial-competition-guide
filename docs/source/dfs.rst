Depth First Search
==================

It is a way of traversing a graph with depth first as criteria.

The codes presented on this section use the adjency list graph representation,
but can be adpated for the others representations as well.

DFS
---

.. note::

    Tested on: UVA11902

.. code-block:: cpp

    #include <vector>  // vector
    #include <stack>   // stack
    #include <cstring> // memset

    void dfs(vector< vector<int> > G, int start_node)
    {
        /*
            Does the depth first starting on the start_node

            Coplexity: O(V + E)
            V: G.size()
            E: number of edges
        */

        stack<int> to_traverse;
        bool * visited = new bool[G.size()];
        memset(visited, 0, G.size());

        visited[start_node] = true;
        to_traverse.push(start_node);

        while(!to_traverse.empty())
        {
            auto node = to_traverse.top();
            to_traverse.pop();

            for(auto i: G[node])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    to_traverse.push(i);
                }
            }
        }
    }


DFS Traversal
-------------

.. warning::

    NOT TESTED

.. code-block:: cpp

    #include <vector>   // vector
    #include <stack>    // stack
    #include <cstring>  // memset

    void dfs_traversal(vector< vector<int> > G)
    {
        /*
            Traverse the graph using depth first as criteria. Each node is only
            visite once.

            Coplexity: O(V + E)
            V: G.size()
            E: number of edges
        */

        stack<int> to_traverse;
        bool * visited = new bool[G.size()];
        memset(visited, 0, G.size());

        for(unsigned int node_i = 0; node_i < G.size(); ++node_i)
        {
            if(visited[node_i]) continue;

            visited[node_i] = true;
            to_traverse.push(node_i);

            while(!to_traverse.empty())
            {
                auto node = to_traverse.top();
                to_traverse.pop();

                for(auto i: G[node])
                {
                    if(!visited[i])
                    {
                        visited[i] = true;
                        to_traverse.push(i);
                    }
                }
            }
        }
    }

.. toctree::
   :maxdepth: 2
