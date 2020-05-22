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
    ll ls,lt,i,j;
    string s,t;
    I>>s>>t;
    ls=s.size();
    lt=t.size();
    vector<vector<ll>> dp(lt+1, vector<ll> (ls+1,0));
    string a;
    F(i,1,lt)
    {
        F(j,1,ls)
        {
            if (s[j-1]==t[i-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    i=lt;
    j=ls;
    while (1)
    {
        while (1)
        {
            if (s[j-1]==t[i-1])
            {
                a=s[j-1]+a;
                --i;
                --j;
            }
            else if (dp[i][j-1] > dp[i-1][j])
            {
                --j;
            }
            else if (dp[i][j-1] <= dp[i-1][j])
            {
                --i;
            }
            if (j==0||i==0)
                break;
        }
        if (j==0||i==0)
            break;
    }
    O<<a<<'\n';
    // O<<dp[lt][ls]<<'\n';
    return 0;
}