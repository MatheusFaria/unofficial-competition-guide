#include <iostream>  // cout
#include <algorithm> // fill

using namespace std;

#define  left_child(x) (2*x)
#define right_child(x) (2*x + 1)

class ProductSegmentTree{
public:
    int n;      // number of leaves in the tree
    int size;   // arrays size
    int * tree;

    ProductSegmentTree(int s){
        n = s;
        size = 4*s + 1;

        tree = new int[size];

        // O(n) fill: unecessary depending on the usage
        fill(tree, tree + size, 0);
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
        tree[position] = tree[left_child(position)] * tree[right_child(position)];
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
            tree[position] = value;
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
            tree[position] = tree[left_child(position)] * tree[right_child(position)];
        }
    }

    void range_update(int initial, int final, int value, int left,
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


        if(left == right) // if this node is a leaf
        {
            tree[position] = value;
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
        tree[position] = tree[left_child(position)] * tree[right_child(position)];
    }

    int RPQ(int initial, int final, int left, int right, int position){
        /*
            RPQ (Range Product Query): Returns the product of the range

                initial, final: range to query
                left, right: recursive tree range, start with [0, n - 1]
                position: tree position that is being anylized now. Just like
                          the heap, the left child is 2*position and the right
                          2*position + 1
        */

        if(left >= initial && right <= final){
            // The tree range is inside the query range
            return tree[position];
        }
        if(right < initial || left > final){
            // The query range and the tree range are disjoint
            return 1;
        }

        int middle = (left + right)/2;
        return RPQ(initial, final, left, middle, left_child(position)) *
               RPQ(initial, final, middle + 1, right, right_child(position));
    }

};



int main()
{
    int n = 10;
    ProductSegmentTree tree(n);

    int values[] = {0, 12, 4, 5, 12, 2, 0, 7, 9, 11};

    cout << "Build tree: " << endl;
    tree.build(values, 0, n - 1, 1);

    for(int i = 0; i < tree.size; i++)
        cout << tree.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Point update 4 to value 2: " << endl;
    tree.point_update(4, 2, 0, n - 1, 1);

    for(int i = 0; i < tree.size; i++)
        cout << tree.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Range update [2, 6] with 1: " << endl;
    tree.range_update(2, 6, 1, 0, n - 1, 1);

    for(int i = 0; i < tree.size; i++)
        cout << tree.tree[i] << " ";
    cout << endl;
    cout << endl;

    cout << "RPQ [1, 4]: ";
    cout << tree.RPQ(1, 4, 0, n - 1, 1) << endl;

    return 0;
}
