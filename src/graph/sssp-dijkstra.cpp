#include <functional> // greater
#include <vector>     // vector
#include <queue>      // priority_queue
#include <limits>     // numeric_limits
#include <utility>    // pair
#include <algorithm>  // fill

using namespace std;

#define MAX 1000

using ii = pair<int, int>;

vector<ii> G[MAX]; // Adjacent list with elements == (weight, node)

int dijkstra_sssp(int source_node, int target_node, int N)
{
    /*
        Finds the shortest path in a weighted graph

        Complexity: O((V + E) log(V))
    */

    // Initially all distances are infinity
    int distances[MAX];
    fill(distances, distances + N + 1, numeric_limits<int>::max());

    // The distance to the source_node is always 0
    distances[source_node] = 0;

    priority_queue<ii, vector<ii>, greater<ii> > to_visit;
    to_visit.push(ii(distances[source_node], source_node));

    while(!to_visit.empty())
    {
        auto distance = to_visit.top().first;
        auto node     = to_visit.top().second;
        to_visit.pop();

        // If a smaller distance were already found, skip the current one
        if(distance > distances[node]) continue;

        for(auto adjacent: G[node])
        {
            auto dist = adjacent.first;
            auto adj  = adjacent.second;

            // current node distance + edge weight < adjacent node distance
            if(distances[node] + dist < distances[adj])
            {
                // Update with smaller distance
                distances[adj] = distances[node] + dist;
                to_visit.push(ii(distances[adj], adj));
            }
        }
    }

    return distances[target_node];
}

int main()
{
    return 0;
}

/*
    Tested on: URI1148
*/
