/*
    * 1187B - Letters Shop
    * 
    * For each letter in 's', create an array 'alph' that stores all the indices where that letter occurs
    * For each name, first sort it in alphabetical order, then count the occurrence of each character
    * Find the last position required for each character using the 'count' array and the 'alph' array
    * ans = max(ans, alph[ch][count[ch] - 1])
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, l, m, j, k = 0;
    string s;
    I>>n>>s>>m;
    V<string> names(m);
    V<V<ll>> alph(26);
    F(i,0,n-1)
        alph[s[i] - 97].pb(i);
    F(i,0,m-1)
        I>>names[i];
    F(i,0,m-1)
    {
        string name = names[i];
        sort(all(name));
        ll ans = 0;
        V<ll> count(26, 0);
        for (char c: name)
            ++count[c - 97];
        F(j,0,25)
            if (count[j])
                ans = max(ans, alph[j][count[j] - 1]);
        O<<ans + 1<<'\n';
    }
   return 0;
}
