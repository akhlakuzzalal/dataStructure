#include <bits/stdc++.h>

using namespace std;

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

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    return 0;
}