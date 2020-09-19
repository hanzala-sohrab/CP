#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define ff first
#define ss second
#define mp make_pair

struct Log {
    string from;
    string to;
    ll t;
};

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n,d,i,j,k;
    I>>n>>d;
    V<Log> logs(n);
    F(i,0,n-1)
        I>>logs[i].from>>logs[i].to>>logs[i].t;
    multimap<string, string> friends;
    F(i,0,n-1)
    {
        Log l = logs[i];
        string from1 = logs[i].from;
        string to1 = logs[i].to;
        ll t1 = logs[i].t;
        F(j,i+1,n-1)
        {
            string from2 = logs[j].from;
            string to2 = logs[j].to;
            ll t2 = logs[j].t;
            if (from1 == to2 and from2 == to1)
                if (t1 != t2 and t2 - t1 <= d)
                {
                    bool found = false;
                    for (auto f = friends.begin(); f != friends.end(); ++f)
                        if ((f->ff == from1 and f->ss == to1) or (f->ff == from2 and f->ss == to2))
                        {
                            found = true;
                            break;
                        }
                    if (!found)
                        friends.insert(mp(from1, to1));
                }
        }
    }
    n = friends.size();
    O<<n<<'\n';
    if (n)
        for (auto f: friends)
            O<<f.ff<<' '<<f.ss<<'\n';
    return 0;
}