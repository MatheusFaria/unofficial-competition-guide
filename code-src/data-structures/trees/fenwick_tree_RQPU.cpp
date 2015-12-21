#include <iostream> // cout, endl
#include <cstring>  // memset

using namespace std;

#define LSB(x) ((x) & -(x))

class FenwickTreeRQPU {
public:
    int size;
    int * tree;

    FenwickTreeRQPU(int _size)
    {
        // size + 1 because the position 0 is a sentinel
        size = _size + 1;

        tree = new int[size];
        memset(tree, 0, sizeof(int)*(size));
    }


    void point_update(int position, int value)
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

    int RSQ(int initial, int final)
    {
        /*
            RSQ (Range Sum Query): returns the sum of the range [intial, final]
        */

        // if the range starts with 1 -> [1, final]
        if(initial == 1){
            int sum = 0;

            while(final > 0)
            {
                sum += tree[final];
                final -= LSB(final);
            }
            return sum;
        }

        // if the range does not start in 1, the range sum will be
        //      [initial, final] = [1, final] - [1, initial - 1]
        return RSQ(1, final) - RSQ(1, initial - 1);
    }
};

int main()
{
    FenwickTreeRQPU ft(10);

    int values[] = {0, 1, 3, 3, 2, 5, 6, 7, 2, 9, 0};

    cout << "Build Tree:" << endl;
    for(int i = 1; i <= 10; i++)
        ft.point_update(i, values[i]);

    for(int i = 0; i < ft.size; i++)
        cout << ft.tree[i] << " ";
    cout << endl;

    cout << "Point Update 5 with value 1:" << endl;
    ft.point_update(5, 1);

    for(int i = 0; i < ft.size; i++)
        cout << ft.tree[i] << " ";
    cout << endl;

    cout << "Range Query [2, 6]: " << ft.RSQ(2, 6) << endl;

    return 0;
}
