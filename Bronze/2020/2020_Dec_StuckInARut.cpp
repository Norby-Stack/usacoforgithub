#include <bits/stdc++.h>
using namespace std;

/*
my idea is that we first sort the cows into east and north cows
and then we sort the east cows by their y axis and the north cows by the x axis

we can create a array of size N and each index will keep track of how long that cow will last
we can make them all infinity and we will overwrite them as we keep going


we will sort the 2 lists by the x for the north cows and y for the east cows
in order to know the input order we will create a number that remembers what index it is so 
when we add it to the array we will know where position to add
i will compare starting with the left most north cow on the x axis 
with all the east cows all the way to the right more north cow
we will look through the east cows also with the smallest y first

we can can also ingore the current east cow if its y is less than the starting position of the north cow
because it wont ever interact with the north cow 
we can obviously also ignore all of the cows that have a greater x axis that the north cow
there will be 3 cases with the current east cow and the north cow
    1. it will each the square they will intersect at before the north cow comes and stops it
    this will just end the loop with that north cow and we will move on to the next north cow 
    while writing how long the north cow moved and delete it from the east because we dont need it
    anymore

    2. if the north cow is the one that reaches the intersection point first 
    then we will just go onto the next east cow and the write how long the east cow moved
    and delete it

    3. if they both reach at the exact same time 
    if this is the case then we dont have to do anything because they will keep going




*/







int main() {
    int N;
    cin >> N;

    vector<tuple<int, int, int>> east_cows;
    vector<tuple<int, int, int>> north_cows;

    for (int i = 0;i<N;i++) {
        char dir;
        int x,y;
        cin >> dir >> x >> y;
        if (dir == 'E') {
            east_cows.push_back({x,y,i});
        } else {
            north_cows.push_back({x,y,i});
        }
    }
    // sorting the north and the east cows by x and y;
    sort(north_cows.begin(), north_cows.end());



    sort(east_cows.begin(), east_cows.end(),
     [](const auto& a, const auto& b) {
         return get<1>(a) < get<1>(b);
    });

    // creating the travel vector
    vector<int> traveled(N,-1);

 
    for (int i = 0;i<north_cows.size();i++) {
        for (int r = 0;r<east_cows.size();r++) {
            if (get<0>(east_cows[r]) <= get<0>(north_cows[i]) && get<1>(east_cows[r]) >= get<1>(north_cows[i]))
            {
                int travel_distance_east = get<0>(north_cows[i])-get<0>(east_cows[r]);
                int travel_distance_north = get<1>(east_cows[r])-get<1>(north_cows[i]);
                
                if (travel_distance_east == travel_distance_north) {
                    continue;
                } else if (travel_distance_east<travel_distance_north) {
                    traveled[get<2>(north_cows[i])] = travel_distance_north;
                    north_cows.erase(north_cows.begin() + i);
                    i--;
                    break;
                } else {
                    traveled[get<2>(east_cows[r])] = travel_distance_east;
                    east_cows.erase(east_cows.begin() + r);
                    r--;
                }
            }
        }
    }
    for (int i = 0;i<N;i++) {
        if (traveled[i] == -1) {
            cout << "Infinity" <<endl;
        } else {
            cout << traveled[i]<<endl;
        }
        
        
    }

}