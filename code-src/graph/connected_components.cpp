#include <iostream> // cout, endl
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

int main()
{
    // Creating a graph G with N nodes
    int N = 10;
    std::vector< std::vector<int> > G(N);

    // Making connections
    G[0] = std::vector<int> { 1 };
    G[1] = std::vector<int> { 2, 3, 4 };
    G[2] = std::vector<int> { 1, 5, 6, 4 };
    G[3] = std::vector<int> { 1 };
    G[4] = std::vector<int> { 7, 6, 1, 2 };
    G[5] = std::vector<int> { 2 };
    G[6] = std::vector<int> { 4, 2 };
    G[7] = std::vector<int> { 4 };
    G[8] = std::vector<int> { 9 };
    G[9] = std::vector<int> { 8 };

    dfs_connected_component_count(G);

    return 0;
}

/*
    Tested on: UVA459
*/
