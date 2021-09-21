#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    long long i, a[n], x1 = 0, x2 = 0;
    for (i = 0; i < n - 1; ++i)
    {
        cin >> a[i];
        x1 ^= a[i];
    }
    for (i = 1; i <= n; ++i)
        x2 ^= i;
    cout << (x1 ^ x2) << '\n';
    return 0;
}
