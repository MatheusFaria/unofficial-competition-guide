#include <iostream> // cout, endl
#include <vector>   // vector
#include <cstring>  // memset

using namespace std;

vector<int> sieve_of_eratosthenes(int N)
{
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

int main()
{

    vector<int> primes = sieve_of_eratosthenes(100);
    for(auto prime: primes)
        cout << prime << " ";
    cout << endl;
    return 0;
}
