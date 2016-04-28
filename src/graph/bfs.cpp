#include <vector>   // vector
#include <queue>    // queue
#include <cstring>  // memset

#define MAX 10010

using namespace std;

vector<int> G[MAX]; // memset to 0
bool visited[MAX];  // memset to false

bool bfs(int start_node, int dest_node)
{
    /*
        Does the breadth first searh to find the dest_node starting from the
        start_node

        Coplexity: O(V + E)
    */

    queue<int> to_visit;
    to_visit.push(start_node);
    visited[start_node] = true;

    while(!to_visit.empty())
    {
        auto node = to_visit.front();
        to_visit.pop();

        for(auto adjacent: G[node])
        {
            if(start_node == dest_node) return true;
            else if(!visited[adjacent])
            {
                visited[adjacent] = true;
                to_visit.push(adjacent);
            }
        }
    }

    return false;
}

void bfs_traversal(int N)
{
    /*
        Traverse the graph using breadth first as criteria. Each node is only
        visite once.

        Coplexity: O(V + E)
        V: G.size()
        E: number of edges
    */

    memset(visited, false, sizeof visited);

    for(int i = 0; i < N; ++i)
    {
        if(visited[i]) continue;
        bfs(i, -1);
    }
}

/*
    Tested on: UVA11902
*/

int main()
{
    return 0;
}
