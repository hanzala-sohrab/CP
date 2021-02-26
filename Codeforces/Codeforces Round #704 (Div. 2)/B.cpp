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
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I>>n;
        V<ll>p(n), a(n+1,0), prefix(n+1,0), b(n+1,0);
        F(i,0,n-1)
        {
            I>>p[i];
            a[p[i]] = i;
        }
        prefix[1] = p[0];
        F(i,2,n)
            prefix[i] = max(prefix[i-1], p[i-1]);
        j = 1;
        q = n;
        for (i = n; i > 0 and j <= n;)
        {
            k = prefix[i];
            b[j] = k;
            j += q - a[k];
            i = a[k];
            q = i;
        }
        F(i,1,n)
        {
            if (!b[i])
                continue;
            j = a[b[i]] + 2;
            F(k,j,n)
                if (i + 1 <= n)
                {
                    if (b[i + 1])
                        break;
                    b[++i] = p[k - 1];
                }
        }
        F(i,1,n)
            O<<b[i]<<' ';
        O<<'\n';
    }
    return 0;
}
