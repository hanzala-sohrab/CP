/*
    * 1367C - Social Distance
    * 
    * Use preffix and suffix array
    * 
    * Prefix array 'pref' will store the nearest '1' left to a particular '0'.
    * Suffix array 'suff' will store the nearest '1' right to a particular '0'.
    * 
    * If, at a particular index having value '0', (pref[i] == -1 or i - pref[i] > k) and (suff[i] == -1 or suff[i] - i > k)
    * Then, ++answer and move 'k' tables (or indices) forward (i.e. i += k)
*/
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
    ll t,n,i,a,k;
    I>>t;
    while (t--)
    {
        string s;
        a = 0;
        I>>n>>k>>s;
        V<ll> pref(n,-1), suff(n, -1);
        F(i,0,n-1)
        {
            if (s[i] == '1')
                pref[i] = suff[i] = i;
            else if (i)
                pref[i] = pref[i - 1];
        }
        for (i = n - 2; i >= 0; --i)
            if (s[i] == '0')
                suff[i] = suff[i + 1];
        F(i,0,n-1)
        {
            if (s[i] == '0' and (i - pref[i] > k or pref[i] == -1) and (suff[i] - i > k or suff[i] == -1))
            {
                pref[i] = suff[i] = i;
                if (i + 1 + k < n)
                    pref[i + k + 1] = i;
                ++a;
                i += k;
            }
        }
        O<<a<<'\n';
    }
    return 0;
}
