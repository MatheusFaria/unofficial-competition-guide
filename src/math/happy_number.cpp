#include <iostream>      // cout, endl
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

int main()
{

    cout << happy_number("556") << endl; // happy
    cout << happy_number("557") << endl; // unhappy
    return 0;
}

/*
    Tested on: UVA944
*/
