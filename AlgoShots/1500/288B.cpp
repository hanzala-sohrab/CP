#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
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

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n,k,a;
    I>>n>>k;
    a = ((binpow(k, k-1) % M) * (binpow(n - k, n - k) % M)) % M;
    O<<a<<'\n';
    return 0;
}
