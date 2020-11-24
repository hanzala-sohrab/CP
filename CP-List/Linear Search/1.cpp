#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, i, K;
    cin >> N;
    int a[N];
    for (i = 0; i < N; ++i)
        cin >> a[i];
    cin >> K;
    for (i = 0; i < N; ++i)
        if (a[i] == K)
            break;
    cout << i << '\n';
    return 0;
}