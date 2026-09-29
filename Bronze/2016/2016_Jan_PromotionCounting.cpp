// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> dif;
    for (int i = 0;i<4;i++){
        int a,b;
        cin >> a >> b;
        dif.push_back(b-a);

        
    }
	
    vector<int> acsensions(3,0);
    acsensions[0] += dif[1]+dif[2]+dif[3];
    acsensions[1] += dif[2]+dif[3];
    acsensions[2] += dif[3];

    cout << acsensions[0] << '\n'
     << acsensions[1] << '\n'
     << acsensions[2] << '\n';
}
