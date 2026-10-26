// https://usaco.org/index.php?page=viewproblem2&cpid=963

// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

/*
we can just loop through all the pairs for 2 cows order mattering
then loop through the total sessions for each of the pairs 
and check if the first cow is always better than the other
*/


int main() {
	int K,N;
    cin >> K >> N;

    vector<vector<int>> cows;
    
    for (int i = 0;i<K;i++) {
        vector<int> line(N);
        for (int r = 0;r<N;r++){
            cin >> line[r];

        }
        cows.push_back(line);
      
    }
    

    int total_pairs = 0;
    for (int i = 1;i<=N;i++) {
        for (int r = 1;r<=N;r++) {
            if (i == r)
                continue;
            int work = 1;
            for (int j = 0;j<K;j++) {
                if ((find(cows[j].begin(), cows[j].end(), i) - cows[j].begin())>(find(cows[j].begin(), cows[j].end(), r) - cows[j].begin()))
                {
                    work = 0;
                    break;
                }
            }
            if (work==1)
            {
                
                total_pairs++;
            }
        }
    }
    cout << total_pairs;
}
