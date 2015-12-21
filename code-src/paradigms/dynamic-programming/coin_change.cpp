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

// What is the minimun number of coins that I can use to give the value
int coin_change(int value, int coins[], int n_coins)
{
    // There is no change with value 0
    if(value == 0) return 0;

    // There shouldn't exist negative values!
    if(value < 0) return numeric_limits<int>::max();

    if(change_dp[value] != -1) return change_dp[value];

    int coin_index = 0;
    int min_change = coin_change(value - coins[0], coins, n_coins);
    for(int i = 1; i < n_coins; i++)
    {
        int current_change = coin_change(value - coins[i], coins, n_coins);
        if(current_change < min_change)
        {
            coin_index = i;
            min_change = current_change;
        }
    }

    change_dp[value] = 0;

    // If for all coins there is no possible way to give a change
    if(min_change == numeric_limits<int>::max()) return 0;

    // Count the coin picked now
    min_change += 1;
    change_dp[value] = min_change;

    return min_change;
}

/*
TESTED ON:
URI: 1034
*/

// This one needs the coin of value 1 in the coin set
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

    int coins[] = {12, 5, 1};
    int n_coins = 3;

    cout << coin_change(15, coins, n_coins) << endl; //outputs 3

    memset(change_dp, -1, sizeof(change_dp));
    int coins_1[] = {1, 2, 3};
    int n_coins_1 = 3;

    cout << coin_change(4, coins_1, n_coins_1) << endl; //outputs 2
    return 0;
}
