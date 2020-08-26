#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, c = 0, s = 0;
    I>>n;
    V<ll>a(n);
    F(i,0,n-1)
    {
        I>>a[i];
        s+=a[i];
    }
    if (s % n == 0)
        c = n;
    else
    {
        sort(all(a));
        for (i = n - 1; i >= 0; --i)
            if (n > 1 and a[i - 1] != a[0])
            {
                a[i - 1] += a[i] - a[0];
                a[i] = a[0];
            }
            else
                break;
        F(i,0,n-1)
            if (a[i] == a[0])
                ++c;
    }
    O<<c<<'\n';
    return 0;
}