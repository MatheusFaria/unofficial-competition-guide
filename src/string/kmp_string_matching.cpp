#include <iostream> // cout
#include <vector>   // vector
#include <string>   // string

using namespace std;

#define MAX 1000010

int back_table[MAX];

void kmp_preprocess(string word)
{
    /*
        Maps the repetitions inside the string you want to search.

        Ex:
            word:   S E V E N T Y   S E V E N
            table: -1 0 0 0 0 0 0 0 0 1 2 3 4 5

        Complexity: O(n)
    */

    int i = 0, j = -1; back_table[0] = -1;
    int word_size = word.size();

    while(i < word_size)
    {
        while(j >= 0 && word[i] != word[j]) j = back_table[j];
        ++i; ++j;
        back_table[i] = j;
    }
}

vector<int> kmp_string_matching(string phrase, string word)
{
    /*
        Searchs for all occurrences of word in the phrase.

        Ex:

            phrase: ABC ABCDAB ABCDABDDABDE
            word:       ABCDABD
            table:     -10000120

            >> Mismatch at D != ' '
            Uses the back_table to restart at word index 2

            phrase: ABC ABCDAB ABCDABDDABDE
            word:           ABCDABD
            table:         -10000120

            >> Mismatch at C != ' '
            Uses the back_table to restart at word index 0

            phrase: ABC ABCDAB ABCDABDDABDE
            word:              ABCDABD
            table:            -10000120

            The substring matches

        Complexity: O(n + m)
    */
    vector<int> indices;

    // !!You can remove this depending on the context, and call it outside this
    //   function. Because it only need to be called once.
    kmp_preprocess(word);

    int i = 0, j = 0;
    int phrase_size = phrase.size();
    int   word_size =   word.size();

    while(i < phrase_size)
    {
        // If the chars at those positions mismatch, use the back table to
        // rewind until the necessary point
        while(j >= 0 && phrase[i] != word[j]) j = back_table[j];
        ++i; ++j;

        if(j == word_size)
        {
            // Found phrase's substring that matches with word
            indices.push_back(i - j);
            j = back_table[j];
        }
    }

    return indices;
}

int main()
{
    string a = "banana", b = "ana";
    for(auto i: kmp_string_matching(a, b))
        cout << i << endl;

    return 0;
}

/*
    Tested on: UVA455
*/
