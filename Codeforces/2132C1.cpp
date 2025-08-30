#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        ll n, m;
        I >> n;
        m = n;
        ll coins = 0;
        int ind = 0;
        while (m)
        {
            int rem = m % 3;
            coins += rem * (pow(3, ind + 1) + ind * pow(3, ind - 1));
            m /= 3;
            ++ind;
        }
        O << coins << '\n';
    }
    return 0;
}
