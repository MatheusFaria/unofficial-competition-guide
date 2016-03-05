#include <iostream>  // cout, endl
#include <cstring>   // memset
#include <algorithm> // max

#define MAX 5
#define MAX_WEIGHT 11

using namespace std;

int knapsack[MAX][MAX_WEIGHT]; // intialization at main with memset -1

/*
    Tested on: UVA562, URI1286
*/

int knapsack_iterative(int weights[], int values[], int n_items, int max_weight)
{
    for(int i = 0; i <= n_items; i++)
    {
        int item_weight = weights[i - 1];
        int item_value  =  values[i - 1];

        for(int bag_weight = 0; bag_weight <= max_weight; bag_weight++)
        {
            if(i == 0 || bag_weight == 0)
                knapsack[i][bag_weight] = 0;
            else if(item_weight > bag_weight)
                knapsack[i][bag_weight] = knapsack[i - 1][bag_weight];
            else
                knapsack[i][bag_weight] = max(
                    knapsack[i - 1][bag_weight],
                    knapsack[i - 1][bag_weight - item_weight] + item_value
                );
        }
    }

    return knapsack[n_items][max_weight];
}

/*
    Tested on: UVA10819
*/

int knapsack_recursive(int weights[], int values[], int n_items, int bag_weight)
{
    if(n_items == 0 || bag_weight <= 0) return 0;

    if(knapsack[n_items][bag_weight] == -1)
    {
        if(weights[n_items - 1] > bag_weight)
            knapsack[n_items][bag_weight] = knapsack_recursive(
                                                weights, values,
                                                n_items - 1, bag_weight
                                            );
        else
            knapsack[n_items][bag_weight] = max(
                // Not take the item
                knapsack_recursive(weights, values, n_items - 1, bag_weight),
                // Take the item
                knapsack_recursive(weights, values, n_items - 1,
                                   bag_weight - weights[n_items - 1]) + values[n_items - 1]
            );
    }

    return knapsack[n_items][bag_weight];
}

int main()
{
    // knapsack matrix initialization
        memset(knapsack, -1, sizeof(int)*MAX_WEIGHT*MAX);

    int values[] = {1, 6, 18, 22, 28};
    int weights[] = {1, 2, 5, 6, 7};

    cout << knapsack_iterative(weights, values, MAX, MAX_WEIGHT) << endl;

    // knapsack matrix initialization
        memset(knapsack, -1, sizeof(int)*MAX_WEIGHT*MAX);

    cout << knapsack_recursive(weights, values, MAX, MAX_WEIGHT) << endl;

    return 0;
}
