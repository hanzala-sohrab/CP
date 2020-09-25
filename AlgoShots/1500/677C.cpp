#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

// https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
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

ll char_to_int(char c) {
    if ('0' <= c and c <= '9')
        return c - 48;
    if ('A' <= c and c <= 'Z')
        return c - 65 + 10;
    if ('a' <= c and c <= 'z')
        return c - 97 + 36;
    if (c == '-')
        return 62;
    return 63;
}

ll count_set(ll n) {
    ll c = 0;
    while (n)
    {
        n &= (n - 1);
        ++c;
    }
    return c;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    string s;
    I>>s;
    ll i, l = s.size(), a = 1, x, p;
    F(i,0,l-1)
    {
        x = char_to_int(s[i]);
        p = 6 - count_set(x);
        a = (a * binpow(3, p)) % M;
    }
    O<<a<<'\n';
    return 0;
}