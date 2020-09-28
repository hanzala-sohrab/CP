#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> CCnum;
int cc, n, m;

void explore(int v) {
    visited[v] = true;
    CCnum[v] = cc;
    int i, w;
    for (i = 0; i < adj[v].size(); ++i)
    {
        w = adj[v][i];
        if (!visited[w])
            explore(w);
    }
}

void dfs() {
    visited.resize(n, false);
    cc = 0;
    int v;
    for (v = 0; v < n; ++v)
        if (!visited[v])
        {
            explore(v);
            ++cc;
        }
}

void graph_input() {
    cin >> n >> m;
    adj.resize(n);
    CCnum.resize(n);
    int i, x, y;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    dfs();
}

int main() {
    graph_input();
    cout << cc << '\n';
    return 0;
}