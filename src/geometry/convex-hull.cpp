#include <vector>    // vector
#include <algorithm> // sort
#include <utility>   // pair

using namespace std;

// BE CAREFUL!!! Do not name variables x or y
#define x first
#define y second

using ii = pair<int, int>;
using ll = long long;

inline ll cross(const ii &O, const ii &A, const ii &B)
{
    return (A.x - O.x)*(ll)(B.y - O.y) - (A.y - O.y)*(ll)(B.x - O.x);
}

vector<ii> convex_hull(vector<ii> P)
{
    /*
        Complexity: O(n log(n))
    */

    int n = P.size(), k = 0;
    vector<ii> H(2*n);

    sort(P.begin(), P.end());

    for(int i = 0; i < n; ++i)
    {
        while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);

    return H;
}

int main()
{
    return 0;
}

/*
    Tested on: URI1982
*/
