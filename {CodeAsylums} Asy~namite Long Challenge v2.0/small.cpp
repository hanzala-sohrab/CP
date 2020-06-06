#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>n;
    V<ll> d(n);
    F (i, 0, n - 1)
        I >> d[i];
    sort(all(d));
    if (d[0] == 0 && d[n - 1] == 0)
        O << "-1";
    else
    {
        string s;
        F (i, 0, n - 1)
            if (d[i])
                break;
        s += to_string(d[i]);
        F (j, 0, n - 1)
            if (j != i)
                s += to_string(d[j]);
        O << s;
    }
    return 0;
}