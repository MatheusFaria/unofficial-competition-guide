#include <vector>     // vector
#include <algorithm>  // sort
#include <utility>    // pair

using namespace std;

#define MAX 400010

class UFDS {
public:
    int parents[MAX];
    int heights[MAX]; // the size of each set
    int n_sets;       // how many sets are in the UFDS

    UFDS(int size)
    {
        // Zero base union find, the elements goes from 0 to N - 1
        // If you need to change the the interval, increase the size OR
        // change the for below
        for(int i = 0; i < size; ++i)
        {
            heights[i] = 1;
            parents[i] = i;
        }

        n_sets = size;
    }

    int find_set(int i) // find the set of node i
    {
        if(parents[i] != i)
            parents[i] = find_set(parents[i]);
        return parents[i];
    }

    inline bool same_set(int x, int y) // checks if x and y are in the same set
    {
        return find_set(x) == find_set(y);
    }

    void union_set(int x, int y) // unite x and y in the same set
    {
        int root1 = find_set(x), root2 = find_set(y);

        if(root1 != root2) // x and y are not in the same set
        {
            // The larger set absorb the smaller set
            if(heights[root1] < heights[root2]) swap(root1, root2);

            parents[root2] = root1;
            heights[root1] += heights[root2];

            n_sets--; // On each union the UFDS reduces one set in size
        }
    }
};

// Graph as an edge list with a cost
// the elements are (weight, (node1, node2))
vector< pair<int, pair<int, int> > > G;
// You can also use a priority_queue as the main data structure

int kruskal_mst_cost(int N)
{
    /*
        Complexity: O(E log V)
    */

    // !!! If the edges' weight lies in a small range, you can use counting
    // sort to speed up the process
    sort(G.begin(), G.end());

    int cost = 0;
    int edges_count = 0;
    UFDS ufds(N);

    for(auto edge: G)
    {
        auto weight = edge.first;
        auto u = edge.second.first, v = edge.second.second;

        if(!ufds.same_set(u, v))
        {
            cost += weight;
            edges_count++;
            if(edges_count == N - 1) break;

            ufds.union_set(u, v);
        }
    }

    return cost;
}

int main()
{
    return 0;
}

/*
    Tested on: UVA11631, URI1152, URI1764, UVA908
*/
