#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, k, i, s;
    string Y = "YES\n", N = "NO\n";
    I>>n>>k;
    s = k;
    V<ll> p(k, 1);
    F(i,0,k-1)
    {
        while (s + p[i] <= n)
        {
            s += p[i];
            p[i] *= 2;
        }
    }
    if (s == n)
    {
        O<<Y;
        F(i,0,k-1)
            O<<p[i]<<' ';
        O<<'\n';
    }
    else
        O<<N;
    return 0;
}