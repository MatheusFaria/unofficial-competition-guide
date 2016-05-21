#include <vector>    // vector
#include <limits>    // numeric_limits
#include <algorithm> // fill, min
#include <utility>   // pair

using namespace std;

#define MAX 10000

vector< pair<int, int> > G[MAX];
int distances[MAX]; // fill with infinite

int bellman_ford_sssp(int source, int target, int N)
{
    fill(distances, distances + N, numeric_limits<int>::max());

    distances[source] = 0;

    for(int i = 0; i < N - 1; ++i)
    {
        for(int node = 0; node < N; ++node)
        {
            for(auto adjacent: G[node])
            {
                auto v = adjacent.first;
                auto w = adjacent.second;
                distances[v] = min(distances[v], distances[node] + w);
            }
        }
    }


    // Negative Cycle check

    bool hasNegativeCycle = false;
    for(int node = 0; node < N; ++node)
    {
        for(auto adjacent: G[node])
        {
            auto v = adjacent.first;
            auto w = adjacent.second;
            if(distances[v] > distances[node] + w)
            {
                hasNegativeCycle = true;
                break;
            }
        }
    }

    return distances[target];
}

int main()
{
    return 0;
}

/*
    Tested on: UVA558
*/
