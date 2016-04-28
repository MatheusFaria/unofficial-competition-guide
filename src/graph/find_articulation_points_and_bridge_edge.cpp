#include <cstdio>    // scanf, printf
#include <vector>    // vector
#include <algorithm> // min
#include <cstring>   // memset
#include <set>       // set
#include <utility>   // pair, make_pair

using namespace std;

#define MAX 110
#define UNVISITED -1

vector<int> G[MAX];
int node_num[MAX]; // memset to -1
int node_low[MAX]; // memset to -1
int parent[MAX];   // memset to -1

int dfs_counter;         // start at 0
int dfs_root;            // stores the first node visited
int root_children_count; // counts the root children

bool articulations[MAX]; // memset to false; stores the articulations
set< pair<int, int> > bridges;  // stores the bridges

void find_articulation_and_bridges_dfs(int node)
{
    /*
        Find vertices and edges that if deleted the graph becomes
        disconnected

        !Only works on undirected graphs!

        Complexity: O(E + V)
    */

    node_num[node] = node_low[node] = dfs_counter++;

    for(auto adjacent: G[node])
    {
        if(node_num[adjacent] == UNVISITED)
        {
            parent[adjacent] = node;
            if(node == dfs_root) root_children_count++;

            find_articulation_and_bridges_dfs(adjacent);

            if(node_low[adjacent] >= node_num[node]) // Articulation found
                articulations[node] = true;
            if(node_low[adjacent] > node_num[node]) // Bridge found
                bridges.insert(make_pair(node, adjacent));

            node_low[node] = min(node_low[node], node_low[adjacent]);
        }
        // If the adj was already visted and is not a bidirectional
        // edge pointing to the node that called the adj
        else if(adjacent != parent[node])
            node_low[node] = min(node_low[node], node_num[adjacent]);
    }
}

void find_articulation_and_bridges(int start_node)
{
    /* Setup the variables to use the method */

    memset(node_num, UNVISITED, sizeof node_num);
    memset(node_low, UNVISITED, sizeof node_low);
    memset(parent, UNVISITED, sizeof parent);
    memset(articulations, false, sizeof articulations);
    bridges.clear();

    dfs_counter = root_children_count = 0;

    dfs_root = start_node;
    find_articulation_and_bridges_dfs(dfs_root);

    articulations[dfs_root] = root_children_count > 1;
}

int main()
{
    return 0;
}

/*
    Tested on: UVA315, URI1709
*/
