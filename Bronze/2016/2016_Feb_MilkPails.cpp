#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int max_milk = 0;
    for (int i = 0;i<=Z+X;i+=X){
        for (int j = 0;j<=Z+Y;j+=Y){
            if (i+j <= Z){
                max_milk = max(max_milk, i+j);
            }
        }
    }
    cout << max_milk;
}
