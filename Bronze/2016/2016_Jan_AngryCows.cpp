#include <bits/stdc++.h>
using namespace std;

/*
we can see that the hay bails will explode only if it is in the distance of an exploding haybale
so we can sort it and then we can check for each starting haybale and we can simulate the explosions since it is only 100 max
then we output the max

*/



// function for 
void amount_affected(vector<int>&cow_pos,int pos)
{

int total_visited = 1;



//check left

       }
    jump++;
}

// now we check to the right

int checkkright = pos;
jump = 1;

while (checkkright + 1 < cow_pos.size()) {
    int cur_pos = cow_pos[checkkright];
    int previous = checkkright;
    while (checkkright + 1 < cow_pos.size() &&
           cow_pos[checkkright + 1] <= cur_pos + jump) {
        total_visited++;
        checkkright++;
    }
    if (checkkright == previous){
    break;
    }
    jump++;
}

cout << total_visited << '\n';

}

int main() {
    int N;
    cin >> N;

    vector<int> positions(N);
    for (int i = 0;i < N;i++) {
        cin >> positions[i];
    }

    sort(positions.begin(),positions.end());
    for (int i = 0;i<N;i++){
        
        cout << positions[i] << " ";
    }
    cout << endl;
    
    for (int i = 0;i<N;i++){
        
        amount_affected(positions,i);
    }





}
