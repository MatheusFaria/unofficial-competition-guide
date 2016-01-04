Connected Components Count
==========================

A small adaptation of the :doc:`dfs` algorithm, allow us to count the number of
connected components on a undirected graph.

.. note::

    Tested on: UVA459

.. code-block:: cpp

    #include <vector>   // vector
    #include <stack>    // stack
    #include <cstring>  // memset

    using namespace std;

    int dfs_connected_component_count(vector< vector<int> > G)
    {
        /*
            Counts the connected components inside your graph.

            Coplexity: O(V + E)
            V: G.size()
            E: number of edges
        */

        stack<int> to_traverse;
        bool * visited = new bool[G.size()];
        memset(visited, 0, G.size());

        int count_cc = 0;

        for(unsigned int node_i = 0; node_i < G.size(); ++node_i)
        {
            if(visited[node_i]) continue;
            count_cc++;

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

        return count_cc;
    }

.. toctree::
   :maxdepth: 2
