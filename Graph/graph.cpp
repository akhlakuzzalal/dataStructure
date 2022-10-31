#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> lwData;

class Graph
{
    int V;
    list<lwData> *listOfConnections;

public:
    Graph(int V)
    {
        this->V = V;
        listOfConnections = new list<lwData>[V];
    }

    void addEdges(int u, int v, int w)
    {
        listOfConnections[u].push_back(make_pair(v, w));
        listOfConnections[v].push_back(make_pair(u, w));
    }

    void print(int chk)
    {
        cout << chk << ":";
        for (auto i = listOfConnections[chk].begin(); i != listOfConnections[chk].end(); i++)
        {
            cout << "(" << (*i).first << "|" << (*i).second << ")";
        }
    }

    void BFS(int source)
    {
        vector<int> visited(this->V, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for (auto element : listOfConnections[u])
            {
                int v = element.first;
                if (visited[v] != true)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void DFS(int source)
    {
        static vector<int> visited(this->V, false);
        cout << source << " ";
        visited[source] = true;
        for (auto element : listOfConnections[source])
        {
            int v = element.first;
            if (visited[v] != true)
            {
                DFS(v);
            }
        }
    }
};

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    Graph g(vertex);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdges(u, v, w);
    }
    cout << "output of Graph is: " << endl;
    for (int i = 0; i < vertex; i++)
    {
        g.print(i);
        cout << endl;
    }
    cout << "output of BFS is: " << endl;
    g.BFS(0);
    cout << endl;
    cout << "output of DFS is: " << endl;
    g.DFS(0);

    return 0;
}