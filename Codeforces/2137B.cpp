#include <bits/stdc++.h>
using namespace std;

vector<int> f(const vector<int>& p, int n) {
    int M = n + 1;
    vector<int> q;
    q.reserve(p.size());
    for (int i : p) {
        q.push_back(M - i);
    }
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        vector<int> q = f(p, n);
        for (int i = 0; i < q.size(); i++) {
            cout << q[i] << (i + 1 < q.size() ? ' ' : '\n');
        }
    }
    return 0;
}

