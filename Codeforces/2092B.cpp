#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int countOfOnesOccurringAtEvenIndicesOfA = 0;
        int countOfOnesOccurringAtOddIndicesOfA = 0;
        int countOfZerosOccurringAtOddIndicesOfB = 0;
        int countOfZerosOccurringAtEvenIndicesOfB = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i & 1)
            {
                if (a[i] == '1')
                {
                    ++countOfOnesOccurringAtOddIndicesOfA;
                }
                if (b[i] == '0')
                {
                    ++countOfZerosOccurringAtOddIndicesOfB;
                }
            }
            else
            {
                if (a[i] == '1')
                {
                    ++countOfOnesOccurringAtEvenIndicesOfA;
                }
                if (b[i] == '0')
                {
                    ++countOfZerosOccurringAtEvenIndicesOfB;
                }
            }
        }

        cout << (countOfOnesOccurringAtEvenIndicesOfA <= countOfZerosOccurringAtOddIndicesOfB and countOfOnesOccurringAtOddIndicesOfA <= countOfZerosOccurringAtEvenIndicesOfB ? "YES" : "NO") << '\n';
    }
    return 0;
}
