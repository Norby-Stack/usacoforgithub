#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N, U;
    cin >> N >> U;
    vector<string> cows(N);
    vector<vector<int>> count(N / 2, vector<int>(N / 2, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> cows[i];
        for (int j = 0; j < N; j++)
        {
            if (cows[i][j] == '#')
            {
                count[min(i, N- 1 - i)][min(j, N - 1 - j)]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            ans += min(count[i][j], 4 - count[i][j]);
        }
    }
    cout << ans << '\n';

    for (int i = 0; i < U; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;

        int a = min(r, N - 1 - r);
        int b = min(c, N - 1 - c);
        ans -= min(count[a][b], 4 - count[a][b]);

        if (cows[r][c] == '#')
        {
            cows[r][c] = '.';
            count[a][b]--;
        }
        else
        {
            cows[r][c] = '#';
            count[a][b]++;
        }

        ans += min(count[a][b], 4 - count[a][b]);
        cout << ans << '\n';
    }
}
