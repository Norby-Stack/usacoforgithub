#include <bits/stdc++.h>
using namespace std;

// https://usaco.org/index.php?page=viewproblem2&cpid=761


/*
we can just sort the cows by the day and simulate each day to check if the leader has changed and
increment the total amoumt changed by 1

*/


int main()
{
int N;
cin >> N;
vector<tuple<int, string, int>> cows;
for (int i = 0; i < N; i++) {
    int time;
    string name;
    int change;
    cin >> time >> name >> change;
    cows.push_back({time, name, change});
}

// setting up the 3 cows each strarting at 7
int bessie_milk = 7;
int elsie_milk = 7;
int mildred_milk = 7;
int change_amount = 0;
vector<string> leader = {};
sort(cows.begin(), cows.end());

for (int i = 0; i < N; i++) {
    int time = get<0>(cows[i]);
    string name = get<1>(cows[i]);
    int change = get<2>(cows[i]);


    // finding if they changed 

    if (name == "Bessie") {
        bessie_milk += change;
    } else if (name == "Elsie") {
        elsie_milk += change;
    } else if (name == "Mildred") {
        mildred_milk += change;
    }

    vector<string> current_leaders;
    int max_milk = max({bessie_milk, elsie_milk, mildred_milk});
    if (bessie_milk == max_milk) current_leaders.push_back("Bessie");
    if (elsie_milk == max_milk) current_leaders.push_back("Elsie");
    if (mildred_milk == max_milk) current_leaders.push_back("Mildred"); 

    if (current_leaders != leader) {
        change_amount++;
        leader = current_leaders;
    }

}
cout << change_amount << endl;  
}       