#include <iostream>  // cout, endl
#include <algorithm> // swap
#include <cstring>   // memset

// TODO: Explanation

using namespace std;

#define  left_child(x) (2*x)
#define right_child(x) (2*x + 1)

class SumSegmentTree{
public:
    int n;                // number of leaves in the tree
    int size;             // arrays size
    long long int * tree;
    long long int * lazy; // array that stores lazy updates

    SumSegmentTree(int s){
        n = s;
        size = 4*s + 1;

        tree = new long long int[size];
        memset(tree, 0, sizeof(long long int)*size);

        lazy = new long long int[size];
        memset(lazy, 0, sizeof(long long int)*size);
    }

    void build(int values[], int left, int right, int position)
    {
        /*
            build: fills the tree nodes with the valus in the array, the leaves
                   will receive the value corresponding to their position in the
                   array, and the other nodes will be filled with the result of
                   the merge operation

                left, right: recursive tree range, start with [0, n - 1]
                values: array of values
                position: position on segment tree array, starts with 1
                          and just like the heap, the left child is 2*position
                          and the right 2*position + 1
        */

        if(left == right) // if the node is a leaf
        {
            tree[position] = values[left];
            return;
        }

        // build the sub-trees: left and right

        int middle = (left + right)/2;
        build(values, left, middle, left_child(position));
        build(values, middle + 1, right, right_child(position));

        // Merge the tree result
        tree[position] = tree[left_child(position)] + tree[right_child(position)];
    }

    void point_update(int index, int value, int left, int right, int position){
        /*
            point_update: updates a single leaf in the tree

                index: index from [0..n-1] to update inside the tree
                value: value to update
                left, right: recursive tree range, start with [0, n - 1]
                position: position on segment tree array, starts with 1
                          and just like the heap, the left child is 2*position
                          and the right 2*position + 1

        */

        if(left == right && left == index) // if is a leaf that you want to update
        {
            tree[position] += value;
        }
        else if(left <= index && index <= right)
        {
            // If the index is inside the [left, right]

            int middle = (left + right)/2;

            // If it is in the left side
            if(index <= middle)
                point_update(index, value, left, middle, left_child(position));
            // If it is in the right side
            else
                point_update(index, value, middle + 1, right, right_child(position));

            // Merge the tree result
            tree[position] = tree[left_child(position)] + tree[right_child(position)];
        }
    }

    inline bool is_lazy(int index){
        /* Checks if the current index is marked as lazy */
        return lazy[index] != 0;
    }

    void range_update(int initial, int final, long long int value, int left,
                      int right, int position){
        /*
            range_update: Updates the range [initial, final] with `value`

                initial, final: range to update
                value: value to update
                left, right: recursive tree range, start with [0, n - 1]
                position: tree position that is being anylized now. Just like
                          the heap, the left child is 2*position and the right
                          2*position + 1
        */


        if(is_lazy(position)) // Check if there is any pending update
        {
            long long int len = right - left + 1;
            long long int lazy_value = lazy[position];

            tree[position] += len*lazy_value;

            if(len > 1) // if this node has children
            {
                // Mark its children as lazy
                lazy[ left_child(position)] += lazy_value;
                lazy[right_child(position)] += lazy_value;
            }

            lazy[position] = 0; // Reseet the node status as false
        }

        if(left >= initial && right <= final)
        {
            // The tree range is inside the update range

            long long int len = right - left + 1;

            tree[position] += len*value;

            if(len > 1) // if this node has children
            {
                // Mark its children as lazy
                lazy[ left_child(position)] += value;
                lazy[right_child(position)] += value;
            }

            return;
        }

        if(right < initial || left > final)
        {
            // The update range and the tree range are disjoint
            return;
        }


        // Divide the tree range in left and right, to do the range update
        // in the node children

        int middle = (left + right)/2;
        range_update(initial, final, value, left, middle, left_child(position));
        range_update(initial, final, value, middle + 1, right, right_child(position));

        // Merge the tree result
        tree[position] = tree[left_child(position)] + tree[right_child(position)];
    }

    long long int RSQ(int initial, int final, int left, int right, int position){
        /*
            RSQ (Range Sum Query): Returns the sum of the range

                initial, final: range to query
                left, right: recursive tree range, start with [0, n - 1]
                position: tree position that is being anylized now. Just like
                          the heap, the left child is 2*position and the right
                          2*position + 1
        */

        if(right < initial || left > final){
            // The query range and the tree range are disjoint
            return 0;
        }

        if(is_lazy(position)) // Check if there is any pending update
        {
            long long int len = right - left + 1;
            long long int lazy_value = lazy[position];

            tree[position] += len*lazy_value;

            if(len > 1) // if this node has children
            {
                // Mark its children as lazy
                lazy[ left_child(position)] += lazy_value;
                lazy[right_child(position)] += lazy_value;
            }

            lazy[position] = 0; // Reseet the node status as false
        }

        if(left >= initial && right <= final){
            // The tree range is inside the query range
            return tree[position];
        }


        // Divide the tree range in left and right, to do the RSQ in each
        // node children

        int middle = (left + right)/2;
        return RSQ(initial, final, left, middle, left_child(position)) +
               RSQ(initial, final, middle + 1, right, right_child(position));
    }

};

int main()
{
    int n = 10;
    SumSegmentTree tree(n);

    int values[] = {1, 12, 4, 5, 12, 2, 3, 7, 9, 11};

    cout << "Build tree: " << endl;
    tree.build(values, 0, n - 1, 1);

    for(int i = 0; i < tree.size; i++)
        cout << tree.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Point update 4 with +2: " << endl;
    tree.point_update(4, 2, 0, n - 1, 1);

    for(int i = 0; i < tree.size; i++)
        cout << tree.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Range update [2, 6] with +1: " << endl;
    tree.range_update(2, 6, 1, 0, n - 1, 1);

    for(int i = 0; i < tree.size; i++)
        cout << tree.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "RSQ [1, 6]: ";
    cout << tree.RSQ(1, 6, 0, n - 1, 1) << endl;

    return 0;
}
