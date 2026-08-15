#include <bits/stdc++.h>

using namespace std;

int checkmoo() {}



int main() {
    int N, F;
    cin >> F >> N;
    string file;
    cin >> file;
    // creating hashmap

    unordered_map<string,int> hashmap;
    for (int i = N;i< F-2;i++) {
        string str = file.substr(i, 3);
        if (hashmap.count(str)) {
            hashmap[str] += 1;

        } else {
            hashmap[str] = 1;
        }
    }

    for (auto& [key, val] : hashmap) {
    cout << key << ": " << val << "\n";
}

}