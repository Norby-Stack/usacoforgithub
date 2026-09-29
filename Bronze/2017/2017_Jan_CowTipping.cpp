#include <bits/stdc++.h>
using namespace std;




/*
tipping only 1 singular cow takes 4 steps for a cow that positions are not on the top or left and 2 if they are and 1 if they are both

case with 4:

00
01
->
11
10
->
00
10
->
10
00
->
00

case with 2:

01
00
->
10
00
->
00
00

case with 1:

10
00
->
00
00


we need for every signle cell with a 1 we have to individually change the cells 
but we notice that if we turn a cell an even number of times,
it will not change so we only have to turn cells with an odd number of turns



*/

int main()
{
    int N;
    cin >>  N;

    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
}

    vector<vector<int>> change(N, vector<int>(N, 0));
    
    // loop though the matrix to find the amount of total tippings a from the top left to the current cell needs

    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                change[i][j] += 1;
                if(i > 0) change[i-1][j] += 1;
                if(j > 0) change[i][j-1] += 1;

                if(i > 0 && j > 0) change[i-1][j-1] += 1;
            }
        }
    }
    // PRINT odd amount of changes 
    int changes = 0;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (change[i][j] % 2 == 1){
                changes++;
            }
        }
        
    }
    cout << changes << endl;
}
