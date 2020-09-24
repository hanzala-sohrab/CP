#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

bool is_prime(int n) {
    if (n == 3 or n == 5 or n == 7)
        return true;
    if (n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0)
        return false;
    for (int i = 6; i * i < n; i += 6)
        if (n % (i - 1) == 0 or n % (i + 1) == 0)
            return false;
    return true;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    int n,i,j,e,t;
    I>>n;
    V<V<int>> m(n+1, V<int>(n+1,-1));
    F(i,1,n)
        if (i == n)
            m[n][1] = 1;
        else
            m[i][i + 1] = 1;

    e = n;
    if (!is_prime(n))
    {
        for (i = n + 1; ; ++i)
            if (is_prime(i))
                break;
        e = i;
        t = n;
        V<bool> visited(n + 1, false);
        F(i,1,n-2)
        {
            if (!visited[i] and !visited[i+2])
            {
                visited[i] = visited[i + 2] = true;
                m[i][i + 2] = 1;
                ++t;
            }
            if (t == e)
                break;
        }
    }
    O<<e<<'\n';
    F(i,1,n)
        F(j,1,n)
            if (m[i][j] == 1)
                O<<i<<' '<<j<<'\n';
    return 0;
}