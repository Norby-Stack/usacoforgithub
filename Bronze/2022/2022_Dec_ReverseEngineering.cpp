#include <bits/stdc++.h>
using namespace std;

/*
when using the if and if else statements,we only look at a column

for each column we will look at the 1 and 0 and if our sequence of if /else if/else are true
then we if statements cannot contridict so all of the 1s in that column have the same output
or if all the 0s have the same output.
if they both satisfy the condition then the we just use 2 ifs in the same column which would make the sequence a valid one

if an if statement works then those rows are already done so then they end early so we dont have to look at them

at the end if there are any left overs then they need to be all have the same output for the sequence to be valid

we will just loop from left to right and if we we remove at least 1 row then we start from begining because 
it could have made another if statement earlier possible

*/


void sol(){
    int N,M;
    cin >> N >> M;
    vector<int> outputs(M);
    vector<string> arrays(M);

    for (int i = 0;i<M;i++){
        cin >> arrays[i] >> outputs[i];
    }
    vector<int> removed(M,0);
    int i = 0;
    while (1){
        int work_1_1 = 1;
        int work_1_0 = 1;
        int work_0_1 = 1;
        int work_0_0 = 1;
        for (int r = 0;r <M;r++){
            if (removed[r] == 0){
                if (arrays[r][i] == '1'){
                    if (outputs[r] != 1){
                        work_1_1 = 0;
                    } else{
                        work_1_0 = 0;
                    }
                }else{
                    if (outputs[r] != 1){
                        work_0_1 = 0;
                    } else{
                        work_0_0 = 0;
                    }
                }
            }
        }
        
        int changed = 0;

        for (int r = 0;r<M;r++){

            if (removed[r])
            continue;
            
            int we_remove = 0;

            if (work_1_1 || work_1_0){
                if (arrays[r][i] == '1'){
                    we_remove = 1;
                }
            }else if (work_0_1 || work_0_0){
                if (arrays[r][i] == '0'){
                    we_remove = 1;
                }
            }
            if (we_remove) {
                changed = 1;
                removed[r] = 1;
            }
        }
        if (changed) 
            i = 0;
        else 
            i++;

       
        if (i == N){
            int work = 1;
            for (int r = 0;r <M;r++){
                if (!removed[r] && outputs[r] == 0){
                    work = 0;
                    break;
                }
            }
            if (work) {
                cout << "OK" << endl;
                return;
            }
            
            work = 1;
            for (int r = 0;r <M;r++){
                if (!removed[r] && outputs[r] == 1){
                    work = 0;
                    break;
                }
            }
            if (work) {
                cout << "OK" << endl;
                return;
            }
            cout << "LIE" << endl;
            return;
            
        }
    }

}



int main(){

    int T;
    cin >> T;

    for (int i = 0;i<T;i++){
        sol();
    }


}