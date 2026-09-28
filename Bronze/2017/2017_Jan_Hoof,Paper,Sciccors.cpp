#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<tuple<int, int>> rounds;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        rounds.push_back({a, b});
    }
}