#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

bool isPowerOfTwo (ll x) {
    return x and (!(x&(x-1)));
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll tests, n, i, j, k, l, min, max, t1;
    I>>tests;
    while (tests--)
    {
        min = LONG_LONG_MAX;
        max = LONG_LONG_MIN;
        t1 = 0;
        float tim;
        I>>n;
        ll velocity[n];
        
        F(i,0,n-1)
            I>>velocity[i];

        float time_table[n][n];
        F(i,0,n-1)
            F(j,0,n-1)
                time_table[i][j] = -2;

        F(j,0,n-1)
            F(k,0,n-1)
                if (velocity[j] != velocity[k])
                {
                    tim = (k - j + 0.0) / (velocity[j] - velocity[k]);
                    if (tim < 0)
                        continue;
                    time_table[j][k] = tim;
                }

        F(j,0,n-1)
        {
            ll inf[n];
            F(i,0,n-1)
                inf[i] = 0;

            inf[j] = 1;

            F(k,0,n-1)
                if (time_table[j][k] != -2)
                {
                    inf[k] = 1;
                    F(l,0,n-1)
                        if (inf[l] == 0 and time_table[k][l] >= time_table[j][k])
                            inf[l] = 1;
                }

            t1 = 0;
            F(k,0,n-1)
            {
                if (inf[k] == 0)
                    continue;
                ++t1;
            }
            min = min > t1 ? t1 : min;
            max = max < t1 ? t1 : max;
        }
        O << min << ' ' << max << '\n';
    }
    return 0;
}