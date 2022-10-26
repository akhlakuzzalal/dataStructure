#include <bits/stdc++.h>

using namespace std;

int main()
{

    int v, e;
    cout << "enter vertex and edges" << endl;
    cin >> v >> e;
    cout << "node :" << v << "edges :" << e << endl;
    vector<vector<int>> adj(v);
    vector<int> inDegree(v, 0);
    for (int i = 0; i < e; i++)
    {
        int n, edge;
        cout << "enter node and edges" << endl;
        cin >> n >> edge;
        adj[n].push_back(edge);
        inDegree[edge]++;
    }

    queue<int> Q;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
            Q.push(i);
    }

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        cout << x << " ";
        for (auto it : adj[x])
        {
            inDegree[x]--;
            inDegree[it]--;
            if (inDegree[it] == 0)
                Q.push(it);
        }
    }

    return 0;
}