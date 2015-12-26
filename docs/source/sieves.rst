Sieves
======

Happy Number
------------

.. note::

    Tested on: UVA944

Happy number is a number where you can successively sum the digits squared, and it
you return 1 at some point.

For example the number 19:

1^2 + 9^2 = 82

8^2 + 2^2 = 68

6^2 + 8^2 = 100

1^2 + 0^2 + 0^2 = 1


.. code-block:: cpp

    #include <unordered_map> // unordered_map
    #include <string>        // to_string

    using namespace std;

    unordered_map<string, bool> happy_number_dp;

    bool happy_number(string number)
    {
        if(number == "1") return true;
        if(number == "4") return false;

        if(happy_number_dp.find(number) != happy_number_dp.end())
            return happy_number_dp[number];

        int result = 0;
        for(unsigned int i = 0; i < number.size(); i++)
            result += (number[i] - '0')*(number[i] - '0');

        happy_number_dp[number] = happy_number(to_string(result));

        return happy_number_dp[number];
    }

Josephus Problem
----------------

k=2
~~~

.. note::

    Tested on: URI1672

When the second person is killed every time, there is a clean solution for this
problem:

.. code-block:: cpp

    #include <bitset>

    using namespace std;

    unsigned long int josephus_k_2(int n)
    {
        /*
            Complexity: O(1)
        */

        // Turn off the MSB and append one bit 1 at the end

        bitset<50> bits(n);
        for(int i = 50; i >= 0; i--)
        {
            if(bits[i] == 1)
            {
                bits.flip(i);
                break;
            }
        }

        bits <<= 1;
        bits.set(0);

        return bits.to_ulong();
    }

.. toctree::
   :maxdepth: 2
