/*
    * 1203C - Common Divisors
    * 
    * First sort the array
    * Then find the GCD of all the elements in the array
    * Finally, count the total number of divisors of the GCD
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

ll count_divisors(ll n) {
    if (n == 1)
        return 1;
    ll ans = 2, i, sq = sqrt(n);
    for (i = 2; i <= sq; ++i)
        if (n % i == 0)
        {
            ++ans;
            if (n / i != i)
                ++ans;
        }
    return ans;
}

ll gcd_of_array(V<ll> &a, ll n) {
    ll i, res = a[0];
    F(i,1,n-1)
    {
        res = __gcd(a[i], res);
        if (res == 1)
            return 1;
    }
    return res;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, g;
    I>>n;
    V<ll> a(n);
    F(i,0,n-1)
        I>>a[i];
    sort(all(a));
    g = gcd_of_array(a, n);
    O<<count_divisors(g)<<'\n';
    return 0;
}
