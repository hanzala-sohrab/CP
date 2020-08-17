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
#define umap unordered_map

bool isPowerOfTwo (ll x) {
    return x && (!(x&(x-1)));
}

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
    ll i, m, s, x, t, j;
    I >> m >> s;
    t = s;
    bool possible = false;
    string n, N;
    F(i,0,m-1)
    {
        j = i ? 0 : 1;
        F(x,j,9)
            if (s <= x + (m - 1 - i) * 9)
            {
                possible = true;
                break;
            }
        n += to_string(x);
        s -= x;
    }
    s = t;
    for (i = m - 1; i >= 0; --i)
    {
        j = i ? 0 : 1;
        for (x = j; x <= 9; ++x)
            if (s <= x + i * 9)
                break;
        N = to_string(x) + N;
        s -= x;
    }
    s = 0;
    F(i,0,m-1)
        s += n[i] - 48;
    if (s == t and n[0] != '0' and N[0] != '0')
        O << n << ' ' << N << '\n';
    else if (m == 1 and t == 0)
        O << "0 0\n";
    else
        O << "-1 -1\n";
    return 0;
}