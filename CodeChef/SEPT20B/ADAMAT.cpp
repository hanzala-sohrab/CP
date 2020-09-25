#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, i, count = 0, j, k, c;
    I >> t;
    while (t--)
    {
        I >> n;

        ll matrix[n][n];
        F(i,0,n-1)
            F(j,0,n-1)
                I >> matrix[i][j];

        c = 0;

        // Checking if sorted.
        bool is_sorted = true;
        F(i,0,n-1)
            F(j,0,n-1)
                if (matrix[i][j] != ++c)
                    is_sorted = false;

        // if sorted, then nothing to do.
        if (is_sorted)
        {
            cout << "0\n";
            continue;
        }

        count = 0;
        ll R[n + 1], C[n + 1];
        F(i,0,n)
            R[i] = C[i] = 0;
        F(i,1,n)
            F(j,0,n-1)
                F(k,0,n-1)
                    if (matrix[j][k] == i)
                    {
                        R[i] = j;
                        C[i] = k;
                    }
        
        // Finding transpose.
        for (i = n; i > 1; --i)
            if (C[i] == 0)
            {
                F(j,0,i-1)
                    F(k,j+1,i-1)
                        swap(matrix[j][k], matrix[k][j]);
                for (j = i - 1; j > 1; --j)
                    swap(R[j], C[j]);
                ++count;
            }
        O << count << '\n';
    }
    return 0;
}