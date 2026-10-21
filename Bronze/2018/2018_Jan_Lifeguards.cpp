#include <bits/stdc++.h>
using namespace std;

/*
we create a array of all the times each with a number for the amount of cows that will be working at that time
then we can go through every cow and subtract its time from the arraw and we can count how many number of times we will lose if we fire 
by checking if it is the only cow for that time. we will then find the minimun and subract the total from the smallest one
*/



int main() 
{
    // taking in input
    int N;
    cin >> N;
    
    vector<pair<int,int>> time_shifts(N);
    for (int i = 0; i<N;i++) {
        cin >> time_shifts[i].first >> time_shifts[i].second;
        
    }

    // this array cahnges 

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