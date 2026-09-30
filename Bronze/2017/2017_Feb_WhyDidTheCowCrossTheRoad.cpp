#include <bits/stdc++.h>
using namespace std;


/*we can use map to check the cows previous positions and with that we can check
 if the prev position is different from the current position and 
 if it is we can add 1 to the amount of crossings and update the prev position to the current position

*/
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
        if (cowscrossedtime.find(cow_id) != cowscrossedtime.end() &&cowscrossedtime[cow_id] != position) {
            
            cowscrossedtime[cow_id] = position;
            amount_of_crossing++;
        } else {
            cowscrossedtime[cow_id] = position;
        }
       

    }   
    cout << amount_of_crossing << endl;
    
}
