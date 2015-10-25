#include <iostream> // cout, endl
#include <cstring>  // memset

//TODO: Explanation

using namespace std;

#define LSB(x) ((x) & -(x))

class FenwickTreePQRU {
public:
    int size;
    long long int * tree;

    FenwickTreePQRU(int _size)
    {
        // size + 1 because the position 0 is a sentinel
        size = _size + 1;

        tree = new long long int[size];
        memset(tree, 0, sizeof(long long int)*(size));
    }

    void range_update(int left, int right, long long int value)
    {
        /*
            range_update: updates a range [left, right] by adding a value
        */

        point_update(tree, left, value);
        point_update(tree, right + 1, -value);
    }

    long long int point_query(int position)
    {
        /*
            point_query: returns the value of a point in the tree
        */

        long long int sum = 0;

        while(position > 0)
        {
            sum += tree[position];
            position -= LSB(position);
        }

        return sum;
    }

private:

    // DO NOT use the point_update directly, the use of this function can cause
    // unpredictable results on the Fenwick Tree RQPU
    void point_update(long long int * tree, int position, int value)
    {
        /*
           point_update: updates one position in the tree and propagates the
                         changes to the other positions that `position` affects

                         Sum the "value" in each position influenced by "position"

           Example:
                initial state:
                tree -> {x, 1, 5, 0, 10, 6}
                size -> 5

                function call:
                update(1, 13)
                    loop 1:
                        tree -> {x, 14, 5, 0, 10, 6}
                    loop 2:
                        tree -> {x, 14, 18, 0, 10, 6}
                    loop 3:
                        tree -> {x, 14, 18, 0, 23, 6}

                # position 1 influence 1, 2, 4
        */

        // While didn't reach the tree root
        while(position <= size)
        {
            tree[position] += value;

            // Go to the parent node
            position += LSB(position);
        }
    }

};



int main()
{
    FenwickTreePQRU ft(10);

    //int values[] = {0, 1, 1, 1, 2, 2, 6, 6, 2, 9, 0};

    cout << "Build Tree:" << endl;
    ft.range_update(1, 3, 1);
    ft.range_update(4, 5, 2);
    ft.range_update(6, 7, 6);
    ft.range_update(8, 8, 2);
    ft.range_update(9, 10, 9);

    for(int i = 0; i < ft.size; i++)
        cout << ft.tree[i] << " ";
    cout << endl;
    cout << endl;


    cout << "Range Update [3, 7] with value +1:" << endl;
    ft.range_update(3, 7, 1);

    for(int i = 0; i < ft.size; i++)
        cout << ft.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Point Query [4]: " << ft.point_query(4) << endl;

    return 0;
}
