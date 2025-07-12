#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, n;
        string game;

        I >> n >> game;

        if (n == 2)
        {
            O << (game[0] == 'A' ? "Alice" : "Bob") << '\n';
            continue;
        }

        V<int> aliceCards, bobCards;

        if (game[0] == game[n - 1])
        {
            O << (game[0] == 'A' ? "Alice" : "Bob") << '\n';
            continue;
        }

        F(i, 0, n - 1)
        {
            if (game[i] == 'A')
            {
                aliceCards.pb(i);
            }
            else
            {
                bobCards.pb(i);
            }
        }

        int A = aliceCards.size();
        const int B = bobCards.size();

        if (B > 0 and bobCards[0] == n - 1)
        {
            O << "Alice\n";
            continue;
        }

        int alice = aliceCards[A - 1];

        if (alice == n - 1)
        {
            aliceCards.pop_back();
            --A;
            alice = aliceCards[A - 1];
        }

        string winner = "Bob";

        int j = upper_bound(all(bobCards), alice) - bobCards.begin();

        if (j == B)
        {
            winner = "Alice";
        }

        O << winner << '\n';
    }
    return 0;
}
