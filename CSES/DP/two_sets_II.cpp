#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000000007

ll n;

void input() {
    cin >> n;
}

void output() {
    ll s, i, j;
    s = (n * (n + 1)) / 2;
    if (s & 1)
    {
        cout << "0\n";
        return;
    }
    s >>= 1;
    int table[n + 1][s + 1];
    table[0][0] = 1;
    for (i = 1; i <= n; ++i)
        table[i][0] = 1;
    for (i = 1; i <= s; ++i)
        table[0][i] = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= s; ++j)
            if (j >= i)
                table[i][j] = (table[i - 1][j - i] + table[i - 1][j]) % M;
            else
                table[i][j] = table[i - 1][j];
    if (table[n][s] & 1)
        table[n][s] += M;
    cout << table[n][s] / 2 << '\n';
}

int main(int argc, char const *argv[])
{
    input();
    output();
    return 0;
}
