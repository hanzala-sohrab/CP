#include <bits/stdc++.h>
using namespace std;
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    int n,i,j,k;
	I>>n;
	int a[n],dp[6]={0};
	for(int &i : a){
		cin>>i;
		if(i==4)
			++dp[0];
		else if(i==8)
			dp[1]=min(dp[0],dp[1]+1);
		else if(i==15)
			dp[2]=min(dp[1],dp[2]+1);
		else if(i==16)
			dp[3]=min(dp[2],dp[3]+1);
		else if(i==23)
			dp[4]=min(dp[3],dp[4]+1);
		else
			dp[5]=min(dp[4],dp[5]+1);
	}
	O<<n-dp[5]*6<<'\n';
    return 0;
}