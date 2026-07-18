#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int test_ = 0;
    while (1)
    {
        int S, C, Q;
        cin >> C >> S >> Q;

        if (C == 0 && S == 0 && Q == 0)
            return 0;

        test_++;
        vector<vector<int>> dist(C + 1, vector<int>(C + 1, INF));

        for (int i = 1; i <= C; i++)
            dist[i][i] = 0;

        for (int i = 0; i < S; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = dist[u][v];
        }

        for (int k = 1; k <= C; k++)
        {
            for (int i = 1; i <= C; i++)
            {
                if (dist[i][k] == INF)
                    continue;
                for (int j = 1; j <= C; j++)
                {
                    if (dist[k][j] == INF)
                        continue;
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }

        if (test_ > 1)
            cout << '\n';

        cout << "Case #" << test_ << endl;

        for (int i = 0; i < Q; i++)
        {
            int a, b;
            cin >> a >> b;

            if (dist[a][b] == INF)
                cout << "no path" << endl;
            else
                cout << dist[a][b] << endl;
        }
    }
}