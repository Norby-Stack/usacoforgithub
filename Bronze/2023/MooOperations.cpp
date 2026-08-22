#include <bits/stdc++.h>
using namespace std;

int solve() {
    string cows;
    cin >> cows;
    int N = cows.size();
    int smallest = 6;
    for (int i=1;i<N-1;i++)
    {
        
        if (cows[i] == 'O')
        {
           if (cows[i-1] == 'M' && cows[i+1] == 'O')
           {
               smallest = min(smallest, 0);
           }
           else if (cows[i-1] == 'O' && cows[i+1] == 'M')
           {
               smallest = min(smallest, 2);

           }
           else {
            smallest = min(smallest, 1);
           }
        }

    }
    if (smallest == 6)
    {
        return -1;
    }
    return smallest + N-3;
}


int main() {
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        cout << solve() << endl;
    }
}