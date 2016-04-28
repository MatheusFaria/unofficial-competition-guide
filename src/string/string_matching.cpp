#include <iostream> // cout
#include <vector>   // vector

using namespace std;

vector<int> basic_string_matching(string phrase, string word)
{
    /*
        Finds all the word occurrences in the pharse, and return the indices of
        those occurrences

        Complexity: O(n*m)
    */
    vector<int> indices;

    // For each letter in the larger string a
    for(unsigned int i = 0; i < phrase.size(); i++)
    {
        bool found = true;
        // For each letter in the smaller string b
        for(unsigned int j = 0; j < word.size() && found; j++)
            if(i + j >= phrase.size() || word[j] != phrase[i + j]) found = false;

        if(found) indices.push_back(i);
    }

    return indices;
}

int main()
{
    string a = "banana", b = "ana";
    auto v = basic_string_matching(a, b);
    for(auto i: v) cout << i << " ";
    cout << endl;
}

/*
    Tested on: UVA455
*/
