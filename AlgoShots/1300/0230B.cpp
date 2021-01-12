#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

bool is_prime(ll n) {
    if (n == 1)
        return false;
    if (n == 2 or n == 3)
        return true;
    if (n % 2 == 0 or n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 or n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>n;
    V<ll>a(n);
    F(i,0,n-1)
        I>>a[i];
    bool found = false;
    F(i,0,n-1)
    {
        q = sqrt(a[i]);
        if (q * q == a[i] and is_prime(q))
            O<<"YES\n";
        else
            O<<"NO\n";
    }
    return 0;
}
