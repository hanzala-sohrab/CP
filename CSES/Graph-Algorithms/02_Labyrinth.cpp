#include<bits/stdc++.h>
using namespace std;

int n, m, rA, cA, rB, cB;
char labyrinth[1001][1001];
bool visited[1001][1001];
char paths[1001][1001];
vector<char> shortestPath;

bool is_valid(int r, int c) {
	if (r < 0 or r >= n or c < 0 or c >= m or visited[r][c] or labyrinth[r][c] == '#')
		return false;
	return true;
}

bool bfs() {
	queue<pair<int, int>> q;
	q.push({rA, cA});
	memset(visited, 0, sizeof(visited));
	visited[rA][cA] = 1;

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (labyrinth[r][c] == 'B')
		{
			while (1)
			{
				shortestPath.push_back(paths[r][c]);
				if (shortestPath.back() == 'U')
					++r;
				if (shortestPath.back() == 'R')
					--c;
				if (shortestPath.back() == 'D')
					--r;
				if (shortestPath.back() == 'L')
					++c;

				if (labyrinth[r][c] == 'A')
					break;
			}
			return true;
		}

		if (is_valid(r - 1, c))
		{
			q.push({r - 1, c});
			paths[r - 1][c] = 'U';
			visited[r - 1][c] = 1;
		}
		if (is_valid(r, c + 1))
		{
			q.push({r, c + 1});
			paths[r][c + 1] = 'R';
			visited[r][c + 1] = 1;
		}
		if (is_valid(r + 1, c))
		{
			q.push({r + 1, c});
			paths[r + 1][c] = 'D';
			visited[r + 1][c] = 1;
		}
		if (is_valid(r, c - 1))
		{
			q.push({r, c - 1});
			paths[r][c - 1] = 'L';
			visited[r][c - 1] = 1;
		}
	}
	return false;
}

void input() {
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
		{
			cin >> labyrinth[i][j];
			if (labyrinth[i][j] == 'A')
				rA = i, cA = j;
			else if (labyrinth[i][j] == 'B')
				rB = i, cB = j;
		}
}

int main() {
	input();
	if (bfs())
	{
		int i, l = shortestPath.size();
		cout << "YES\n" << l << '\n';
		for (i = l - 1; i >= 0; --i)
			cout << shortestPath[i];
	}
	else
		cout << "NO";
	cout << '\n';
	return 0;
}
