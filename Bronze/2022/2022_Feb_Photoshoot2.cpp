#include <bits/stdc++.h>
using namespace std;

/*
we first rearrange the desired order to be 1 to N and then we will change 
the order of the orginal array to the new numbers

3 2 4 1
4 3 1 2

it will be

2 4 1 3
1 2 3 4


after this we will start from the left and add it to a list
if it is not the biggest number in the list then we know we must
move it to the left so we add 1 to ans

*/

int main()
{
    int N;
    cin >> N;
    vector<int> org(N);
    for (int i = 0; i < N; i++)
    {
        cin >> org[i];
    }
    vector<int> des(N);
    for (int i = 0; i < N; i++)
    {
        cin >> des[i];
    }

    // this will know what number will be which position in the desired order
    vector<int> swap(N);
    for (int i = 0; i < N; i++)
    {
        swap[des[i] - 1] = i;
        des[i] = i + 1;
    }

    for (int i = 0;i<N;i++){
        org[i]= swap[org[i]-1];
    }
    
    // now we have the new positions
    int max_num = -1;
    int ans = 0;
    for (int i = 0;i<N;i++){
        if (org[i] > max_num){
            max_num = org[i];
        }else{
            ans++;
        }
    }
    cout << ans << endl;
}
