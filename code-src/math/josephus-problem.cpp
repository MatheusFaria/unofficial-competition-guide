#include <iostream>
#include <bitset>

using namespace std;

unsigned long int josephus_k_2(int n)
{
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

int main()
{
    cout << josephus_k_2(5) << endl;   // outputs 3
    cout << josephus_k_2(56) << endl;  // outputs 49
    cout << josephus_k_2(7) << endl;   // outputs 7
    cout << josephus_k_2(185) << endl; // outputs 115

    return 0;
}
