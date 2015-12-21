#include <iostream>      // cout, endl
#include <algorithm>     // find
#include <vector>        // vector
#include <stack>         // stack
#include <unordered_set> // set

void dfs_adjacency_list(std::vector<int> * G, int N)
{
    // Assuming that the nodes are sequentially created 1..(N - 1),
    // and 0 is a sentinel

    std::unordered_set<int> visited_nodes;

    // Stack of nodes starts empty
    std::stack<int> node_stack;

    // Subgraphs counter
    int sub_graphs_counter = 0;

    // While there are unvisited nodes
    for(int i = 1; i < N; ++i)
    {
        if(visited_nodes.count(i)) continue;

        // Counting the subgraphs
        sub_graphs_counter++;
        std::cout << "Subgraph " << sub_graphs_counter << std::endl;

        // Visting a node
        int node = i;
        visited_nodes.insert(node);
        std::cout << node << " ";

        // Putting a node into the stack to check its adjacents
        node_stack.push(node);

        while(!node_stack.empty())
        {
            // Removing a node from the stack to check its adjacetns
            node = node_stack.top();
            node_stack.pop();

            // Checking the adjacents
            for(auto adjacent: G[node])
            {
                // If the adjcent is not visited yet
                if(!visited_nodes.count(adjacent))
                {
                    // Visit the adjcent
                    std::cout << adjacent << " ";
                    visited_nodes.insert(adjacent);

                    // Push the adjacent into the stack
                    node_stack.push(adjacent);
                }
            }
        }

        std::cout << std::endl;
    }
}

int main()
{
    // Creating a graph G with N nodes
    int N = 10;
    std::vector<int> * G = new std::vector<int>[N];

    // Making connections
    G[0] = std::vector<int> { }; // Sentinel
    G[1] = std::vector<int> { 2, 3, 4 };
    G[2] = std::vector<int> { 1, 5, 6, 4 };
    G[3] = std::vector<int> { 1 };
    G[4] = std::vector<int> { 7, 6, 1, 2 };
    G[5] = std::vector<int> { 2 };
    G[6] = std::vector<int> { 4, 2 };
    G[7] = std::vector<int> { 4 };
    G[8] = std::vector<int> { 9 };
    G[9] = std::vector<int> { 8 };

    std::cout << "DSF" << std::endl;
    dfs_adjacency_list(G, N);

    delete[] G;
}

