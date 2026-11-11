#include <bits/stdc++.h>
using namespace std;

/*



We will try all possible of the 2^10 combinations to buy the air conditioners

we had an array that is length 10 and 1 is for we buy that air conditioner and 0 for we not

ans = the smallest money we have to pay



*/


int main() {
    int N, K;
    cin >> N >> K;

    vector<int> cows_min(101);

    for (int i = 0;i<N;i++){
        int a,b,c;
        cin >> a >> b >>c;
        for (int r = a;r<=b;r++){
            cows_min[r]+= c;
        }
    }

    vector<array<int, 4>> airconditioners(K);

    for(int i = 0;i<K;i++){
        cin >> airconditioners[i][0] >> airconditioners[i][1] >> airconditioners[i][2] >> airconditioners[i][3];
    }



    int amount = 0;
    vector<int> boughtstalls(K,0);
    vector<int> stallscooled(101);


    int ans = INT_MAX;

    while (amount != pow(2,K)){
        int cost = 0;
        for (int i = 0;i<K;i++){
            if (boughtstalls[i] == 1){
                for (int r = airconditioners[i][0];r<=airconditioners[i][1];r++){
                    stallscooled[r]+= airconditioners[i][2];
                }
                cost += airconditioners[i][3];
            }
            
        }
        int cows_all_cooled = 1;
        for (int i = 0;i<=100;i++)
        {
            if (stallscooled[i]<cows_min[i]){
                cows_all_cooled = 0;
                break;
            }
        }
        if (cows_all_cooled)
            ans = min(ans, cost);

        amount++;
        fill(stallscooled.begin(), stallscooled.end(), 0);
        for (int i = 0;i<K;i++){
            if (boughtstalls[i] == 0){
                boughtstalls[i] = 1;
                break;
            }
            else{
                boughtstalls[i] = 0;
            }
        }
    }
    cout << ans;
}