#include <bits/stdc++.h>
using namespace std;

/*
we have a function 

*/
int ans = 0;

int metal_work(int material,vector<int>& materials_list, map<int,vector<int>>& recipes)
{

    if (!recipes.count(material)) {
    return 0;
    }
  
    for (int i = 0; i < recipes[material].size(); i++){
        int cur_material = recipes[material][i];
        if (materials_list[cur_material] == 0){

            if (!metal_work(cur_material, materials_list, recipes)){
                return 0;
            }
        }
        materials_list[cur_material]--;
    }
  
    
    materials_list[material]++;
    return 1;


}


int main() {
    int N;
    cin >> N;
    vector<int> materials_list(N+1);
    for(int i = 1;i<=N;i++){
        cin >> materials_list[i];
    }
    int K;
    cin >> K;
    map<int,vector<int>> recipes;
    for (int i = 0; i < K; i++) {
        int L, M;
        cin >> L >> M;
        vector<int> ingredients(M);
        for (int r = 0;r<M;r++){
            cin >> ingredients[r];
        }
        recipes[L] = ingredients;
    }
    ans = materials_list[N];

    while (true) {
        vector<int> backup = materials_list;

        if (!metal_work(N, materials_list, recipes)) {
            materials_list = backup;
            break;
        }

        ans++;
    }
    cout << ans << endl;


    


}