#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>
#include <unordered_set>

/*
-- Dijkstra Algorithm --

Dijkstra algorithm is an algorithm to find the shortest path in a graph, where
the edeges can be weighted. The algorithm starts in the source node, and
schedules its neighboors to be visited, then it visits them and repeats the
process until it find the target node. It is like a BFS traverssal, but instead
of visiting every node in the order that they are enqueued, it uses the edge
weight to order the nodes to be visted.

This algorithm does not support negative weights, iff the negative weight is in
an undirected cicle. If you are working with DAGs or the negative weight is in
a edge that is not part of a cicle, you still can use the dijkstra algorithm.
The problem is that dijkstra always finds the lowest cost to a given vertex, and
during the process it visits/closes each vertex, giving the shortest path to
that vertex. If the weights are all positive this cost can only increase, if
there is a negative weight this cost can decrease, and you can find a new
shorstest path to a vertex that was already closed.

Example:


       A
      / \
     /   \
    /     \
   5       2
  /         \
  B--(-10)-->C---20--->D

V={A,B,C,D} ; E = {(A,C,2), (A,B,5), (B,C,-10), (C, D, 20)}

First it will find the path from A to C at cost of 2, and will close C. Then
it will find the cost from A to B at cost of 5, and will close B. Then it will
find a path A -> B -> C at cost of -5, and the vertex C that was already closed
now has a new shortest path. If you want the shortest path to D, dijkstra will
give you (A - C - D: 22), because (A - C) is closed with the value of 2. But
the correct answer is (A - B - C - D: 15).

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
*/

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first > b.first;
}

int shortest_path_dijkstra(int a, int b, vector< pair<int, int> > *  G, int N)
{
    vector<int> shortest_paths;
    for(int i = 0; i <= N; i++)
        shortest_paths.push_back(numeric_limits<int>::max());

    unordered_set<int> visited_nodes;
    priority_queue< pair<int, int>, vector< pair<int, int> >, decltype(&comp) > to_visit(&comp);

    pair<int, int> node(0, a);
    to_visit.push(node);

    while(!to_visit.empty())
    {
        node = to_visit.top();
        to_visit.pop();

        if(node.second == b) return node.first;

        if(!visited_nodes.count(node.second))
        {
            visited_nodes.insert(node.second);
            shortest_paths[node.second] = node.first;

            for(unsigned int j = 0; j < G[node.second].size(); j++)
            {
                pair<int, int> adjacent_node = G[node.second][j];
                adjacent_node.first += node.first;
                to_visit.push(adjacent_node);
            }
        }
    }

    return numeric_limits<int>::max();
}

int main()
{
    int N = 8;
    vector< pair<int, int> > * G = new vector< pair<int, int> >[N + 1];


    G[1].push_back(make_pair(6, 3));
    G[1].push_back(make_pair(3, 2));
    G[1].push_back(make_pair(4, 4));
    G[2].push_back(make_pair(2, 6));
    G[3].push_back(make_pair(3, 7));
    G[3].push_back(make_pair(1, 5));
    G[4].push_back(make_pair(1, 3));
    G[5].push_back(make_pair(2, 8));
    G[6].push_back(make_pair(1, 8));
    G[7].push_back(make_pair(10, 8));
    G[8] = vector< pair<int, int> >();

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << "Shortest Distance from " << i << " to " << j << ": " << shortest_path_dijkstra(i, j, G, N) << endl;
        }
    }

    delete[] G;

    return 0;
}
