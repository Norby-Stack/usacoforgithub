#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    /*
     
    
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
    int max_x = max(candidates.begin()->first, candidates.rbegin()->first);
    int min_x = min(candidates.begin()->first, candidates.rbegin()->first);
    int max_y = max(candidates.begin()->second, candidates.rbegin()->second);
    int min_y = min(candidates.begin()->second, candidates.rbegin()->second);
    smallest_area = min(smallest_area, (max_x - min_x) * (max_y - min_y));
    candidates.insert(y4);

    // we remove y1
    candidates.erase(y1);
    max_x = max(candidates.begin()->first, candidates.rbegin()->first);
    min_x = min(candidates.begin()->first, candidates.rbegin()->first);
    max_y = max(candidates.begin()->second, candidates.rbegin()->second);
    min_y = min(candidates.begin()->second, candidates.rbegin()->second);
    smallest_area = min(smallest_area, (max_x - min_x) * (max_y - min_y));
    candidates.insert(y1);

    // we remove x4
    candidates.erase(x4);
    max_x = max(candidates.begin()->first, candidates.rbegin()->first);
    min_x = min(candidates.begin()->first, candidates.rbegin()->first);
    max_y = max(candidates.begin()->second, candidates.rbegin()->second);
    min_y = min(candidates.begin()->second, candidates.rbegin()->second);
    smallest_area = min(smallest_area, (max_x - min_x) * (max_y - min_y));
    candidates.insert(x4);

    // we remove x1
    candidates.erase(x1);
    max_x = max(candidates.begin()->first, candidates.rbegin()->first);
    min_x = min(candidates.begin()->first, candidates.rbegin()->first);
    max_y = max(candidates.begin()->second, candidates.rbegin()->second);
    min_y = min(candidates.begin()->second, candidates.rbegin()->second);
    smallest_area = min(smallest_area, (max_x - min_x) * (max_y - min_y));
    candidates.insert(x1);


    
    cout << smallest_area << endl;
}
