#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 110

vector<int> G[MAX];
int W[MAX][MAX]; // Stores the edges weights -- memset to 0
int parent[MAX]; // Stores the nodes' parents -- memset to -1

int get_min_edge(int node, int min_edge, int source_node)
{
    if (node == source_node)
        return min_edge;
    // If the node has a parent
    else if (parent[node] != -1)
    {
        auto parent_node = parent[node];

        auto flow = get_min_edge(parent_node, min(min_edge, W[parent_node][node]), source_node);

        W[parent_node][node] -= flow; // Descreases flow
        W[node][parent_node] += flow; // Increases flow
        return flow;
    }

    return 0;
}

bool visited[MAX]; // memset to false

int max_flow_edmonds_karp(int source_node, int target_node)
{
    /*
        Finds the max flow of a directed weighted graph

        !! All edges must have a backward edge, they will have different weights

        Complexity: O(V * E^2)
    */

    int max_flow = 0, flow;
    while (true)
    {
        flow = 0;

        // Using BFS to build the parent array
        queue<int> to_visit;
        memset(visited, false, sizeof visited);
        memset(parent, -1, sizeof parent);

        visited[source_node] = true;
        to_visit.push(source_node);

        while(!to_visit.empty())
        {
            auto node = to_visit.front();
            to_visit.pop();

            if (node == target_node) break;

            for(auto adjacent: G[node])
            {
                // Excludes the edges without flow and already visited
                if (W[node][adjacent] > 0 and not visited[adjacent])
                {
                    visited[adjacent] = true;
                    to_visit.push(adjacent);
                    parent[adjacent] = node;
                }
            }
        }

        // Get the minimum edge value from source to target
        flow = get_min_edge(target_node, numeric_limits<int>::max(), source_node);
        if (flow == 0) break; // No more flow in the graph

        max_flow += flow;
    }

    return max_flow;
}

/* Variants:
        Min Cut: searchs for the minimum edges to disconnect the graph in two
                 components
        Multi-Source Multi-Sink: create a super source that connects to all sources,
            create a super sink that connects to all sinks, both with infinite capacities
        Vertex Capacity: when the vertice has a capacity, besides the edges,
            you need to duplicate the vertices and connect them with their
            capacity as the edge value
*/


int main()
{
    return 0;
}

/*
    Tested On: UVA820, UVA259
*/
