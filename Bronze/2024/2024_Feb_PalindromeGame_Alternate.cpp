#include <bits/stdc++.h>
using namespace std;

main() {

    int N;
    cin >> N;
    for (int i = 0;i <N;i++) {
        string number;
        cin >> number;
        if (number[number.size()-1] == '0') {
            cout << "E"<< "\n";
        } else {
            cout << "B" << "\n";
        }
    }
}