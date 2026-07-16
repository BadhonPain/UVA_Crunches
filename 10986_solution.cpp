#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int source)
{
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int cost = x.first;
        int u = x.second;

        if (cost > dist[u])
            continue;

        for (auto neighbour : graph[u])
        {
            if (dist[neighbour.first] > cost + neighbour.second)
            {
                dist[neighbour.first] = dist[u] + neighbour.second;
                pq.push({dist[neighbour.first], neighbour.first});
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int n, M, S, T;

    for (int i = 1; i <= N; i++)
    {
        cin >> n >> M >> S >> T;

        graph.clear();
        graph.resize(n);
        dist.assign(n, INF);

        while (M--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        dijkstra(S);
        cout << "Case #" << i << " : ";
        if (dist[T] < INF)
            cout << dist[T] << endl;
        else
            cout << "unreachable" << endl;
    }
}