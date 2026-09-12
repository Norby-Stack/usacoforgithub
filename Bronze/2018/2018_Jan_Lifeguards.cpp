#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    
    vector<pair<int,int>> time_shifts(N);
    for (int i = 0; i<N;i++) {
        cin >> time_shifts[i].first >> time_shifts[i].second;
        
    }
    int addminus[1001] = {0};

    for (int i = 0; i < N; i++) {
    addminus[time_shifts[i].first] += 1;
    addminus[time_shifts[i].second] -= 1;
    }
    
    int allcowsthing[1001] = {0};
    int setting = 0;

    int amountoftimeworking = 0;

    for (int i = 0; i <= 1000; i++) {
        int x = addminus[i];
        setting += x;
        allcowsthing[i] = setting;
        if (setting>0) 
            amountoftimeworking += 1;

    }
    
    
    int smallest = 1000000;

    for (int i = 0;i<N;i++) {
        
        int start = time_shifts[i].first;
        int end = time_shifts[i].second;
        
        int amountlost = 0;

        for (int point = start;point < end;point++){
            if (allcowsthing[point] == 1) 
                amountlost += 1;
            


            
        }
        
        smallest = min(smallest,amountlost);

    }
    cout << amountoftimeworking-smallest;
    
}