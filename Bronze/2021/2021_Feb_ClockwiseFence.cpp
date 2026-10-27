// Source: https://usaco.guide/general/io
// https://usaco.org/index.php?page=viewproblem2&cpid=1109

/*
pretty sure all we have to do it count the amount of left and right turns
the fences and if it has more left turns, then the answer is obviously 
counterclockise while more right turns means clockwise.
*/

#include <bits/stdc++.h>
using namespace std;

void sol()
{
    string path;
    cin >> path;

    int left_turns = 0;
    int right_turns = 0;

    char prev_dir = path[0];
    for (int i = 1;i<path.size();i++) {
        if (prev_dir == 'N') {
            if (path[i]=='E')
                right_turns++;
            else if (path[i]=='W')
                left_turns++;
        }else if (prev_dir == 'E') {
            if (path[i]=='S')
                right_turns++;
            else if (path[i]=='N')
                left_turns++;
        }else if (prev_dir == 'S') {
            if (path[i]=='W')
                right_turns++;
            else if (path[i]=='E')
                left_turns++;
        }else if (prev_dir == 'W') {
            if (path[i]=='N')
                right_turns++;
            else if (path[i]=='S')
                left_turns++;
        }
        prev_dir = path[i];
        
    }
    if (left_turns < right_turns) {
        cout << "CW" << endl;
    } else {
        cout << "CCW" << endl;
    }
}

int main() {
	int N;
    cin >> N;
    for (int i = 0;i<N;i++) {
        sol();
    }


}
