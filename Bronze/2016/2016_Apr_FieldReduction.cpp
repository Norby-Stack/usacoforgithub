#include <bits/stdc++.h>
using namespace std;

// we can find the area of the fence by finding the min and max x and y coordinates of the cows
int get_area(const set<pair<int, int>>& candidates) {
    int min_x = INT_MAX, max_x = INT_MIN;
    int min_y = INT_MAX, max_y = INT_MIN;
    for (auto [x, y]:candidates) {
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    return (max_x - min_x) * (max_y - min_y);
}



int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    /*
     we can see that only removing the cows on the edges of the fence encloser will effect the area of the new fence
     so we can just find the 2 most smallest and 2 largest for the x and y axis so we can try to remove each of the 
     most extreme cows and find the smallest area of the new fence.
    
    */
    
    pair<int, int> x1, x2, x3, x4;
    pair<int, int> y1, y2, y3, y4;

    sort(cows.begin(), cows.end());
    x1 = cows[0];
    x2 = cows[1];
    x3 = cows[N - 2];
    x4 = cows[N - 1];

    sort(cows.begin(), cows.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    y1 = cows[0];
    y2 = cows[1];
    y3 = cows[N - 2];
    y4 = cows[N - 1];
    
    int smallest_area = INT_MAX;

    set<pair<int, int>> candidates = {x1, x2, x3, x4, y1, y2, y3, y4};

    // we first remove y4
    candidates.erase(y4);
    
    smallest_area = min(smallest_area, get_area(candidates));
    candidates.insert(y4);

    // we remove y1
    candidates.erase(y1);
    smallest_area = min(smallest_area, get_area(candidates));
    candidates.insert(y1);

    // we remove x4
    candidates.erase(x4);
    smallest_area = min(smallest_area, get_area(candidates));
    candidates.insert(x4);

    // we remove x1
    candidates.erase(x1);
    smallest_area = min(smallest_area, get_area(candidates));
    candidates.insert(x1);


    
    cout << smallest_area << endl;
}
