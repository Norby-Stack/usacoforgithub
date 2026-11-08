#include <bits/stdc++.h>
using namespace std;

/*
there are 4 possible lengths for a word 

1. if the word is 1 character 
then we just check if any of the blocks have that character

2. if the word is 2 characters long
we can simulate all 3*4 = 12 possible cases of 2 order blocks
and then try each of the 6 * 6 = 36 possible combinations of characters

3. 3 and 4 characters long is the same idea

4. if it is more than 4 characters then we output no

*/


string sol(vector<string> &blocks) {
    string word;
    cin >> word;
    if (word.size() == 1){
        for (int i = 0;i<4;i++){
            for (int r = 0;r<6;r++){
                if (blocks[i][r] == word[0]) {
                    return "YES";
                }
            }
        }
        return "NO";
    }else if (word.size() == 2){
        for (int i = 0;i<4;i++){
            for (int r = 0;r<4;r++){
                if (i==r) continue; 
                string block1 = blocks[i];
                string block2 = blocks[r];
                for (int a = 0;a<6;a++){
                    for (int b = 0;b<6;b++){
                        if (block1[a] == word[0] && block2[b] == word[1]) {
                            return "YES";
                        }
                    }
                }
            }
        }
        return "NO";
    }else if (word.size() == 3){
        for (int i = 0;i<4;i++){
            for (int r = 0;r<4;r++){
                for (int j = 0;j<4;j++){
                    if (i==r || r==j ||j==i) continue; 
                    string block1 = blocks[i];
                    string block2 = blocks[r];
                    string block3 = blocks[j];  
                    for (int a = 0;a<6;a++){
                        for (int b = 0;b<6;b++){
                            for (int c = 0;c<6;c++){
                                if (block1[a] == word[0] && block2[b] == word[1] && block3[c] == word[2]) {
                                    return "YES";
                                }
                            }
                        }
                    }
                }
            }
        }
        return "NO";
    }else if (word.size() == 4){
        for (int i = 0;i<4;i++){
            for (int r = 0;r<4;r++){
                for (int j = 0;j<4;j++){
                    for (int u = 0;u<4;u++){
                        if (i==r || r==j ||j==i||i==u||r==u||j==u) continue; 
                        string block1 = blocks[i];
                        string block2 = blocks[r];
                        string block3 = blocks[j];
                        string block4 = blocks[u];
                        for (int a = 0;a<6;a++){
                            for (int b = 0;b<6;b++){
                                for (int c = 0;c<6;c++){
                                    for (int d = 0;d<6;d++){
                                        if (block1[a] == word[0] && block2[b] == word[1] && block3[c] == word[2] && block4[d] == word[3]) {
                                            return "YES";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return "NO";
    }else{
        return "NO";
    }




}


int main()
{
    int N;
    cin >> N;
    vector<string> blocks(4);
    for (int i = 0;i<4;i++) {
        cin >> blocks[i];
    }
    
    vector<string> ans;
    for (int i = 0;i<N;i++){
        ans.push_back(sol(blocks));
    }
    for (int i = 0;i<N;i++){
        cout << ans[i]<<endl;
    }
}
