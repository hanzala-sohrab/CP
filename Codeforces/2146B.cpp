#include <bits/stdc++.h>
using namespace std;

bool is_possible(int n, int m, const vector<unordered_set<int>>& sets) {
    vector<int> freq(m + 1, 0);

    // Count frequency of each element across all sets
    for (const auto& s : sets) {
        for (int el : s) {
            freq[el]++;
        }
    }

    // Check if all elements from 1..m are present
    for (int i = 1; i <= m; i++) {
        if (freq[i] == 0)
            return false;
    }

    // Build union of all sets
    unordered_set<int> union_set;
    for (const auto& s : sets) {
        union_set.insert(s.begin(), s.end());
    }

    int cnt = 1;

    for (int i = 0; i < n; i++) {
        const auto& s = sets[i];
        bool flag = true;

        // Temporarily remove elements of current set from frequency
        for (int el : s) {
            freq[el]--;
            if (freq[el] == 0)
                flag = false;
        }

        if (flag)
            cnt++;

        // Restore frequencies
        for (int el : s) {
            freq[el]++;
        }
    }

    return cnt >= 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<unordered_set<int>> sets;

        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            unordered_set<int> s;
            for (int j = 0; j < l; j++) {
                int x;
                cin >> x;
                s.insert(x);
            }
            sets.push_back(move(s));
        }

        cout << (is_possible(n, m, sets) ? "yes" : "no") << "\n";
    }

    return 0;
}

