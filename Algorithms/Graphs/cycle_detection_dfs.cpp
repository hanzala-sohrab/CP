/*
 * Cycle detection in undirected graph using DFS
 *
 */
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

vector<vector<int>> adj;
vector<bool> visited;
int n, m;

void explore(int v, int u, bool &val) {
	visited[v] = true;
	int i, w;
	for (i = 0; i < adj[v].size(); ++i)
	{
		w = adj[v][i];
		if (u == w)
			continue;
		if (!visited[w])
			explore(w, v, val);
		else
		{
			val = true;
			return;
		}
	}
}

bool dfs() {
	visited.resize(n, false);
	int v;
	bool found = false;
	for (v = 0; v < n; ++v)
		if (!visited[v])
		{
			explore(v, -1, found);
			if (found)
				break;
		}
	return found;
}

void graph_input() {
	cin >> n >> m;
	adj.resize(n);
	int i, x, y;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	if (dfs())
		cout << "Cycle found\n";
	else
		cout << "No cycle found\n";
}

int main() {
	graph_input();
	return 0;
}
