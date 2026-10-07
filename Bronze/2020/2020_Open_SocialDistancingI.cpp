#include <bits/stdc++.h>
using namespace std;

/*
there are 2 cases

1. we can fit 2 stalls inside the largest distance between 2 stalls

2. we can fit 1 stall in each of the largest and second largest distance between 2 stalls

we need to consider the sides of the string so we can do like 00001 we can do x0x01 which is 
the length /2 instead of /3

and for 1 we can do 0001000 x00100x so it is just length


*/




int main()
{
    int N;
    string stalls;
    cin >> N;
    cin >> stalls;
    int first_largest = 0;
    int second_largest=0;
    int original_smallest_distance = INT_MAX;


    //check if there are any stalls at all
    if (stalls.find('1') == string::npos) {
        cout << N - 1 << endl;
        return 0;
    }


    // get position of first stall
    int last_pos = 0;
    for (int i = 0; i < N;i++) {
        if (stalls[i] =='1') {
            last_pos = i;
            break;
        }
    }
    int left = last_pos;
  

    // calculate the original smallest distance between 2 stalls 
    int pos = last_pos;

    for (int i = last_pos + 1; i < N; i++) {
        if (stalls[i] == '1') {
            original_smallest_distance =
                min(original_smallest_distance, i - pos);

            pos = i;
        }
    }

    // now we can find the largest and second largest distance between 2 stalls

    for (int i = last_pos+1; i < N;i++) {
        if (stalls[i] == '1') {
            if (i - last_pos > first_largest) {
                second_largest = first_largest;
                first_largest = i - last_pos;
            }
            else if (i - last_pos > second_largest) {
                second_largest = i - last_pos;
            }

            last_pos = i;
            
        }
    }

    int right = N - 1 - last_pos;

    //check if we can fit 2 stalls inside the largest distnace or on the left and right side
    int smallest_distance1 = max({first_largest / 3, left / 2, right / 2});

    //now we fit 1 stall in each including the left and right and we can find the second laregest min distance
    vector<int> choices = {first_largest / 2,second_largest / 2,left,right};
    sort(choices.rbegin(), choices.rend());

    int smallest_distance2 = choices[1];


    int smallest_distance = min(original_smallest_distance,max(smallest_distance1, smallest_distance2));


    // cout <<smallest_distance1 << endl << smallest_distance2 << endl;
    // cout << original_smallest_distance << endl;
    cout << smallest_distance << endl;
}