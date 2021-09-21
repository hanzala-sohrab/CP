#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    long long i, x[n], ans = 0;
    for (i = 0; i < n; ++i)
        cin >> x[i];
    for (i = 1; i < n; ++i)
        if (x[i] < x[i - 1])
        {
            ans += x[i - 1] - x[i];
            x[i] = x[i - 1];
        }
    cout << ans;
    return 0;
}
