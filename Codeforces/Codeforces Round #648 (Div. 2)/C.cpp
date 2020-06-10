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

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    // I>>t;
    t = 1;
    while (t--)
    {
        I >> n;
        V<ll> a(n), b(n);
        F (i, 0, n - 1)
            I >> a[i];
        F (i, 0, n - 1)
            I >> b[i];
        ll m = 0, c;
        F (i, 0, n - 1)
        {
            F (j, 0, n - 1)
            {
                if (b[j] == a[i])
                {
                    k = j - i;
                    c = 0;
                    F (q, 0, n - 1)
                    {
                        if (a[q] == b[(q + k) % n])
                            ++c;
                    }
                    m = max(m, c);
                }
            }
        }
        O << m << '\n';
    }
    return 0;
}
