#include <algorithm>

using namespace std;

#define MAX 405
#define INITIAL_VALUE 100000000

int G[MAX][MAX]; // intializates it with a large number

void floyd_warshall(int V)
{
    /*
        Computes all-pairs shortest paths
        !! Use it for small graphs (V <= 400)
        Complexity: O(V^3)

        Notes:
              > After running this algorithm, values in the matrix diagonal
                indicates the existance of cycles. The value will be the
                minimum length of that cycle

              > It can detect negative cycles with one pass of the algorithm,
                if the diagonal has a negative number.

              > If a value inside the matrix stays infinity those two vertices
                are disconected
    */

    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

void init_G_matrix(int V)
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if(i == j) G[i][j] = 0;
            else G[i][j] = INITIAL_VALUE;
        }
    }
}

int main()
{
    return 0;
}

/*
    Tested on: UVA821
*/
