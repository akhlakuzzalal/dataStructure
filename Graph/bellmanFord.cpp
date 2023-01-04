#include <bits/stdc++.h>

using namespace std;
int INF = 1e9;

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: " << endl;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    cout << "Enter the edges and their weights: " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int source;
    cout << "Enter the source node: " << endl;
    cin >> source;
    vector<int> dist(n + 1, (INF));
    dist[source] = 0;
    bool detectCycle = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if (dist[v] > dist[u] + w)
                {
                    detectCycle = true;
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    if (detectCycle)
    {
        cout << "Negative cycle Present" << endl;
    }
    cout << "The shortest distances from the source node are: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "from " << source << " to " << i << " : " << dist[i] << endl;
    }
    cout << endl;

    return 0;
}