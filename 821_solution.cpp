#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N_MAX = 100;
const int M_MAX = 100 * 99 / 2;

const ll INF = 1e18;

int main()
{

    int n = N_MAX;
    int m = M_MAX;

    while (1)
    {
        vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
        vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

        for (int i = 1; i <= n; i++)
        {
            dist[i][i] = 0;
            next[i][i] = i;
        }

        int zero_count = 0;

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            ll w;
            cin >> u >> v >> w;

            if (u == 0 && v == 0 && zero_count)
                break;
            // For handling multi graph
            dist[u][v] = min(dist[u][v], w);
            zero_count++;
        }

        // Floyd-Warshall Algo
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dist[i][k] == INF)
                    continue;

                for (int j = 1; j <= n; j++)
                {
                    if (dist[k][j] == INF)
                        continue;

                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }



    return 0;
}