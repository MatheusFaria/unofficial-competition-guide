Topological Sort
================

Topological Sort with DFS
-------------------------

.. note::

    Tested on: UVA200

.. code-block:: cpp

    #include <iostream> // cout, endl
    #include <vector>   // vector
    #include <cstring>  // memset

    using namespace std;

    #define MAX 100

    bool visited[MAX]; // memset it to false
    vector<int> topological_sort_vector; // Stores the result

    void topological_sort_dfs(vector< vector<int> > G, int node)
    {
        /*
            Does the topological sort from a source node.

            Complexity: O(E + V)
        */

        visited[node] = true;
        for(auto adjacent: G[node])
            if(!visited[adjacent])
                topological_sort_dfs(G, adjacent);

        topological_sort_vector.push_back(node);
    }

    void topological_sort_traversal(vector< vector<int> > G)
    {
        /*
            Returns one possible topological order to the DAG G.

            Complexity: O(E + V)
        */

        memset(visited, false, MAX);
        topological_sort_vector.clear();

        for(unsigned int i = 0; i < G.size(); ++i)
            if(!visited[i])
                topological_sort_dfs(G, i);
    }

Khan's Topological Sort
-----------------------

.. note::

    Tested on: UVA11060

.. code-block:: cpp

    #include <iostream>   // cout, endl
    #include <queue>      // priority_queue
    #include <vector>     // vector
    #include <functional> // greater

    #define MAX 110

    using namespace std;

    vector<int> topological_sort_kahn(vector<int> G[], int n_nodes, int indegree_count[])
    {
        /*
            Returns a topological order of the DAG G. This order follows some priority,
            the one chosen in this implementation is the smallest id first. But you
            can adapt it to your problem.

            !! This algorithm can decect cycles (see the last lines)

            Complexity: O(V + E)
        */

        vector<int> topological_order;

        // Gives priority to the smallest node id.
        priority_queue< int, vector<int>, greater<int> > indegree_zero_nodes;
        // Inserts all nodes that do not have incoming edges in a queue
        // !! You can do this process on the input, and pass the intial queue
        //    to this method.
        for(int i = 0; i < n_nodes; ++i)
            if(indegree_count[i] == 0) indegree_zero_nodes.push(i);

        while(!indegree_zero_nodes.empty())
        {
            auto node = indegree_zero_nodes.top();
            indegree_zero_nodes.pop();

            topological_order.push_back(node);

            for(auto adjacent: G[node])
            {
                // "Removing" the edge from that node
                indegree_count[adjacent]--;

                if(indegree_count[adjacent] == 0)
                    indegree_zero_nodes.push(adjacent);
            }
        }

        //if(n_nodes != topological_order.size())
        //    return NULL; // ERROR: This graph has at least one cycle

        return topological_order;
    }

.. toctree::
   :maxdepth: 2
