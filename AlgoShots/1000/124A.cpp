#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b<n){
    	std::cout << b+1 << std::endl;
    	return 0;
    }
    else if(a+b == n){
    	std::cout << b << std::endl;
    }
    else{
    	std::cout << n-a << std::endl;
    }
    
    return 0;
}