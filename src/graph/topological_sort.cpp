#include <vector>   // vector
#include <cstring>  // memset

using namespace std;

#define MAX 100

vector<int> G[MAX];
bool visited[MAX]; // memset it to false
vector<int> topological_sort_vector; // Stores the result

void topological_sort_dfs(int node)
{
    /*
        Does the topological sort from a source node.

        Complexity: O(E + V)
    */

    visited[node] = true;
    for(auto adjacent: G[node])
        if(!visited[adjacent])
            topological_sort_dfs(adjacent);

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
    return 0;
}

/*
    Tested on: UVA200
*/
