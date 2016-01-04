Backtracking
============

Brute force the entire solution space to find all possible solutions. Be careful
with the size of the solution space. Most of the solutions with backtracking explode
the time limit. But it is very useful in some cases, and to produces offline solutions.
You can see below the backtracking framework.

.. code-block:: cpp

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

.. toctree::
   :maxdepth: 2
