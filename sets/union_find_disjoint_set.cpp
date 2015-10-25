#include <iostream> // cout, endl
#include <cstring>  // memset

//TODO: Explanation

using namespace std;

class UFDS{
public:
    int size;
    int * parents;
    int * heights;

    UFDS(int s)
    {
        // Using 0 as sentinel
        size = s + 1;

        parents = new int[size];
        memset(parents, 0, size*sizeof(int));

        heights = new int[size];
        memset(heights, 0, size*sizeof(int));
    }

    int find_set(int x)
    {
        /*
            find_set: returns the root of the set that x belongs
        */

        int root = parents[x];

        // If it found a root, return it
        if(x == root) return x;

        // If the value of parents[x] is not setted yet, which means that it
        // has the default value 0
        if(root == 0){
            parents[x] = x;
            return x;
        }

        // x is not the root of the set, look to its father root and update the
        // x root to be the set root
        parents[x] = find_set(root);

        // return x updated root
        return parents[x];
    }

    inline bool same_set(int x, int y)
    {
        /*
            same_set: checks if x and y belong to the same set
        */

        return find_set(x) == find_set(y);
    }

    void union_set(int x, int y)
    {
        /*
            union_set: joins two sets if they are not from the same set
                       The rule for join is to join the smaller set into the
                       larger.
        */

        int root1 = find_set(x);
        int root2 = find_set(y);

        // If is not from the same set
        if(root1 != root2)
        {
            if(heights[root1] >= heights[root2])
            {
                parents[root2] = root1;
                heights[root1] += heights[root2];
            }
            else
            {
                parents[root1] = root2;
                heights[root2] += heights[root1];
            }
        }
    }
};


int main()
{
    UFDS ufds(10);

    for(int i = 0; i < ufds.size; ++i)
        cout << ufds.parents[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Join sets 1 and 2" << endl;
    ufds.union_set(1, 2);

    for(int i = 0; i < ufds.size; ++i)
        cout << ufds.parents[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Join sets 4 and 5" << endl;
    ufds.union_set(4, 5);

    for(int i = 0; i < ufds.size; ++i)
        cout << ufds.parents[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Join sets 3 and 4" << endl;
    ufds.union_set(3, 4);

    for(int i = 0; i < ufds.size; ++i)
        cout << ufds.parents[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Join sets 5 and 1" << endl;
    ufds.union_set(5, 1);

    for(int i = 0; i < ufds.size; ++i)
        cout << ufds.parents[i] << " ";
    cout << endl;
    cout << endl;

    cout << "Is 9 and 1 from the same set: " << (ufds.same_set(9, 1) ? "True" : "False") << endl;
    cout << "Is 1 and 4 from the same set: " << (ufds.same_set(1, 4) ? "True" : "False") << endl;

    cout << "Find 5 set:  " << ufds.find_set(5) << endl;

    return 0;
}
