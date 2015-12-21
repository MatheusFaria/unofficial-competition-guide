#include <iostream>
#include <limits>

using namespace std;

#define N_CITIES 11

int distances[N_CITIES][N_CITIES];

/*
TESTED ON:
UVA: 10496
*/

// Given N cities, what is the shortes path passing through them all?
// All the cities must be interconnected with each other
// The origin is the matrix 0 0
int tsp(int i_city, int visited_cities, int n_cities)
{
    int min_distance = numeric_limits<int>::max();
    for(int i = 0; i < n_cities; i++)
    {
        if(i == i_city) continue;

        if(!(visited_cities & (1 << i)))
        {
            int current_distance = tsp(i, visited_cities | (1 << i), n_cities)
                                    + distances[i][i_city];
            min_distance = min(current_distance, min_distance);
        }
    }

    // Passed through all cities
    if(min_distance == numeric_limits<int>::max()) return distances[i_city][0];

    return min_distance;
}


int main()
{

    // Populate Distances

    // Then...
    cout << tsp(0, 1, n) << endl;
    return 0;
}
