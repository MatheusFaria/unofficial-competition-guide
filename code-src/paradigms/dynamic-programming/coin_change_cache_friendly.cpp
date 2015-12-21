#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

#define MAX_VALUE 10010

int change_dp[MAX_VALUE]; // initialization memset with value -1

/*
TESTED ON:
URI: 1034
*/

// This one needs the coin of value 1 in the first position of the coin set
int coin_change_cache_friendly(int value, int coins[], int n_coins)
{
    for(int i = 0; i <= value; i++)
        change_dp[i] = i;

    for(int i = 1; i < n_coins; i++)
        for(int j = coins[i]; j <= value; j++)
            change_dp[j] = min(change_dp[j], 1 + change_dp[j - coins[i]]);

    return change_dp[value];
}

int main()
{
    memset(change_dp, -1, sizeof(change_dp));

    int coins[] = {1, 12, 5};
    int n_coins = 3;

    cout << coin_change_cache_friendly(15, coins, n_coins) << endl; //outputs 3

    memset(change_dp, -1, sizeof(change_dp));
    int coins_1[] = {1, 2, 3};
    int n_coins_1 = 3;

    cout << coin_change_cache_friendly(4, coins_1, n_coins_1) << endl; //outputs 2
    return 0;
}
