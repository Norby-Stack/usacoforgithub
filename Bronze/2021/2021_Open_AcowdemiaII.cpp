#include <bits/stdc++.h>
using namespace std;

// https://usaco.org/index.php?page=viewproblem2&cpid=1132

/*
My idea is to first loop through each member starting in the order from 0 to N-1 cow
then the cow called i will loop through each of the K publications. 

Then we will with that cow loop through all the cows lets call it j in that publication
and we can loop through all pairs of i and j

we cam find the positions for the 2 cows and if we can confirm that the smaller one is not equal to the larger one
then we will know if it is lower ranked or higher ranked than j depending on if i is the smaller or the larger of the 2
we can check if they did not contribute the same by looking at the names and as long as one of the names is sorted from the right
then we know that it that i and j are not the same and output the answqer


*/




int main() 
{

    int K,N;
    cin >> K >> N;

    vector<string> coworder(N);

    vector<vector<string>> cow_publications;

    for (int i = 0;i<N;i++) {
        cin >> coworder[i];
    }

    for (int i = 0;i < K;i++) {
        vector<string> cur_publication(N);
        for (int i = 0;i<N;i++) 
        {
            cin >> cur_publication[i];
        }
        cow_publications.push_back(cur_publication);
    }
    vector<vector<char>> output(N, vector<char>(N, '?'));


    // looping through cows
    for (int i = 0;i<N;i++) {
        string cow_i = coworder[i];
        // each publication
        for (int x = 0;x < K;x++) {
            for (int j = 0;j < N; j++)
            {
                if (i == j) {
                    output[i][j] = 'B';
                    continue;
                }

                vector<string>& publication = cow_publications[x];

                // find each cows position in this publication.
                int pos_i = find(publication.begin(), publication.end(), coworder[i])- publication.begin();
                int pos_j = find(publication.begin(), publication.end(), coworder[j])- publication.begin();

                // finding which one comes first
                int left = min(pos_i, pos_j);
                int right = max(pos_i, pos_j);

                // Check every neighboring pair between those positions.
                for (int p = left; p < right; p++) {
                    if (publication[p] > publication[p + 1]) {
                        
                        if (pos_i < pos_j) {
                            output[i][j] = '0'; //cow i is more junior
                        } else {
                            output[i][j] = '1'; // Cow i is more senior
                        }

                        break;
                    }
                }
                
            }
            
        }
    }
    for (int i = 0;i<N;i++) {
        for (int r = 0;r<N;r++) {
            cout << output[i][r];
        }
        cout << endl;
    }



}