#include <iostream> // cout, endl
#include <vector>   // vector
#include <stack>    // stack
#include <cstring>  // memset

using namespace std;

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
/*
    Tested on: UVA11902
*/

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

    dfs(G, 0);
    dfs_traversal(G);

    return 0;
}

