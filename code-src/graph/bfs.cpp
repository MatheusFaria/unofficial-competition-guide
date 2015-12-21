#include <iostream>      // cout, endl
#include <algorithm>     // find
#include <vector>        // vector
#include <queue>         // queue
#include <unordered_set> // set


void bsf(std::vector<int> * G, int N)
{
    // Assuming that the nodes are sequentially created 1..(N - 1),
    // and 0 is a sentinel

    std::unordered_set<int> visited_nodes;

    // Counts how many disconnected graphs there are in G
    int sub_graphs_counter = 0;

    std::queue<int> to_visit;

    // While there are unvisited nodes
    for(int i = 1; i < N; ++i)
    {
        if(visited_nodes.count(i)) continue;

        sub_graphs_counter++;
        std::cout << "Sub-graph " << sub_graphs_counter << std::endl;

        // Visiting the first node
        int node = i;
        std::cout << node << " ";

        visited_nodes.insert(node);

        // Scheduling the node to visit its adjacents
        to_visit.push(node);

        while(!to_visit.empty())
        {
            // Getting a node that was schedule
            node = to_visit.front();
            to_visit.pop();

            // Visiting the adjacents of the node
            for(unsigned int j = 0; j < G[node].size(); j++)
            {
                int adjacent_node = G[node][j];

                // If the adjacent node was not visit yet
                if(!visited_nodes.count(adjacent_node))
                {
                    // Visit the adjacent node
                    std::cout << adjacent_node << " ";
                    visited_nodes.insert(adjacent_node);

                    // Schedule the adjacent node to check its neighbors
                    to_visit.push(adjacent_node);
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
    G[1] = std::vector<int> { 4, 3, 2 };
    G[2] = std::vector<int> { 5, 6, 4 };
    G[3] = std::vector<int> { 1 };
    G[4] = std::vector<int> { 7, 6, 1, 2 };
    G[5] = std::vector<int> { 2 };
    G[6] = std::vector<int> { 4, 2 };
    G[7] = std::vector<int> { 4 };
    G[8] = std::vector<int> { 9 };
    G[9] = std::vector<int> { 8 };

    std::cout << "BSF" << std::endl;
    bsf(G, N);

    delete[] G;

    return 0;
}

