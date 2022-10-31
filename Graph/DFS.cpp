#include <bits/stdc++.h>

using namespace std;

void dfs(int source, vector<vector<int>> &adj, vector<int> &visited)
{
    cout << source << " ";
    visited[source] = 1;
    for (int i = 0; i < adj[source].size(); i++)
    {
        int v = adj[source][i];
        if (visited[v] == 0)
        {
            dfs(v, adj, visited);
        }
    }
}

int main()
{
    int node, vartex;
    cin >> node >> vartex;
    vector<vector<int>> adj(node);
    vector<int> visited(node, 0);

    for (int i = 0; i < vartex; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, adj, visited);
    return 0;
}