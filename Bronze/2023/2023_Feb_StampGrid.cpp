#include <bits/stdc++.h>
using namespace std;

/*
for each test case we will check all the possible arrangements of stamps
and as long as it doesnt interfere with our target we can stamp it
*/

void sol() {
    int N;
    cin >> N;
    
    vector<vector<int>> target(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char c;
            cin >> c;
            target[i][j] = (c == '*');
        }
    }
    int K;
    cin >> K;
    
    vector<vector<int>> stamp(K, vector<int>(K)); 
    for(int i = 0;i<K;i++){
        for(int j = 0;j<K;j++){
            char c;
            cin >> c;
            stamp[i][j] = (c == '*');
        }
    }
    // the 4 rotated stamps
    vector<vector<vector<int>>> stamps(4, vector<vector<int>>(K, vector<int>(K)));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            stamps[0][i][j] = stamp[i][j];
            stamps[1][j][K-1-i] = stamp[i][j];
            stamps[2][K-1-i][K-1-j] = stamp[i][j];
            stamps[3][K-1-j][i] = stamp[i][j];
        }
    }


    vector<vector<int>> blank(N,vector<int>(N,0));
    // the ranges of i and j is N-K+1


    for (int i = 0;i<N-K+1;i++){
        for (int j = 0;j<N-K+1;j++){
            for (int r = 0;r<4;r++){
                int work = 1;
                for(int a = 0;a<K;a++){
                    for(int b = 0;b<K;b++){
                        if (target[i+a][j+b] == 0 && stamps[r][a][b] == 1){
                            work = 0;
                        }
                    }
                }
                if (work){
                    for(int a = 0;a<K;a++){
                    for(int b = 0;b<K;b++){
                        if (stamps[r][a][b] == 1)
                        blank[i+a][j+b] = 1;
                        
                    }
                }
                }
            }
        }
    }
    int iscorrect = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (blank[i][j] != target[i][j]){
                iscorrect = 0;
            }
        }
    }
   if (iscorrect)
    cout << "YES\n";
    else
    cout << "NO\n";

}



int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        sol();
    }
    
}