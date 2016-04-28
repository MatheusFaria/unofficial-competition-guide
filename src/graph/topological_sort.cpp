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


int main()
{
    // Creating a graph G with N nodes
    int N = 8;
    vector< vector<int> > G;
    G.assing(N, vector<int>());

    // Making connections
    G[0] = vector<int> { 1, 2 };
    G[1] = vector<int> { 3, 4 };
    G[2] = vector<int> { 5, 6 };
    G[3] = vector<int> { 6 };
    G[4] = vector<int> { 5 };
    G[5] = vector<int> { 7 };
    G[6] = vector<int> { 8 };

    topological_sort_traversal(G);

    return 0;
}

/*
    Tested on: UVA200
*/
