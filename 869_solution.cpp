#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;

        vector<vector<bool>> reach1(26, vector<bool>(26, false));
        vector<vector<bool>> reach2(26, vector<bool>(26, false));

        // First airline
        for (int i = 0; i < n; i++)
        {
            char from, to;
            cin >> from >> to;

            int u = from - 'A';
            int v = to - 'A';

            reach1[u][v] = true;
        }

        // Second airline
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            char from, to;
            cin >> from >> to;

            int u = from - 'A';
            int v = to - 'A';

            reach2[u][v] = true;
        }

        for (int i = 0; i < 26; i++)
        {
            reach1[i][i] = true;
            reach2[i][i] = true;
        }

        // Warshall for first graph
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    reach1[i][j] = reach1[i][j] || (reach1[i][k] && reach1[k][j]);
                }
            }
        }

        // Warshall for second graph
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    reach2[i][j] = reach2[i][j] || (reach2[i][k] && reach2[k][j]);
                }
            }
        }

        bool isEquivalent = true;

        for (int i = 0; i < 26 && isEquivalent; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (reach1[i][j] != reach2[i][j])
                {
                    isEquivalent = false;
                    break;
                }
            }
        }

        if (isEquivalent)
            cout << "YES\n";
        else
            cout << "NO\n";

        if (test)
            cout << endl;
    }

    return 0;
}