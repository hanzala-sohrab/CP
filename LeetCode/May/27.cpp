class Solution {
public:
    vector<vector<int>> adj;
    vector<int> color;
    vector<bool> visited;
    bool ans;
    void explore(int v) {
        visited[v]=true;
        for (int j=0;j<adj[v].size();++j)
        {
            int u=adj[v][j];
            if (visited[u] && visited[v] && color[u] == color[v])
            {
                ans=false;
                return;
            }
            color[u]=color[v]?0:1;
            if (!visited[u])
                explore(u);
        }
    }
    void dfs() {
        for (int v=1;v<adj.size();++v)
            if (!visited[v])
                explore(v);
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N==1)
            return true;
        adj.resize(N+1);
        visited.resize(N+1, false);
        color.resize(N+1);
        color[1]=1;
        ans=true;
        int i, l = dislikes.size();
        adj[0].push_back(0);
        for (int i=0;i<l;++i)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        dfs();
        return ans;
    }
};
