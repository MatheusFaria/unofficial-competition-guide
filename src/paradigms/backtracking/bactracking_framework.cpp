#include <iostream>

using namespace std;

#define MAX 10000

bool is_solution(int a[], int k, void * p)
{
    /* Checks if the array a is a possible solution */
    return false;
}

void process_solution(int a[], int k, void * p)
{
    /* Process the possible solution */
}

void construct_candidates(int a[], int k, void * p, int candidates[], int nc)
{
    /* Creates the next possible solution to be tested */
}

// Framework Backtracking
void backtracking(int a[], int k, void * p)
{
    /*
        backtracking: Brute force almost the entire space procesing the entries
                      that are solutions

        a[]: is an array that stores a solution
        k:   size of the array a
        p:   extra variables to help you in the problem solution
    */


    int candidates[MAX];
    int nc;

    if(is_solution(a, k, p))
        process_solution(a, k, p);
    else
    {
        ++k;
        construct_candidates(a, k, p, candidates, nc);
        for(int i = 0; i < nc; i++)
        {
            a[k] = candidates[i];
            backtracking(a, k, p);
        }
    }
}

int main()
{
    int a[] = {0};
    //backtracking_example(a, 0, 3, 5);
}
