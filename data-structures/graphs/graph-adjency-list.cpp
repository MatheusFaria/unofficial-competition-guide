#include <iostream>
#include <vector>

/*
-- Graph represented as an Adjency List --

In this representation the n nodes of a graph are the entries of a list. And
each entry has a list of nodes. This list represents the nodes that are conected
to the node of that entry.

For example, if you have the nodes [1, 2, 3, 4], and 1 is connected to 3 and 4,
2 is conencted to 1, 3 is connected to 1 2 and 4, and 4 has no connections. The
list will be:

                    i : [list of nodes]
                    -------------------
                    1 : [3, 4]
                    2 : [1]
                    3 : [1, 2, 4]
                    4 : []

With this list you can represent directed and undirected graphs. And saves
space, because you only store connections that really exist. However, operations
like check if two nodes are connected are performed in linear time O(n).

* Most of graphs' algorithms use this representation

In pratice you can use any structure that maps to a list of nodes. Depending on
your data type and the complexity that you want to recover the information,
there are more approprieate data structures.

If you have a more dense data, e.g. [1, 2, 3, 4], as nodes you can use a vector
of vectors, or an array of vector. If your data is more sparse,
e.g. [1, 30, 100], it is better to use something like a map of vectors.

If the graph edges have a weight associated you can change each node in the list
to a tuple with both infomations (Node, weight).
*/

//Vector of vectors
using graph = std::vector< std::vector<int> >;

int main()
{
    graph G;

    // Index 0, does not exist on my graph, but to garantee the O(1) access to
    // any node I inserted it, since they follow the numeric order.
    G.push_back( std::vector<int> { } );

    // The graph used in the example above
    G.push_back( std::vector<int> { 3, 4 } );
    G.push_back( std::vector<int> { 1 } );
    G.push_back( std::vector<int> { 1, 2, 4 } );
    G.push_back( std::vector<int> { } );

    std::cout << "i : [list of nodes]" << std::endl;
    for(unsigned int i = 1; i <= 4; i++)
    {
        std::cout << i << " : [ ";
        for(unsigned int j = 0; j < G[i].size(); j++)
        {
            std::cout << G[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
