#include <iostream>

using namespace std;

int main()
{
    int a; long int b; long long int c;
    float d; double e;
    char f;
    cin >> a >> b >> c >> d >> e >> f;

    string line;
    getline(cin, line);

    cout << a << b << c << d << e << f << line << endl;
    return 0;
}
