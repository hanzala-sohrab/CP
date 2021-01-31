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
    ll t, i, n, b, a;
    I>>t;
    while (t--)
    {
        I>>n>>b>>a;
        V<ll>arr(n);
        F(i,0,n-1)
            I>>arr[i];
        ll k;
        double m = 0;
        F(k,a,b)
        {
            ll ma = 0, windowSum = 0, windowStart = 0;
            F(i,0,n-1)
            {
                windowSum += arr[i];
                if (i >= k - 1)
                {
                    ma = max(windowSum, ma);
                    windowSum -= arr[windowStart];
                    ++windowStart;
                }
            }
            m = max(m, ma / (k + 0.0));
        }
        O<<fixed<<setprecision(6)<<m<<'\n';
    }
    return 0;
}
