#include <cstdio>    // printf
#include <string>    // string, stoll
#include <algorithm> // find

using namespace std;

long long int safe_float_to_int(string float_num)
{
    // Removing trailing zeros
    while(float_num.back() == '0') float_num.pop_back();

    // Removing the dot
    auto it_dot = find(float_num.begin(), float_num.end(), '.');
    if(it_dot != float_num.end())
        float_num.erase(it_dot);

    // Converting to int
    return stoll(float_num);
}

int main()
{
    printf("%lld\n", safe_float_to_int("1.0002"))
    return 0;
}
