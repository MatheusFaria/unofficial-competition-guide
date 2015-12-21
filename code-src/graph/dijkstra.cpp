#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>
#include <unordered_set>

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
