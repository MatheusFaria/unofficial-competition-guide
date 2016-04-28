#include <iostream> // cout, endl
#include <vector>   // vector
#include <queue>    // queue
#include <cstring>  // memset

using namespace std;

bool bipartite_check(vector<int> G[], int n_nodes)
{
    /*
        Checks if the graph G is bipartite.
        Works only on undirected strongly connected graphs.

        Complexity: O(V + E)
    */

    queue<int> to_visit;
    int * color = new int[n_nodes];

    to_visit.push(0);
    memset(color, -1, sizeof(int)*n_nodes);
    color[0] = 1;

    bool is_bipartite = true;

    while(!to_visit.empty() && is_bipartite)
    {
        auto node = to_visit.front();
        to_visit.pop();

        for(auto adjancent: G[node])
        {
            if(color[adjancent] == -1)
            {
                color[adjancent] = 1 - color[node];
                to_visit.push(adjancent);
            }
            else if(color[adjancent] == color[node])
            {
                is_bipartite = false;
                break;
            }
        }
    }

    return is_bipartite;
}

int main()
{
    return 0;
}

/*
    Tested on: UVA10004
*/
