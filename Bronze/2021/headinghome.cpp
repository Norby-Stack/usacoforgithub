#include <bits/stdc++.h>
using namespace std;


int dfs(int x,int y,int turnsleft,int dir,int size, char grid[50][50]) {
    cout << x << " " << y << "\n" ;
    if (turnsleft == 0) {
        if (x == size-1) {
            bool nobarriers = true;
            for (int i = y;i < size;i++) {
                if (grid[x][i] == 'H') {
                    nobarriers = false;
                    break;
                }
                
            }
            if (nobarriers) {
                return 1;
            }
        }else if (y == size-1) {
            bool nobarriers = true;
            for (int i = x;i < size;i++) {
                if (grid[i][y] == 'H') {
                    nobarriers = false;
                    break;
                }
            }
            if (nobarriers) {
                return 1;
            }
        } else {
            return 0;

        }

        
    }
    int added = 0;
    if (dir == 'd') {
    int xgo = x;
    
    while (grid[xgo][y] != 'H' && xgo < size) {
        cout << "rnlolx" << xgo << "\n";    
        added += dfs(xgo,y,turnsleft-1,'r',size,grid);
       
        xgo ++;
        
    }
    }
    if (dir == 'r') {
    int ygo = y;
    while (grid[x][ygo] != 'H' && ygo < size) {
        cout << "rnloly" << ygo << "\n";
        added += dfs(x,ygo,turnsleft-1,'l',size,grid);
        
        ygo ++;
    }
    }
    return added;


}

int main() 
{

int n;
cin >> n;
for (int i = 0;i<n;i++) {
    int size;
    int turns;
    cin >> size >> turns;
    char grid[50][50];
    for (int j = 0;j<size;j++) {
        string line;
        cin >> line;
        for (int q = 0;q<size;q++) {
            grid[j][q] = line[q];
        }
    }
    int answer;
    answer += dfs(0,0,turns,'l',size,grid);
    answer += dfs(0,0,turns,'r',size,grid);
    cout << answer;
    
    
}



    

















} 
