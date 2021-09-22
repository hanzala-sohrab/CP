#include <bits/stdc++.h>
using namespace std;

int n, m, cc;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> CCnum;

void explore(int u)
{
    visited[u] = true;
    CCnum[u] = cc;
    int i, v, l = adj[u].size();
    for (i = 0; i < l; ++i)
    {
        v = adj[u][i];
        if (!visited[v])
            explore(v);
    }
}

void dfs()
{
    cc = 0;
    visited.resize(n, false);
    CCnum.resize(n, -1);
    int i;
    for (i = 0; i < n; ++i) 
        if (!visited[i])
        {
            explore(i);
            ++cc;
        }
}

void input()
{
    cin >> n >> m;
    adj.resize(n);
    int i, j;
    for (j = 0; j < m; ++j)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main()
{
    input();
    dfs();
    int i, j = 0;
    vector<int> nodes(cc, 0);
    for (i = 0; i < n; ++i)
        if (!nodes[CCnum[i]])
            nodes[CCnum[i]] = i + 1;
    i = nodes[0];
    cout << cc - 1 << '\n';
    for (j = 0; j < cc; ++j)
        if (i != nodes[j])
            cout << i << ' ' << nodes[j]<< '\n';
    return 0;
}
