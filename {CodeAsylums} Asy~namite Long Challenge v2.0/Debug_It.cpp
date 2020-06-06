#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

long long add(string a , string b) 
	{
		long long sum = 0;
		int j = 0;
		for(int i = a.size()-1 ; i >= 0 ; i--)
			{
				sum += ((long long)(a[i] - '0'))*((long long)pow(10 , j));
				j += 1; 
			}
			
		j = 0;
		
		for(int i = b.size()-1 ; i >= 0 ; i--) 
			{
				sum += ((long long)(b[i] - '0'))*((long long)pow(10 , j));
				j += 1; 
			}
			
		return sum;		
	}

long long eval(string a , string b)
	{
		if(a.size() < b.size())
			{
				int j = b.size() - a.size();
				for(int i = 0 ; i < a.size() ; i++)
					{
						if(a[i] = b[j]) 
							{
								a.erase(a.begin() + i);
								b.erase(b.begin() + j);
								i--;
								j--;
							}
						j++;
					}
			}
		else
			{
				int j = a.size() - b.size();
				for(int i = 0 ; i < b.size() ; i++)
					{
						if(b[i] == a[j])
							{
								b.erase(b.begin() + i);
								a.erase(a.begin() + j);
								i--;
								j--;
							}
						j++;
					}
			}
			
		return add(a , b);
	}
int main()
	{
		string a , b;
		cin>>a>>b;
		
		long long sum = 0;
		
		sum = eval(a , b );
		cout<<sum;
		
		return 0;
	}