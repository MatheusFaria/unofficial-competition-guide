#include <cstdio>    // scanf, printf
#include <vector>    // vector
#include <cstring>   // memset
#include <algorithm> // min

#define MAX 1000
#define UNVISITED -1

using namespace std;

vector<int> G[MAX];

int node_num[MAX]; // memset to UNVISITED
int node_low[MAX]; // memset to UNVISITED

// flags if a node doesn't have its SCC defined yet
bool not_in_scc[MAX];   // memset to false
vector<int> node_stack; // Stores the nodes in the SCC

int dfs_counter; // start at 0
int scc_counter; // start at 0

void tarjan_SCC_dfs(int node)
{
    /*
        Counts and identifies the Strogly Connected Components

        Complexity: O(E + V)
    */

    node_low[node] = node_num[node] = dfs_counter++;
    node_stack.push_back(node);

    // This node is looking for a SCC
    not_in_scc[node] = true;

    for(auto adjacent: G[node])
    {
        if(node_num[adjacent] == UNVISITED)
            tarjan_SCC_dfs(adjacent);

        // If the adjacent is looking for a SCC, the node_low is update with
        // the adjacent node_low
        if(not_in_scc[adjacent])
            node_low[node] = min(node_low[node], node_low[adjacent]);
    }

    if(node_low[node] == node_num[node])
    {
        // A new SCC was found

        scc_counter++;
        int scc_node;

        // Iterates over the SCC found
        do {
            scc_node = node_stack.back();
            node_stack.pop_back();
            not_in_scc[scc_node] = false;
        } while(node != scc_node);
    }
}

void tarjan_SCC(int N)
{
    /* Finds all SCC in a graph of size N */

    memset(node_num, UNVISITED, sizeof node_num);
    memset(node_low, UNVISITED, sizeof node_low);
    memset(not_in_scc, false, sizeof not_in_scc);

    node_stack.clear();

    dfs_counter = scc_counter = 0;

    for(int i = 0; i < N; ++i)
        if(node_num[i] == UNVISITED)
            tarjan_SCC_dfs(i);
}

int main()
{
    return 0;
}

/*
    Tested on: UVA11838, UVA247, URI1128
*/
