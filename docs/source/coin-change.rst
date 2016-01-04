Coin Change
===========

Coin change problems usually try to answer the question: What is the minimun
number of coins that I can use to give the value X?

Standard
--------

.. note::

    Tested on: URI1034

.. code-block:: cpp

    #include <limits>   // numeric_limits
    #include <cstring>  // memset

    using namespace std;

    #define MAX_VALUE 10010

    int change_dp[MAX_VALUE]; // initialization memset with value -1

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


Cache Friendly
--------------

Faster than the standart version. But has a restriction that can only be used in
problems where the coin set has the coin of value 1.

.. note::

    Tested on: URI1034

.. code-block:: cpp

    #include <cstring>   // memset
    #include <algorithm> // min

    using namespace std;

    #define MAX_VALUE 10010

    int change_dp[MAX_VALUE]; // initialization memset with value -1

    // Needs the coin of value 1 in the first position of the coin set
    int coin_change_cache_friendly(int value, int coins[], int n_coins)
    {
        for(int i = 0; i <= value; i++)
            change_dp[i] = i;

        for(int i = 1; i < n_coins; i++)
            for(int j = coins[i]; j <= value; j++)
                change_dp[j] = min(change_dp[j], 1 + change_dp[j - coins[i]]);

        return change_dp[value];
    }


Ways
----

Uses the coin change to answer the question: How many ways do I have to give the same exact change?
Given an infinity amount of those coins.

.. note::

    Tested on: UVA147

.. code-block:: cpp

    #include <cstring>  // memset

    using namespace std;

    #define MAX 30010
    #define MAX_COINS 15

    long long int ways_memoized[MAX_COINS][MAX]; // initialized with memset -1

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

.. toctree::
   :maxdepth: 2
