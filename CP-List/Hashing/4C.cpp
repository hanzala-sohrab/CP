#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int i, n;
    cin >> n;
    unordered_map<string, vector<string>> m;
    for (i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (m.find(s) == m.end())
        {
            vector<string> a = {s};
            m.insert(make_pair(s, a));
            cout << "OK\n";
        }
        else
        {
            int l = m[s].size();
            string x = s + to_string(l);
            m[s].push_back(x);
            cout << x << '\n';
        }
    }
    return 0;
}
