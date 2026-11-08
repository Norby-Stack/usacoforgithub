#include <bits/stdc++.h>
using namespace std;


/*
we can first find the different between the two arrays and store it in a new array
then we can find the number of operations needed to make the array all 0s

we can loop through the array and look at that element and the next element
while we create ans = 0

when comparing dif[i] and dif[i+1]
when they are both positive the number of operations we need to get them to 0 is jkust
the greater of the 2

if dif[i] is less than dif[i+1] then we just add ans by dif[i+1] - dif[i]
if dif[i] is greater than dif[i+1] then we dont have to do anything because
the operations from earlier already took care of dif[i+1]

when they are both negative the number of operations we need to get them to 0 is just
the absolute value of the smaller of the 2
then it is the same logic in reverse as the positive case


if dif[i] is positive and dif[i+1] is negative
then we just add ans by the absolute value of dif[i+1] because we dont have to include dif[i]
since we are adding instead of subtracting the temp

same logic applies if dif[i] is negative and dif[i+1] is positive 
we just add ans by  dif[i+1] because we dont have to include dif[i]


*/

int main() {
    int N;
    cin >> N;
    vector<int> dif(N+1);
    vector<int> res(N);
    dif[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> res[i];
    }
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        dif[i+1] = res[i] - n;
    }

  
   
    int ans = 0;
    for (int i = 0; i < N; i++) {
        // this shortens the explanation above but it is the same logic
        ans += max(0, dif[i+1] - max(0, dif[i]))+max(0, -dif[i+1] - max(0, -dif[i]));
    }

    cout << ans << endl;
}