#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N-1; i++){
        cin >> cows[i];
    }


    set<int> appeared;
    vector<int> permutation(N);


    int starting_num = 1;
    bool work = true;
    while (true) {

        work = true;
        permutation[0] = starting_num;
        appeared.insert(starting_num);
        for (int i = 1;i< N;i++) {
            permutation[i] = cows[i-1] - permutation[i-1];
            if (appeared.count(permutation[i]) || permutation[i] <= 0 || permutation[i] > N) {
                work = false;
                break;
            }
            appeared.insert(permutation[i]);
        }

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
