#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	long int n;
	cin>>n;
	vector<long int> a[3];
	long int ans=0,temp=0;
	
	/* In vector a, a[0],a[1] and a[2] contains the integer 
	   corresponding to "00", "01" and "10" respectively.
	   temp is the count of "11" strings.*/
	for(long int i=0;i<n;i++)
	{
	    string s;
        int aa;
	    cin>>s>>aa;
	    if(s=="11")
	    {
	        ans+=aa;
	        temp++;
	    }
	    else if(s=="00")
	    a[0].push_back(aa);
	    else if(s=="01")
	    a[1].push_back(aa);
	    else
	    a[2].push_back(aa);
	}
	
	// temp1 is the number of pairs of "01" and "10" strings.
	int temp1=min(a[1].size(),a[2].size());
	// Sorting in descending order.
	sort(a[1].begin(),a[1].end(),greater<long int>());
	sort(a[2].begin(),a[2].end(),greater<long int>());
	for(long int i=0;i<temp1;i++)
	{
	    ans+=a[1][i]+a[2][i];
	}
	
	//Adding the extra elements to a[0] vector.
	if(a[1].size()>a[2].size())
	{
	    for(long int i=temp1;i<a[1].size();i++)
	    {
	        a[0].push_back(a[1][i]);
	    }
	}
	else
	{
	    for(long int i=temp1;i<a[2].size();i++)
	    {
	        a[0].push_back(a[2][i]);
	    }
	}
	sort(a[0].begin(),a[0].end(),greater<long int>());
	long int l=a[0].size();
	int temp3=min(temp,l);
	for(long int i=0;i<temp3;i++)
	    ans+=a[0][i];
	cout<<ans<<endl;
	return 0;
}