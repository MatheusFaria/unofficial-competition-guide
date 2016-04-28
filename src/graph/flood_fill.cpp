#include <iostream>

using namespace std;

#define MAX 110
char G[MAX][MAX];

int flood_fill(int i, int j, int n, int m, char color, char new_color)
{
    /*
        Measures the size of the component that (i, j) are in. And recolors
        the component to the new_color

        Complexity: O(V + E)
    */

    if(i < 0 || j < 0 || i >= n || j >= m) return 0;

    // Arrays to move in the grid
    // {up, down, right, left} + {diagonals}
    int drow[8] = {0,  0, 1, -1, 1,  1, -1, -1};
    int dcol[8] = {1, -1, 0,  0, 1, -1,  1, -1};

    if(G[i][j] != color) return 0;

    G[i][j] = new_color;

    int size = 1;
    for(int di = 0; di < 8; ++di)
        size += flood_fill(i + drow[di], j + dcol[di], n, m, color, new_color);

    return size;
}

int main()
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            G[i][j] = 'a';

    G[0][0] = 'b';
    G[0][1] = 'b';
    G[1][0] = 'b';
    G[1][1] = 'b';

    G[2][4] = 'b';
    G[3][4] = 'b';
    G[1][3] = 'b';

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << G[i][j];
        cout << endl;
    }

    flood_fill(0, 1, 5, 5, 'b', 'c');

    cout << endl;
    cout << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << G[i][j];
        cout << endl;
    }
    return 0;
}

/*
    Tested on: UVA469
*/
