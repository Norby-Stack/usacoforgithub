#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l;
    cin >> l;
    vector<int> lst(l);
    for (int i = 0; i < l; i++) cin >> lst[i];

    long long sumlst = 0;
    for (int x : lst) sumlst += x;

    if (sumlst == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> factors;
    for (long long i = 1; i * i <= sumlst; i++) {
        if (sumlst % i == 0) {
            factors.push_back(i);
            if (i != sumlst / i)
                factors.push_back(sumlst / i);
        }
    }
    sort(factors.begin(), factors.end());

    for (long long factor : factors) {
        long long running = 0;
        int merges = 0;
        bool work = true;

        for (int j = 0; j < l; j++) {
            running += lst[j];
            if (running == factor) {
                running = 0;
            } else if (running > factor) {
                work = false;
                break;
            } else {
                merges++;
            }
        }

        if (work) {
            cout << merges << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) solve();

    return 0;
}