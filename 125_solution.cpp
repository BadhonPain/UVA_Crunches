#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m;
    int matrix_no = 0;
    while (cin >> m)
    {
        vector<pair<int, int>> edges;

        int mx = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            mx = max(mx, max(u, v));
        }

        int n = mx + 1;

        vector<vector<int>> paths(n, vector<int>(n, 0));

        vector<vector<bool>>dist(n, vector<bool>(n,false));
        for (auto x : edges)
        {
            paths[x.first][x.second] ++;
             dist[x.first][x.second]=true;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k]&& dist[k][j])
                        paths[i][j]=(paths[i][k]+paths[k][j]);
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (paths[k][k] > 0)
            {

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (paths[i][k] > 0 && paths[k][j] > 0)
                            paths[i][j] = -1;
                    }
                }
            }
        }

        

        cout << "matrix for city " << matrix_no++ << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j)
                    cout << ' ';
                cout << paths[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}