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
    ll k, i, m = 0, ind, a = 0, l;
    string s;
    I >> s >> k;
    l = s.size();
    V<ll> w(26);
    F(i,0,25)
    {
        I>>w[i];
        if (m < w[i])
        {
            m = w[i];
            ind = i;
        }
    }
    F(i,0,l-1)
        a += w[s[i] - 97] * (i + 1);
    for ( ; i < l + k; ++i)
        a += w[ind] * (i + 1);
    O << a << '\n';
    return 0;
}