#include <iostream>
#include <cstring>

/*
-- Graph represented as a matrix --

The most basic and primitive graph representation. Respresent the grah as a
square matrix of N by N, where N is the number of nodes. The connections between
nodes are stored in the cells.

For example, if you have the nodes [1, 2, 3, 4], and 1 is connected to 3 and 4,
2 is conencted to 1, 3 is connected to 1 2 and 4, and 4 has no connections. The
matrix will be:

                             | 1 2 3 4
                            ----------
                            1| 0 0 1 1
                            2| 1 0 1 0
                            3| 1 1 0 1
                            4| 0 0 0 0


This representation is good to answer queries that check if a node is connected
to another, because this operation is O(1). The downside of this representation
is that it take too much space to represent graphs that don't have too many
edges. Also, most of the algorithms are not designed to work with it.

In practice, this matrix will be an array of array (a.k.a matrix), or you can
use a linear array.

If the edges of your graph have weights, you can store this information in the
cells of your matrix. Otherwise, you can use a matrix of boolean to store the
connection.
*/

int connect(bool * graph, int N, int a, int b);

int main()
{
    // The size of my graph is 4, but I will use 5 to save the row and colunm 0
    // as a sentinel.
    int N = 5;

    bool * graph = new bool[N*N];
    memset(graph, false, N*N*sizeof(int));

    connect(graph, N, 1, 3);
    connect(graph, N, 1, 4);

    connect(graph, N, 2, 1);
    connect(graph, N, 2, 3);

    connect(graph, N, 3, 1);
    connect(graph, N, 3, 2);
    connect(graph, N, 3, 4);

    // Since for has no connections, then you don't need to specify it. Because
    // the whole matrix was initialized with the not connected space

    std::cout << "     1 2 3 4" << std::endl;
    for(int i = 1; i < N; i++)
    {
        std::cout << i << ": [ ";
        for(int j = 1; j < N; j++)
        {
            if(graph[j + i*N]) std::cout << 1 << " ";
            else std::cout << 0 << " ";
        }
        std::cout << "]" << std::endl;
    }

    delete[] graph;

    return 0;
}

// Connects node A to node B
int connect(bool * graph, int N, int a, int b)
{
    graph[b + a*N] = true;
    return 0;
}
