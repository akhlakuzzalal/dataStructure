#include <bits/stdc++.h>

using namespace std;
bool isPresent(vector<int> &v, int ele)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ele)
            return true;
    }
    return false;
}

int firstIndex(vector<int> &v, int ele)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ele)
            return i;
    }
    return -1;
}

void dfs(int source, vector<vector<int>> &adj, vector<int> &visited)
{
    cout << source << " ";
    visited[source] = 1;
    for (int i = 0; i < adj[source].size(); i++)
    {
        int v = adj[source][i];
        if (adj[source].size() == 0 && isPresent(visited, 0) == true)
        {
            int newSource = firstIndex(visited, 0);
            dfs(newSource, adj, visited);
        }
        else if (visited[v] == 0)
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