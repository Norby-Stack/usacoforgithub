#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int N, Q, C;
    cin >> N >> Q >> C;
    vector<int> cows(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cows[i];
    }
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b};
    }
    sort(queries.begin(), queries.end(), [](auto a, auto b)
         { return a.second < b.second; });
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}