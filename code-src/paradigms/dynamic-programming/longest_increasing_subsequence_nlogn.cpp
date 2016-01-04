#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>::iterator relative_lower_bound(int values[], vector<int>& L, int num)
{
    if(L.size() == 0) return L.end();

    int begin = 0;
    int end = L.size() - 1;
    int mid = (begin + end)/2;

    while(values[L[mid]] != num)
    {
        if(begin >= end) break;

        if(values[L[mid]] < num) begin = mid + 1;
        else if(values[L[mid]] > num) end = mid;

        mid = (begin + end)/2;
    }

    if(values[L[mid]] < num)
        return L.end();

    return L.begin() + mid;
}

int longest_increasing_subsequence(int values[], int size, int parents[], int &longest_seq_i)
{
    parents[0] = 0;
    vector<int> L;

    for(int i = 0; i < size; i++)
    {
        auto it = relative_lower_bound(values, L, values[i]);

        if(it == L.end())
        {
            L.push_back(i);
        }
        else
        {
            *it = i;
        }

        if(L.size() > 1)
            parents[i] = *(it - 1);

    }

    longest_seq_i = L.back();
    return L.size();
}

void print_sequence(int values[], int parents[], int longest_seq_i)
{
    int i = longest_seq_i;
    while(i != parents[i])
    {
        cout << values[i] << " ";
        i = parents[i];
    }
    cout << values[i];

    cout << endl;
}

int main()
{

    int values[] = {1, 2, 7, 9, 5, 6, 8, 9};
    int parents[8];
    int longest_seq_i = 0;

    int max_seq = longest_increasing_subsequence(values, 8, parents, longest_seq_i);
    cout << max_seq << endl;
    print_sequence(values, parents, longest_seq_i);

    int values1[] = {2, 1, 2, 6, 4, 3, 6, 4, 5};
    int parents1[9];
    longest_seq_i = 0;

    max_seq = longest_increasing_subsequence(values1, 9, parents1, longest_seq_i);
    cout << max_seq << endl;
    print_sequence(values1, parents1, longest_seq_i);

    int values2[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int parents2[16];
    longest_seq_i = 0;

    max_seq = longest_increasing_subsequence(values2, 16, parents2, longest_seq_i);
    cout << max_seq << endl;
    print_sequence(values2, parents2, longest_seq_i);

    int values3[] = {-7, 10, 9, 2, 3, 8, 8, 1};
    int parents3[8];
    longest_seq_i = 0;

    max_seq = longest_increasing_subsequence(values3, 8, parents3, longest_seq_i);
    cout << max_seq << endl;
    print_sequence(values3, parents3, longest_seq_i);

    return 0;
}

/*
    Tested on: UVA231
*/
