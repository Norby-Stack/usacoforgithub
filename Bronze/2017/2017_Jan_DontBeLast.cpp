

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        string a;
        cin >> a;
        cout << a;
        return 1
    }
    map<string, int> cows = {
        
    };

    for (int i = 0; i < N; i++) {
        string a;
        int b;

        cin >> a >> b;
        
        cows[a] += b;
        
        
    }
   
    
    vector<int> values;

    for (auto cow : cows) {
        values.push_back(cow.second);
    }

    sort(values.begin(), values.end());

    values.erase(unique(values.begin(), values.end()), values.end());
    
    if (values.size() == 1) {

        cout << "Tie";
        return 0;
    }
    int secondsmallest = values[1];
    for (auto cow : cows) {
    if (cow.second == secondsmallest)
        cout << cow.first << '\n';
    }


}