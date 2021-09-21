#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n, x;
    cin >> n;
    if (n == 1)
        cout << "1";
    else if (n < 4)
        cout << "NO SOLUTION";
    else if (n == 4)
        cout << "2 4 1 3";
    else if (n & 1)
    {
        x = n - 1;
        while (x > 0)
        {
            cout << x << ' ';
            x -= 2;
        }
        x = n;
        while (x > 0)
        {
            cout << x << ' ';
            x -= 2;
        }
    }
    else
    {
        x = n;
        while (x > 0)
        {
            cout << x << ' ';
            x -= 2;
        }
        x = n - 1;
        while (x > 0)
        {
            cout << x << ' ';
            x -= 2;
        }
    }
    cout << '\n';
    return 0;
}
