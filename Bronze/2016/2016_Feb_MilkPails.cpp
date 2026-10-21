#include <bits/stdc++.h>
using namespace std;
// https://usaco.org/index.php?page=viewproblem2&cpid=615
/*
we can just try every single possible number disible by x and then check the y and 
we set the new max every single time we have a new max
*/


int main() 
{   
    // taking in input

    int X, Y, Z;
    cin >> X >> Y >> Z;
    int max_milk = 0;
    //looping through each x and y

    for (int i = 0;i<=Z+X;i+=X){
        for (int j = 0;j<=Z+Y;j+=Y){
            if (i+j <= Z){
                max_milk = max(max_milk, i+j);
            }
        }
    }
    cout << max_milk;
}
