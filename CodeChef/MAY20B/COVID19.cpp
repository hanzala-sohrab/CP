#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define M 1000000007



int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    ll t,n,q,i,j;
    cin>>t;
    while (t--)
    {
        cin>>n;
        ll d=1,m=INT_MAX,ma=0;
        vector<ll>x(n+1);
        x[n]=INT_MAX;
        for (i=0;i<n;++i)
        {
            cin>>x[i];
        }
        for (i=0;i<=n;++i)
        {
            if (i>0&&x[i]-x[i-1]<=2)
                ++d;
            else if (x[i]-x[i-1]>2)
            {
                m=min(m,d);
                ma=max(ma,d);
                d=1;
            }
        }
        if (m==INT_MAX)
            m=ma=d;
        cout<<m<<' '<<ma<<'\n';
    }
    return 0;
}