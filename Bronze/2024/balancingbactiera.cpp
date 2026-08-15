#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long N;
    cin >> N;
    vector<long long> lawn(N);
    for (int i = 0;i < N;i++) 
    {
        cin >> lawn[i];
    }
    long long fulladditinoall = 0;
    long long additional = 0;
    long long hehe = 0;
    for (long long i = 0;i<N;i++)
    {
        long long num = lawn[i];
        
        
        num += fulladditinoall; 
        additional += -num;
        fulladditinoall += -num;
        fulladditinoall += additional;  

        hehe+= abs(num);    
        
    }
    cout << hehe;
}