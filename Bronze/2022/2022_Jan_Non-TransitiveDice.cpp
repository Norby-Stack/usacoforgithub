#include <bits/stdc++.h>
using namespace std;

/*
we first need to calculate how a dice is better than the other
we can find the winner by finding looping through each side and checking
how many of the other dice's sides it can beat and then adding it up 
then we compare the two totals and see which one is bigger

there are 3 cases

1. dice 1 beats dice 2
    if this is the case then dice 3 has to beat dice 1 but lose to dice 2
    in order for it to be non transitive

2. dice 2 beats dice 1
    if this is the case then dice 3 has to beat dice 2 but lose to dice 1
    in order for it to be non transitive

3. dice 1 and dice 2 are equal
    if this is the case then they cannot be non transitive


*/

int winner(vector<int>& dice1, vector<int>& dice2) {
    int score1 = 0, score2 = 0;
    for (int side1 : dice1) {
        for (int side2 : dice2) {
            if (side1 > side2) {
                score1++;
            } else if (side2 > side1) {
                score2++;
            }
        }
    }
    if (score1 > score2) {
        return 1;
    } else if (score2 > score1) {
        return 2;
    } else {
        return 0;
    }
}

string solution() {
        vector<int> dice1(4), dice2(4);
        for (int i = 0; i < 4; i++) {
            cin >> dice1[i];
        }
        for (int i = 0; i < 4; i++) {
            cin >> dice2[i];
        }

    int result = winner(dice1, dice2);
    // if dice 1 beats dice 2, then we need to check if dice 3 can beat dice 1 but lose to dice 2
    vector<int> dice3(4);
    if (result == 1) {
        // simulate all posibble dice 3s and check if any of them can beat dice 1 but lose to dice 2
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                for (int k = 1; k <= 10; k++) {
                    for (int l = 1; l <= 10; l++) {
                        dice3 = {i, j, k, l};
                        if (winner(dice3, dice1) == 1 && winner(dice3, dice2) == 2) {
                            return "yes";
                        }
                    }
                }
            }
        }
        return "no";

    }else if (result == 2) {
        // simulate all posibble dice 3s and check if any of them can beat dice 2 but lose to dice 1
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                for (int k = 1; k <= 10; k++) {
                    for (int l = 1; l <= 10; l++) {
                        dice3 = {i, j, k, l};
                        if (winner(dice3, dice2) == 1 && winner(dice3, dice1) == 2) {
                            return "yes";
                        }
                    }
                }
            }
        }
        return "no";
    } else {
        return "no";
    }
    

}

int main() {
    int T;
    cin >> T;

    vector<string> results;

    for (int i = 0; i < T; i++) {
        results.push_back(solution());
    }

    for (string result : results) {
        cout << result << '\n';
    }
}