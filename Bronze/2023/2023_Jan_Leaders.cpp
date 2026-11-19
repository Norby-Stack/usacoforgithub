#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string cows;
    cin >> N >> cows;

    vector<int> cow_views(N);

    for(int i = 0;i<N;i++) {
        cin >> cow_views[i];
    }

    int H_lead_pos = -1;
    int G_lead_pos = -1;


    // for G cow
    int G_cow_seen = 1;
    int maybe_G = 0;
    for (int i = 0;i<N;i++){
        if (cows[i] == 'G'){
            if (G_cow_seen){
                maybe_G = i;
                i = cow_views[i]-1;   
                G_cow_seen = 0;
            }else{
                break;
            }
            
        }
        if (i == N-1){
            G_lead_pos = maybe_G;
        }
    }
    

    // for H cow
    int H_cow_seen = 1;
    int maybe_H = 0;
    for (int i = 0;i<N;i++){
        if (cows[i] == 'H'){
            if (H_cow_seen){
                maybe_H = i;
                i = cow_views[i]-1;   
                H_cow_seen = 0;
            }else{
                break;
            }
            
        }
        if (i == N-1){
            H_lead_pos = maybe_H;
        }
    }

    int ans=0;
    // looping from left to right now 

    for (int i = 0;i<N;i++){
        if (cows[i] == 'H'){
            if (i==H_lead_pos) continue;
            
            if (i <= G_lead_pos && cow_views[i] >= G_lead_pos + 1){
                ans++;
            }


        }else{
            if (i == G_lead_pos ) continue;

            if (i <= H_lead_pos && cow_views[i] >= H_lead_pos + 1){
                ans++;
            }

        }
    }
    if (G_lead_pos != -1 && H_lead_pos != -1){
        ans ++;
    }

  
    cout << ans;

}