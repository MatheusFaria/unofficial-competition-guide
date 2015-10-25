#include <iostream>      // cout, endl
#include <algorithm>     // find
#include <vector>        // vector
#include <stack>         // stack
#include <unordered_set> // set

/*
-- Depth First Search --

DFS is a algorithm to perform graph traversals. It start at a node and follows
a path until the farthest node without adjacents, then goes back one node and
explore the unvisited adjacents.

In this same algorithm you can count the number o subgraphs that a graph has.
But, for that be possible, the graph needs to be undirected. Otherwise, the
number of subgraphs can vary based on the starting node.

--- Algorithm outline ---

    G -> graph
    unvisited_nodes -> list of nodes
    node_stack -> empty

    for each node in unvisited_nodes:
        visit node
        push node in node_stack

        while node_stack is not empty:
            node -> pop node_stack top node

            for each adjacent connected to node:
                if adjacent is unvisited:
                    visit adjacent
                    push adjacent in node_stack
                    break

--- Complexity ---

The complexity is linear on the number of nodes, and for each node the algorithm
executes for its adjacents, which is the degree of that node. The sum of all
degrees is twice the number of edges. The complexity is O(N + 2M). By removing
the constants:

                                O(N + M)

--- Example ---

For example, the graph listed below:

1 : [2, 3, 4]
2 : [5, 6, 4]
3 : [1]
4 : [7, 6, 1, 2]
5 : [2]
6 : [4, 2]
7 : [4]
8 : [9]
9 : [8]

If the starting point is 1, them 1 will be stacked. Then its goes on the first
unvisted adjacent node and visit it, in this case 2. It will stack 2, and go to
the first unvisted adjacet of 2, which is 5. So on so forth. When it pops all
elements from the stack and gets into 1 again, it will look to the other
adjacents nodes, if they were not visit at this point, it will visit them by
repeating the process.

The algorithm starting at 1 should output:


Sub-Graph 1
1 2 5 6 4 7 3

Sub-Graph 2
8 9
*/

// Uses the adjency list graph representation to execute the DFS
void dfs_adjacency_list(std::vector<int> * G, int N);

// Uses the matrix graph representation to execute the DFS
void dfs_matrix(bool * G, int N);

int main()
{
    // Creating a graph G with N nodes
    int N = 10;
    std::vector<int> * G = new std::vector<int>[N];

    // Making connections
    G[0] = std::vector<int> { }; // Sentinel
    G[1] = std::vector<int> { 2, 3, 4 };
    G[2] = std::vector<int> { 5, 6, 4 };
    G[3] = std::vector<int> { 1 };
    G[4] = std::vector<int> { 7, 6, 1, 2 };
    G[5] = std::vector<int> { 2 };
    G[6] = std::vector<int> { 4, 2 };
    G[7] = std::vector<int> { 4 };
    G[8] = std::vector<int> { 9 };
    G[9] = std::vector<int> { 8 };

    std::cout << "BSF - List of Adjacents" << std::endl;
    dfs_adjacency_list(G, N);

    delete[] G;

    std::cout << std::endl;

    // Creating a graph as a matrix
    bool * graph = new bool[N*N];
    memset(graph, false, N*N*sizeof(bool));

    // Creating the edges from A to B -> A*N + B
    graph[1*N + 2] = true;
    graph[1*N + 3] = true;
    graph[1*N + 4] = true;

    graph[2*N + 5] = true;
    graph[2*N + 6] = true;
    graph[2*N + 4] = true;

    graph[3*N + 1] = true;

    graph[4*N + 7] = true;
    graph[4*N + 6] = true;
    graph[4*N + 1] = true;
    graph[4*N + 2] = true;

    graph[5*N + 2] = true;

    graph[6*N + 4] = true;
    graph[6*N + 2] = true;

    graph[7*N + 4] = true;

    graph[8*N + 9] = true;

    graph[9*N + 8] = true;

    std::cout << "BSF - Matrix" << std::endl;
    dfs_matrix(graph, N);

    delete[] graph;
    return 0;
}

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

            // If all ajacents nodes of node were visit, then this node can be
            // removed from the stack
            bool all_adjacent_visited = true;

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

                    // Go to check the neighbors of the adjacent node
                    all_adjacent_visited = false;
                    break;
                }
            }

            if(all_adjacent_visited) node_stack.pop();
        }

        std::cout << std::endl;
    }
}

void dfs_matrix(bool * G, int N)
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

            // If all ajacents nodes of node were visit, then this node can be
            // removed from the stack
            bool all_adjacent_visited = true;

            // Checking the adjacents
            for(int j = 0; j < N; j++)
            {
                if(G[node*N + j])
                {
                    int adjacent_node = j;

                    // If the adjcent is not visited yet
                    if(!visited_nodes.count(adjacent_node))
                    {
                        // Visit the adjcent
                        std::cout << adjacent_node << " ";
                        visited_nodes.insert(adjacent_node);

                        // Push the adjacent into the stack
                        node_stack.push(adjacent_node);

                        // Go to check the neighbors of the adjacent node
                        all_adjacent_visited = false;
                        break;
                    }
                }
            }

            if(all_adjacent_visited) node_stack.pop();
        }

        std::cout << std::endl;
    }
}
