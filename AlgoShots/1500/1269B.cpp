#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

int main() {
    ll t,n,m,q,i,j,k,x,mx = INT_MAX;
    I>>n>>m;
    V<ll>a(n), b(n);
    F(i,0,n-1)
        I>>a[i];
    F(i,0,n-1)
        I>>b[i];

    sort(all(b));

    F(i,0,n-1)
    {
        V<ll> c(all(a));
        bool found = true;
        x = (b[0] - c[i] + m) % m;
        F(j,0,n-1)
            c[j] = (c[j] + x) % m;

        sort(all(c));

        F(j,0,n-1)
            if (c[j] != b[j])
            {
                found = false;
                break;
            }

        if (found)
            mx = min(mx, x);
    }
    O<<mx<<'\n';
    return 0;
}