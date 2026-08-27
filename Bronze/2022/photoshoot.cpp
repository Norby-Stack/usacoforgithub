#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    string cows;    
    cin >> N;
    cin >> cows;
    char prev = '.';
    int ans = 0;
    for (int i = 0;i<N-1;i+=2)
    {
        if (cows[i] != cows[i+1])
        {
            if (cows[i] != prev)
            {
                ans++;
                prev = cows[i];
            }
            
        }
    }
    if (prev == 'H'){
        ans--;
    }
    cout << ans << endl;
}