#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    cin >> N;
    // anount of crossing declaration
    int amount_of_crossing = 0;

    // first  is the cow id, the second is  the prev position 

    unordered_map<  int,int> cowscrossedtime;
    for (int i = 0; i < N; i++) {
        int cow_id,position;    
        cin >> cow_id >> position;
        if (cowscrossedtime.find(cow_id) == cowscrossedtime.end() && cowscrossedtime[cow_id] != position) {
            
            cowscrossedtime[cow_id] = position;
            amount_of_crossing++;
        } else {
            cowscrossedtime[cow_id] = position;
        }
       

    }   
    cout << amount_of_crossing << endl;
    
}
