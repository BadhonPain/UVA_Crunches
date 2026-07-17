#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main()
{
    int n;
    cin >> n;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    string s;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cin >> s;

            if (s != "x")
            {
                int w = stoi(s);
                dist[i][j] = w;
                dist[j][i] = w;
            }
        }
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

    cout << *max_element(dist[1].begin() + 1, dist[1].end()) << endl;

    return 0;
}