#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string num;
        cin >> num;
        if (num.back() == '0') {
            cout << "E" << endl;
        } else {
            cout << "B" << endl;
        }

    }

}