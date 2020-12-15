#include <bits/stdc++.h>
using namespace std;

#define M 1000002
 
void GenPrime();
void DigitPrime();
long int prime[M];
long int dprime[M];
 
int main()
{
    GenPrime();
    DigitPrime();
    long int t,t1,t2,i,sum,n,j,total;
    while(scanf("%ld",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%ld%ld",&t1,&t2);
            total=dprime[t2]-dprime[t1-1];
            printf("%ld\n",total);
        }
    }
    return 0;
}
 
void GenPrime()
{
    long int i,j,m;
    m=(long int)sqrt(M);
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=0;
    for(i=2;i<=m;i++)
    {
        if(prime[i])
        {
            for(j=i+i;j<M;j+=i)
                prime[j]=0;
        }
 
    }
 
}
void DigitPrime()
{
    long int n,i,nodprime,sum;
    nodprime=0;
    for(i=2;i<M;i++)
    {
        if(prime[i])
        {
            sum=0;
            n=i;
            while(n>9)
            {
                sum+=n%10;
                n/=10;
            }
            sum+=n;
            if(prime[sum])
                nodprime+=1;
        }
        dprime[i]=nodprime;
    }
}
