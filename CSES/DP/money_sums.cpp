#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> x;
void input()
{
    cin >> n;
    x.resize(n);
    for (int i=0;i<n;++i)
        cin>>x[i];
}
void output()
{
    int i, j, s = 0, k=0;
    for (i=0;i<n;++i)
        s+=x[i];
    int dp[n+1][s+1];
    dp[0][0] = 1;
    for (i=1;i<=n;++i)
        dp[i][0]=1;
    for (i=1;i<=s;++i)
        dp[0][i]=0;
    for (i=1;i<=n;++i)
        for (j=1;j<=s;++j)
            if (j>=x[i-1])
                dp[i][j]=dp[i-1][j-x[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
    for (i=1;i<=s;++i)
        if (dp[n][i])
            ++k;
    cout<<k<<'\n';
    for (i=1;i<=s;++i)
        if (dp[n][i])
            cout<<i<<' ';
    cout<<'\n';
}
int main(int argc, char const *argv[])
{
    input();
    output();
    return 0;
}
