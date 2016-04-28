#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // List Initialization
        vector<int> vec{1, 2, 3, 4, 5};


    // For each
        for(auto element: vec)
            cout << element << " ";
        cout << endl;


    // Dynamic type declaration
        auto a = 3, b = 1;
        decltype(a + b) c = a + b;


    // Replace typedefs
        using ll = long long int;
        ll ll_var = 30;


    // Lambda function
        sort(vec.begin(), vec.end(),
             [](const int& e1, const int& e2) -> bool
             {
                 return e1 < e2;
             });

        // Other uses

        int var1 = 1;
        int var2 = 3;

        // Copying all context variables
        auto f1 = [=]() -> int{
            int var3 = var1 + 1;
            return var3 + var2;
        };

        // Copying by reference all context variables
        auto f2 = [&]() -> int{
            var1++;
            var2 += var1;
            return var1 + var2;
        };

        // Mixing copy styles, all by reference, except one by copying
        auto f3 = [&, var1]() -> int{
            var2 += var1;
            return var1 + var2;
        };

    return 0;
}
