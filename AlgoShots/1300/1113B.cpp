#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

int main() {
    ll n, i, b, l, j, s, s0 = 0, p;
    I>>n;
    V<ll> a(n);
    F(i,0,n-1)
    {
        I>>a[i];
        s0 += a[i];
    }
    s = s0;
    p = s;
    sort(all(a));
    V<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    V<bool> is_prime(101,false);
    l = primes.size();
    F(i,0,l-1)
        is_prime[primes[i]] = true;
    for (i = n - 1; i >= 0; --i)
    {
        if (is_prime[a[i]])
            continue;
        for (b = j = 1; j <= a[i]; ++j)
            if (a[i] % j == 0)
            {
                b = j;
                s -= a[0];
                s -= a[i];
                s += a[0] * b;
                s += a[i] / b;
                p = min(s, p);
                s = s0;
            }
    }
    O<<p<<'\n';
    return 0;
}