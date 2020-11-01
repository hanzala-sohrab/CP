#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll a,b,x,i;
    I>>a>>b>>x;
    string s;
    if (x & 1)
    {
        if (a <= b)
        {
            F(i,0,x/2-1)
                s += "10";
            F(i,0,b-x/2-1)
                s+="1";
            F(i,0,a-x/2-1)
                s+="0";
        }
        else
        {
            F(i,0,x/2-1)
                s+="01";
            F(i,0,a-x/2-1)
                s+="0";
            F(i,0,b-x/2-1)
                s+="1";
        }
    }
    else
    {
        if (a <= b)
        {
            F(i,0,x/2-1)
                s+="10";
            F(i,0,a-x/2-1)
                s+="0";
            F(i,0,b-x/2-1)
                s+="1";
        }
        else
        {
            F(i,0,x/2-1)
                s+="01";
            F(i,0,b-x/2-1)
                s+="1";
            F(i,0,a-x/2-1)
                s+="0";
        }
    }
    O<<s<<'\n';
    return 0;
}
