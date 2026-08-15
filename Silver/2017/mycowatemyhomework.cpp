#include <bits/stdc++.h>
using namespace std;




int main() 
{
    int N;
    cin >> N;
    vector<int> homework(N);
    for (int i = 0;i++;i<N) {
        cin >> homework[i];
    }

    vector<int> smallest(N);
    smallest[N-1] = homework[N-1];
    for (int i = N-2;i--;i>=0) {
        smallest[i] = min(smallest[i+1],homework[i]);
    }

    vector<int> prefixsum(N);
    prefixsum[0] = homework[0];
    for (int i = 1;i++;i<N) {
        prefixsum[i] = prefixsum[i-1] + homework[i];
    }
}
