#include <iostream> // cout, endl
#include <vector>   // vector
#include <cstring>  // memset

using namespace std;

// Sieve Dependency
#define MAX 1000000
    vector<long long int> primes;
    bool is_prime[MAX + 1];
    vector<long long int> sieve_of_eratosthenes(long long int N);
///////



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


int main()
{
    memset(is_prime, 1, (MAX + 1)*sizeof(bool));
    sieve_of_eratosthenes(MAX);

    return 0;
}

vector<long long int> sieve_of_eratosthenes(long long int N)
{
    for(long long int i = 2; i <= N; i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            for(long long int j = i*i; j <= N; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

/*
    Tested on: UVA10392
*/
