#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n, i, c = 1, temp = 0;
    cin >> n;
    long long x[n];
    for (i = 0; i < n; ++i) 
        cin >> x[i];
    sort(x, x + n);
    for (i = 1; i < n; ++i)
        if (x[i] != x[i - 1])
            ++c;
    cout << c << '\n';
    return 0;
}
