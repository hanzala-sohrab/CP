#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define M 1000000007
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

ll binpow(ll a, ll b) {
    a %= M;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        string s, s1, s2;
        I >> s;
        j = s.size();
        i = j / 2;
        s1 = s.substr(0, i);
        if (j & 1)
            ++i;
        s2 = s.substr(i, j - 1);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (!s1.compare(s2))
            O << "YES\n";
        else
            O << "NO\n";
    }
    return 0;
}