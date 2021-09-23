#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist, pred;

void dijkstra(int src = 0)
{
    visited.resize(n, false);
    pred.resize(n);
    dist.resize(n, INT_MAX);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(src);
    dist[src] = 0;
    pred[src] = -1;
    int i;
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();

        for (i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push(v);
                pred[v] = u;
            }
        }
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
    dijkstra();
    if (dist[n - 1] == INT_MAX)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dist[n - 1] + 1 << '\n';
        int i = n - 1;
        vector<int> route;
        route.push_back(n);
        while (i > 0)
        {
            route.push_back(pred[i] + 1);
            i = pred[i];
        }
        for (i = route.size() - 1; i >= 0; --i)
            cout << route[i] << ' ';
    }
    cout << '\n';
    return 0;
}
