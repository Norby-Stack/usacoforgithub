#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N,M;
    cin >> N >> M;
    string directions;
    cin >> directions;
    vector<int> milk(N);
    for (int i = 0;i<N;i++) {
        int bucket;
        cin >> bucket;
        milk[i] = bucket;
    }

    vector<int> change(N,0);
    for (int i = 1;i<N-1;i++) {
        if (directions[i] == 'R')
        {
            change[i+1] += 1;
            change[i] -= 1;
        } else {
            change[i-1] += 1;
            change[i] -= 1;
        }
    }
    if (directions[0] == 'R') {
        change[1] += 1;
        change[0] -= 1;
    } else if (directions[0] == 'L'){
        change[N-1] += 1;
        change[0] -= 1;
    } else if (directions[N-1] == 'L'){
        change[N-2] += 1;
        change[N-1] -= 1;
    } else if (directions[N-1] == 'R'){
        change[0] += 1;
        change[N-1] -= 1;
    }

    for (int i = 0;i<N;i++) {
        milk[i] += min(milk[i],max(0,change[i]*M));
    }
    int sum = 0;
    for (int i = 0;i<N;i++) {
        sum += milk[i];
    }
    cout << sum;
}