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
    ll n, i, j, k, c = 0, M = INT_MIN;
    string s;
    I>>n>>s;
    V<ll> a(n), b(n);
    F(i,0,n-1)
        I>>a[i]>>b[i];
    V<V<ll>> v(101, V<ll>(1001,-1));
    F(i,0,n-1)
        v[i][0] = s[i] - 48;
    F(i,0,n-1)
    {
        bool on = s[i] - 48;
        F(j,0,b[i] - 1)
        {
            v[i][j] = on;
        }
    }
    F(i,0,n-1)
    {
        bool on = s[i] - 48;
        for (j = b[i]; j < 1001; j += a[i])
        {
            if (on)
            {
                v[i][j] = 0;
                on = false;
            }
            else if (!on)
            {
                v[i][j] = 1;
                on = true;
            }
        }
    }
    F(i,0,n-1)
    {
        // bool on = s[i] - 48;
        F(j,b[i],1000)
        {
            if (v[i][j - 1] == 0)
            {
                while (j < 1001 and (v[i][j] == -1 or v[i][j] == 1))
                {
                    v[i][j] = 1;
                    ++j;
                }
                --j;
            }
            else
            {
                while (j < 1001 and (v[i][j] == -1 or v[i][j] == 0))
                {
                    v[i][j] = 0;
                    ++j;
                }
                --j;
            }
        }
    }
    F(j,0,1000)
    {
        c = 0;
        F(i,0,n-1)
            if (v[i][j] == 1)
                ++c;
        M = max(M, c);
        if (M == n)
            break;
    }
    O<<M<<'\n';
    return 0;
}
