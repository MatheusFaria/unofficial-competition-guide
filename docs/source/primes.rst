Prime Numbers
=============

In this sections you can find algorithms related to prime numbers.


Sieve of Erastosthenes
----------------------

.. note::

    Tested on: UVA10392

.. code-block:: cpp

    vector<int> sieve_of_eratosthenes(int N)
    {
        /*
            Finds all primes until N

            Complexity: O(sqrt(n)/log n)
        */
        vector<int> primes;
        bool * is_prime = new bool[N + 1];
        memset(is_prime, 1, (N + 1)*sizeof(bool));

        for(int i = 2; i <= N; i++)
        {
            if(is_prime[i])
            {
                primes.push_back(i);
                for(int j = i*i; j <= N; j+=i)
                {
                    is_prime[j] = false;
                }
            }
        }

        return primes;
    }

Prime Factors
-------------

.. note::

    Tested on: UVA10392

.. attention::

    This algorithm depends on the sieve_of_eratosthenes to fill the `primes` vector

.. code-block:: cpp

    vector<unsigned long long int> prime_factors(unsigned long long int N)
    {
        /*
            Calculates all prime factors of N

            !!Depends on the sieve_of_eratosthenes
            Complexity: O(PI * sqrt(N))
        */
        vector<unsigned long long int> factors;
        unsigned long long int prime_index = 0, prime_factor = primes[prime_index];

        // Uses the division property that a factor of a number can only be
        // less or equal to the sqrt(number)
        while(prime_factor * prime_factor <= N)
        {
            while(N % prime_factor == 0)
            {
                N /= prime_factor;
                factors.push_back(prime_factor);
            }

            prime_factor = primes[++prime_index];
            if(prime_index == primes.size()) break;
        }

        if(N != 1) factors.push_back(N); // N is prime

        return factors;
    }

.. toctree::
   :maxdepth: 2
