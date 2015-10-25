#include <iostream>      // cout, endl
#include <algorithm>     // find
#include <vector>        // vector
#include <queue>         // queue
#include <unordered_set> // set

/*
-- Breadth Frist Search --

BFS is a way to traverse any graph without getting lost in the loops or passing
twice through an edge or a node. In this traverse, the nodes that are closer to
the initial node will be visited first, than their neighboor, so on so forth.

One way to think about this algorithm is: first, it will visit all the nodes
that have distance of 0 from the start node, which means the node itself; then
it will visit those that have distace of 1, a.k.a. the adjancet nodes; then
those that have distance of 3, so on and so forth.

With this same algortihm you can count the number of not connect graphs inside
one graph. But you can do this if and only if the graph is acyclic.

--- Algorithm outline ---

    G -> graph
    unvisited_nodes -> set of all nodes
        check_adjacents -> empty queue

        for each node in unvisited_nodes:
            visit node
            enqueue node in check_adjacents

            while check_adjacents is not empty:
                node -> dequeue check_adjacents front node

                for each adjacent connected to node:
                    if adjacent is unvisited:
                        visit adjacent
                        enqueue adjacent in check_adjacents

--- Complexity ---

There are N nodes in the Graph. For each node its adjacents will be checked.
Chencking the adjacent of a node is linear on the node degree O(degree(N)).
Checking all the adjancents of all node is O(2M), where M is the number of
edges. The complexity of everything is O(N + 2M), removing the constants:

                                O(N + M)

It is not O(N^2), because to be like this for every node it should check all the
edges. And it just check the degrees.

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

The algorithm will pick the first unvisited node, which is 1. It is going to
visit 1 and put it on the queue to check its neighbours. Then will dequeue 1,
and check its adjacents, each not visited adjacent is visited and enqueued.
In this case, it will visit and enqueue [2, 3, 4]. Then it will dequeue the next
node, 2. And will check its adjcents, visit and enqueue them. The process will
be repeated until the the queue is not empty. When the queue is empty, it will
check if still there is an unvisited node, in this case [8, 9]. It will start
the same process for 8.

The algorithm starting at 1 should output:

Distance: nodes

Sub-Graph 1
0: 1
1: 2 3 4
2: 5 6
3: 7

Sub-Graph 2
0: 8
1: 9
*/

// BFS using the list of adjacents as a graph
void bsf_adjacency_list(std::vector<int> * G, int N);

// BFS  using the matrix as a graph
void bsf_matrix(bool * G, int N);

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

    std::cout << "BSF - List of Adjacents" << std::endl;
    bsf_adjacency_list(G, N);

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
    bsf_matrix(graph, N);

    delete[] graph;
    return 0;
}

void bsf_adjacency_list(std::vector<int> * G, int N)
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

void bsf_matrix(bool * G, int N)
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
            for(int j = 1; j < N; j++)
            {
                // If there is a connection between the node and this adjancent
                // candidate node

                if(G[node*N + j])
                {
                    int adjacent_node = j;

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
        }
        std::cout << std::endl;
    }
}
