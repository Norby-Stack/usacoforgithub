#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    vector<pair<int,int>> line(N);
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        line[i] = {a,b};

    }
    unordered_set<int> visited;
    set<tuple<int,int,int>> thinglol;
    int direction = 1;
    int power = 1;
    int position = S-1;
    int bob = 0; 
    while (true)

    {
        if (0 > position || position >= N || thinglol.count({position,direction,power})) {
            break;
        }
    

        if (line[position].first == 1) 
        {
            if (power >= line[position].second) {
                if (!thinglol.count({position,direction,power})) {
                    thinglol.insert({position,direction,power});
                    
                }
                if (!visited.count(position)) {
                    visited.insert(position);
                    bob ++;
                }
            }
            
        } else

        {
            direction *= -1;
            power += line[position].second;
        }
        position += direction*power;
       
    }
    cout << bob << endl;
}


    