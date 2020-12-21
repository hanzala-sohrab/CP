/*
Pongal Bunk
--------------------
Use scanline algorithm

Create two prefix sum arrays - A1 and A2.

    A1 array stores the frequency of all the indices (i.e. how many times a particular index
    occurs in an interval [L, R]).

    A1[L] += 1
    A1[R + 1] -= 1

    A2[L] -= L - 1
    A2[R + 1] += L - 1

Find prefix sum for both the arrays

Finally, create a new array B
    
    B[i] = A2[i] + i * A1[i]

NOTE : i, L, R belong to the range [1, N].
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll N, Q, M, L, R, l, i;
    I>>N;
    V<ll> A(N,0), A1(N+1, 0), A2(N+1,0), B(N);
    I>>Q;
    F(i,0,Q-1)
    {
        I>>L>>R;
        // Prefix sum trick
        A1[L - 1] += 1;
        A1[R] -= 1;

        A2[L - 1] -= L - 1;
        A2[R] += L - 1;
    }
    F(i,0,N-1)
    {
        A1[i + 1] += A1[i];
        A2[i + 1] += A2[i];
    }
    F(i,0,N-1)
        B[i] = A2[i] + (i + 1) * A1[i];

    I>>M;
    F(i,0,M-1)
    {
        I>>l;
        O<<B[l-1]<<'\n';
    }
    return 0;
}
