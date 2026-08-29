#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> homework(N);
    for (int i = 0; i < N; i++)
    {
        cin >> homework[i];
    }

    vector<int> smallest(N);
    smallest[N - 1] = homework[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        smallest[i] = min(smallest[i + 1], homework[i]);
    }

    vector<int> prefixsum(N);
    prefixsum[N - 1] = homework[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        prefixsum[i] = prefixsum[i + 1] + homework[i];
    }
    float largest = 0;
    int work = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        float num = prefixsum[i] - smallest[i];
        if (num / (N - 1 - i) > largest)
        {
            largest = num / (N - 1 - i);
            work = N - i;
        }
    }
}
