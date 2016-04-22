#include <vector>   // vector
#include <cstring>  // memset

using namespace std;

#define MAX 10010

vector<int> G[MAX]; // memset to 0
bool visited[MAX];  // memset to false

bool dfs(int node, int dest_node)
{
    /*
        Does the depth first search recursivily to find the dest_node starting
        from the current node

        Coplexity: O(V + E)
    */

    if(node == dest_node) return true;

    visited[node] = true;

    for(auto adjacent: G[node])
        if(!visited[adjacent])
            if(dfs(adjacent, dest_node)) return true;

    return false;
}

void dfs_traversal(int N)
{
    /*
        Traverse the graph using depth first as criteria

        Coplexity: O(V + E)
    */

    memset(visited, false, sizeof visited);

    for(int i = 0; i < N; ++i)
    {
        if(visited[i]) continue;
        dfs(i, -1);
    }
}

/*
    Tested on: UVA11902
*/

int main()
{
    return 0;
}

