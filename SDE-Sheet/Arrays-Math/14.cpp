#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007


// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}



long long power(int N,int R);

int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        
        //power of the number to it's reverse
        long long ans =power(N,R);
        cout << ans<<endl;
    }
}

long long power(int N, int R)
{
   const long long M = 1e9 + 7;
   long long ans = 1;
   long long n = N;
   N %= M;
   while (R)
   {
        if (R & 1)
            ans = (ans * n) % M;
        n = (n * n) % M;
        R >>= 1;
   }
   return ans;
}
