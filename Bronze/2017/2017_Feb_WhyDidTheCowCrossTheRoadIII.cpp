// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

/*
we can sort the cows by their start time and check if when it ends it is before the next cow starts
but if it is not we will make just make the start time for the next cow the end time of the previous cow 
and add the duration of the next cow to it
*/


int main() {
	int N;
    cin >> N;
    vector<pair<int,int>> cows(N);
    for (int i = 0; i <N;i++) 
    {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(),cows.end());

    int end = -1;

    for (int i = 0;i<N;i++) {
        if (cows[i].first < end)
            end += cows[i].second;
        else
            end = cows[i].first + cows[i].second;
    }
    cout << end << endl;

}
