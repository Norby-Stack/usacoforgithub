#include <bits/stdc++.h>
using namespace std;


/*
we can brute force this by trying every starting position from 1 to N and then we can simulate the rest of the
permutation and check if it is valid. 
If it is valid we can print it and since it will be the smallest we can break out of the loop.
*/


int main()
{

    // read in the input
    int N;
    cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N-1; i++){
        cin >> cows[i];
    }

    //setting variables
    set<int> appeared;
    vector<int> permutation(N);

    int starting_num = 1;

    bool work = true;

    while (true) {

        //setting first number and checking if it is valid
        work = true;
        permutation[0] = starting_num;
        appeared.insert(starting_num);

        //simulating
        for (int i = 1;i< N;i++) {
            permutation[i] = cows[i-1] - permutation[i-1];
            if (appeared.count(permutation[i]) || permutation[i] <= 0 || permutation[i] > N) {
                work = false;
                break;
            }
            appeared.insert(permutation[i]);
        }

        
        // checking if the perm is valid
        if (work) {
            for (int i = 0; i < N; i++) {
                cout << permutation[i] << " ";
            }
            cout << endl;
            break;
        }
        else {
            starting_num++;
            appeared.clear();
        }
        
    }


}
