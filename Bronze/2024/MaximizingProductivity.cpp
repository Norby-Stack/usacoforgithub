#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N,Q;
    cin >> N >> Q;
    vector<int> c(N);
    for (int i = 0;i<N;i++) {
        cin >> c[i];
    }
    vector<int> t(N);
    for (int i = 0;i<N;i++) {
        cin >> t[i];
    }
    
    vector<int> difference(N);
    for (int i = 0;i<N;i++) {
        difference[i] = c[i] - t[i];
    }

    sort(difference.rbegin(), difference.rend());
    
    vector<int> amount(1000000, 0);
    
    int start = 0;
    
    int hehe = 0;
    for (int i = 999999;i>=0;i--) {
        if (difference[start] < 0) {
            break;
        }
        if (difference[start]==i) {
            cout << "i: " << i << endl;
            hehe ++;
            start++;
        }
        amount[i] = hehe;
    

    }
    for (int i = 0;i<10;i++){
        cout << amount[i] << endl;
    }
    for (int i = 0;i<Q;i++) {
        int a,b;
        cin >> a >> b;
        if (amount[b-1] >= a) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}