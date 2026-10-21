// Source: https://usaco.guide/general/io

// https://usaco.org/index.php?page=viewproblem2&cpid=591

/*
we can calculate acsension for each division by adding the diffence of 
before test and after test of all the previous ones.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> dif;
    // finding difference
    for (int i = 0;i<4;i++){
        int a,b;
        cin >> a >> b;
        dif.push_back(b-a);

        
    }
	
    vector<int> acsensions(3,0);
    // adding it and the previous ones
    acsensions[0] += dif[1]+dif[2]+dif[3];
    acsensions[1] += dif[2]+dif[3];
    acsensions[2] += dif[3];

    cout << acsensions[0] << '\n'
     << acsensions[1] << '\n'
     << acsensions[2] << '\n';
}
