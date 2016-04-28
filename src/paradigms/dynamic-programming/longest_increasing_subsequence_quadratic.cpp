#include <iostream>

using namespace std;

int longest_increasing_subsequence(int values[], int size, int parents[], int &longest_seq_i)
{

    int * lis = new int[size];
    for(int i = 0; i < size; i++)
        parents[i] = i;

    int longest_seq = 0;

    for(int i = 0; i < size; i++)
    {
        lis[i] = 1;
        for(int j = i - 1; j >= 0; j--)
        {
            if(values[i] > values[j])
            {
                if(lis[i] < lis[j] + 1)
                {
                    parents[i] = j;
                    lis[i] = lis[j] + 1;
                }
            }
        }

        if(lis[i] > longest_seq)
        {
            longest_seq = lis[i];
            longest_seq_i = i;
        }
    }

    delete[] lis;

    return longest_seq;
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

    return 0;
}
