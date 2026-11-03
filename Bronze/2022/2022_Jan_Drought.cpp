#include <bits/stdc++.h>
using namespace std;

/*

we can solve each test case independently

we will check from left to right starting with the zero index and the first index all the way to the 
second to last index and the last index named i and i+1 and the array will be named arr

there are 3 cases for i

1. if arr[i] is less than arr[i+1] 
    we will subract the pair arr[i+1] and arr[i+2] by 1 until arr[i+1] equal to arr[i]
    then we will increment i by 1

2. if arr[i] is greater than arr[i+1]
    we need to check if i+1 is even and if it is
    then we will subract all of the values from 0 to i until they are equal to arr[i+1]
    and then we will increment i by 1
    if it is odd then we cannot make all of 0 to i equal to arr[i+1] so it will be impossible

3. if arr[i] is equal to arr[i+1]
    they are already the same so we will increment i by 1

a

*/

long long sol() {
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> original(N);
    for (int i = 0;i<N;i++) {
        cin >> arr[i];
        original[i] = arr[i];
    }

    for (int i = 0;i<N-1;i++){
        // case 1
        if (arr[i] < arr[i+1]) {
            if (i == N-2){
                
                return -1;
            }
            // we will subtract the pair arr[i+1] and arr[i+2] by 1 until arr[i+1] equal to arr[i]
            arr[i+2] -= (arr[i+1] - arr[i]);
            arr[i+1] = arr[i];
            if (arr[i+1] < 0 || arr[i+2] < 0) {
                
                return -1;
            }
            
        } else if (arr[i] > arr[i+1]){
            // case 2
            if ((i+1) % 2 == 0) {
                // instead of subtracting all of the values from 0 to i until they are equal to arr[i+1]
                // we can just set arr[i] to arr[i+1] and then we will
                arr[i] = arr[i+1];

              
            } else {
                
                return -1;
            }

        } else {
            // case 3
            continue;
        }

    }
    long long ans = 0;
    for (int x : original) ans += x;
    ans -= 1LL * N * arr[N-1];
    return ans;


}

int main() {
    int N;
    cin >> N;
    vector<long long> ans(N);
    for (int i = 0;i<N;i++) {
        ans[i] = sol();
    }
    for (int i = 0;i<N;i++) {
        cout << ans[i] << endl;
    }
}