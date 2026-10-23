#include <bits/stdc++.h>
using namespace std;

// https://usaco.org/index.php?page=viewproblem2&cpid=1132

/*
My idea is to first loop through each member starting in the order from 0 to N-1 cow
then the cow called i will loop through each of the K publications. 

Then we will with that cow loop through all the cows lets call it j in that publication
and for each of those publication we can look at the left half of i and the right half

1. for the left half this is always true in seniority
    j <= i in seniority
    

    1. if i and j are alphebetically ordered and j is first
    then that must mean that j is less in seniority 

    This is because if they are the same seniority then they would sort by alphebetical order
    but it is not in alphebetical order so that can only mean that cow i has higher signora 
    so we output "1"

    2. other wise, we would not be able to tell and we will output "?"



2. for the right half this is always true in seniority
    i <= j in seniority
   
    1. if i and j are alphebetically ordered and i is first
    then that must mean that i is less in seniority because they cant be the same.
    if they are the same then j should be ordered first but it isnt.
    so we output "0"

    2. other wise, we would not be able to tell and we will output "?"
    
we can just do this and output each every time

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