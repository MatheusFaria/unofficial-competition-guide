#include <iostream> // cout, endl
#include <cstring>  // memset

using namespace std;

#define MAX 30010
#define MAX_COINS 15

long long int ways_memoized[MAX_COINS][MAX]; // initialized with memset -1

// How many ways do I have to give the same exact change?
long long int coin_change_ways(int value, int i_n_coins, int coins[], int n_coins)
{
    // There are no representations for negative values
    if(value < 0) return 0;
    // If there isn't more coins to consider, threare no representations
    if(i_n_coins == n_coins) return 0;
    // Value zero, can be represented by not taking any coins
    if(value == 0) return 1;


    if(ways_memoized[i_n_coins][value] == -1)
    {
        long long int take_coin = coin_change_ways(value - coins[i_n_coins],
                                         i_n_coins, coins, n_coins);
        long long int not_take_coin = coin_change_ways(value, i_n_coins + 1,
                                             coins, n_coins);
        ways_memoized[i_n_coins][value] = take_coin + not_take_coin;
    }

    return ways_memoized[i_n_coins][value];
}

int main()
{
    string num;
    int n_coins = 11;
    int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

    memset(ways_memoized, -1, sizeof(long long int)*MAX*MAX_COINS);

    cout << coin_change_ways(4, 0, coins, n_coins) << endl; // outputs 817

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <= 4; j++)
            cout << ways_memoized[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
    Tested on: UVA147
*/
