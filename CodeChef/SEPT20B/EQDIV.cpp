#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::to_string;
using std::string;

#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    string op;
    ll T, K;
    scanf("%lld %lld", &K, &T);
    while (T--)
    {
        ll N, i, j, S;

        scanf("%lld", &N);

        S = (N * (N + 1)) / 2;

        char str[N];
        F(i,0,N-1)
            if (i < N - 1)
                str[i] = '0';
            else
                str[i] = '1';

        j = N;
        i = j - 4;

        while (i >= 0)
        {
            j += i + 1;
            str[i] = '1';
            if (i > 0)
            {
                str[i - 1] = '1';
                j += i;
                --i;
            }
            i = i - 3;
        }

        op += to_string(abs(S - 2 * j)) + "\n";

        F(i,0,N-1)
            op += str[i];

        op += "\n";
    }
    O<<op;
    return 0;
}