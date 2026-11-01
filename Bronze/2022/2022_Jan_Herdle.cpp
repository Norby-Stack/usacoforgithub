#include <bits/stdc++.h>
using namespace std;

/*
we can first check the amount of green highlighted squares just by checking if 
they are the same for the guess

*/

int main() {
    vector<vector<char>> answer;
    for (int i = 0;i<3;i++) {
        string line;
        cin >> line;
        vector<char> row(line.begin(), line.end());
        answer.push_back(row);
    }

    vector<vector<char>> guess;
    for (int i = 0;i<3;i++) {
        string line;
        cin >> line;
        vector<char> row(line.begin(), line.end());
        guess.push_back(row);
    }


    int green_count = 0;
    int yellow_count = 0;

    set<pair<int,int>> usedgreens;
    set<pair<int,int>> already_greened;
    // checking for greens
    for (int i = 0;i<3;i++) {
        for (int r = 0;r<3;r++) {
            if (guess[i][r] == answer[i][r]) {
                green_count ++;
               
                usedgreens.insert({i,r});
                already_greened.insert({i,r});
                
            }
        }
    }
    
    
    // check for yellows
    for (int i = 0;i<3;i++) {
        for (int r = 0;r<3;r++) {
            if (already_greened.find({i,r}) != already_greened.end()) {
                continue;
            }
            char cur_cow = guess[i][r];
            // checking if others are same
            for (int j = 0;j<3;j++) {
                for (int a = 0;a<3;a++) {
                    if ((i==j) && (r==a)) {
                        continue;
                    }else{
                        if (cur_cow == answer[j][a]){
                            if (usedgreens.find({j,a}) == usedgreens.end()) {
                            yellow_count++;
                            usedgreens.insert({j,a});
                            j = 3;
                            break;
                            }
                        }

                    }
                }
            }
        }
    }
    cout << green_count << endl << yellow_count;


}