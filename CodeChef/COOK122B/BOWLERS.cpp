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
    ll t,n,q,i,j,k,l;
    I>>t;
    while (t--)
    {
        I>>n>>k>>l;
        ll m = 1e4;
        V<ll> overs(m,0), bowlers(m, 0);
        F(i,0,k-1)
        {
            for (j = 0; j < n; ++j)
            {
                if (bowlers[i] < l and overs[j] == 0)
                {
                    overs[j] = i + 1;
                    ++bowlers[i];
                    j += k - 1;
                }
            }
        }
        bool possible = true;
        F(i,0,n-1)
            if (overs[i] == 0 or (i > 0 and overs[i - 1] == overs[i]))
            {
                possible = false;
                break;
            }
        if (!possible)
            O<<"-1\n";
        else
        {
            F(i,0,n-1)
                O<<overs[i]<<' ';
            O<<'\n';
        }
        
    }
    return 0;
}
