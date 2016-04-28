#include <iostream> // cout, endl
#include <cstring>  // memset

using namespace std;

#define LSB(x) ((x) & -(x))

class FenwickTreeRQRU {
public:
    int size;
    long long int * tree1;
    long long int * tree2;

    FenwickTreeRQRU(int _size)
    {
        // size + 1 because the position 0 is a sentinel
        size = _size + 1;

        tree1 = new long long int[size];
        memset(tree1, 0, sizeof(long long int)*(size));

        tree2 = new long long int[size + 1];
        memset(tree2, 0, sizeof(long long int)*(size));
    }

    void range_update(int left, int right, long long int value)
    {
        /*
            range_update: updates a range [left, right] by adding a value

            Complexity: O(log n)
        */

        // Updating the first tree just like a RQPU Fenwick tree
        point_update(tree1, left, value);
        point_update(tree1, right + 1, -value);

        // Updating the second tree just like a RQPU Fenwick tree, but with
        // a diferent value
        point_update(tree2, left, (left - 1)*value);
        point_update(tree2, right + 1, -value*right);
    }

    long long int RSQ(int initial, int final)
    {
        /*
            RSQ (Range Sum Query): returns the sum of the range [intial, final]

            Complexity: O(log n)
        */

        // if the range starts with 1 -> [1, final]
        if(initial == 1){
            long long int sum1 = 0, sum2 = 0;
            int position = final;

            while(position > 0)
            {
                sum1 += tree1[position];
                sum2 += tree2[position];

                position -= LSB(position);
            }

            return sum1 * final - sum2;
        }

        // if the range does not start in 1, the range sum will be
        //      [initial, final] = [1, final] - [1, initial - 1]
        return RSQ(1, final) - RSQ(1, initial - 1);
    }

private:

    // DO NOT use the point_update directly, the use of this function can cause
    // unpredictable results on the Fenwick Tree RQRU
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

            Complexity: O(log n)
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
    FenwickTreeRQRU ft(10);

    //int values[] = {0, 1, 1, 1, 2, 2, 6, 6, 2, 9, 0};

    cout << "Build Tree:" << endl;
    ft.range_update(1, 3, 1);
    ft.range_update(4, 5, 2);
    ft.range_update(6, 7, 6);
    ft.range_update(8, 8, 2);
    ft.range_update(9, 10, 9);

    cout << "Tree 1: ";
    for(int i = 0; i < ft.size; i++)
        cout << ft.tree1[i] << " ";
    cout << endl;

    cout << "Tree 2: ";
    for(int i = 0; i < ft.size; i++)
        cout << ft.tree2[i] << " ";
    cout << endl;
    cout << endl;


    cout << "Range Update [3, 7] with value +1:" << endl;
    ft.range_update(3, 7, 1);

    cout << "Tree 1: ";
    for(int i = 0; i < ft.size; i++)
        cout << ft.tree1[i] << " ";
    cout << endl;

    cout << "Tree 2: ";
    for(int i = 0; i < ft.size; i++)
        cout << ft.tree2[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Range Query [4, 8]: " << ft.RSQ(4, 8) << endl;

    return 0;
}

/*
    Tested on: URI1500
*/
