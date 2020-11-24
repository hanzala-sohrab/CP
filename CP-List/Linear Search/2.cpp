/*
    Just find the sum of all positive integers and also count the number of positive integers.
    If no positive integer is present, then simply print the largest integer.
*/
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int N, i, maxN = INT_MIN;
    long long s = 0, c = 0;
    cin >> N;
    int A[N];
    for (i = 0; i < N; ++i)
        cin >> A[i];
    for (i = 0; i < N; ++i)
    {
        if (A[i] >= 0)
        {
            s = s + A[i];
            ++c;
        }
        else
            maxN = max(maxN, A[i]);
    }
    if (c)
        cout << s << ' ' << c << '\n';
    else
        cout << maxN << " 1\n";
    return 0;
}
