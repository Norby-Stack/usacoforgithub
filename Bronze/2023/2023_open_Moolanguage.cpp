#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,C,P;
    vector<string> noun;
    vector<string> conjunction;
    vector<string> transitive;
    vector<string> intransitive;
    for (int i = 0;i <N ;i++) {
        string word;
        string type;
        cin >> word >> type;
        if (type == "noun") {
            noun.push_back(word);
        } else if (type == "transitive-verb") {
            transitive.push_back(word);
        } else if (type == "intransitive-verb") {
            intransitive.push_back(word);
        }
    }
}


int main() 
{
    int N;
    cin >> N;
    for (int i = 0;i<N;i++)
    {
        solve();
    }
}