        #include <bits/stdc++.h>
        using namespace std;

        int main()
        {
            int N;
            cin >> N;
            pair<int, int> cows[N];
            for (int i = 0; i < N; i++) {
                cin >> cows[i].first >> cows[i].second;
            }
            vector<tuple<int, bool, int>> cowshifts;
            for (int i = 0; i < N; i++) {
                cowshifts.push_back({cows[i].first, true, i});
                cowshifts.push_back({cows[i].second, false, i});

            }
            vector<int> each_cow_single_time(N, 0);
            set<int> cur_active_cows;

            int last = 0;
            int current_time = 0;
            int total_time = 0;
            for (int i = 0; i < cowshifts.size(); i++) {


                auto cowpoint = cowshifts[i];

                int current_time = get<0>(cowpoint);

                if (cur_active_cows.size() > 0) {
                    if (cur_active_cows.size() == 1) {
                        total_time += current_time - last;
                    }
                }   


                if (cur_active_cows.size() == 1) {
                    each_cow_single_time[get<2>(cowpoint)] += current_time - last;
                }

                if (get<1>(cowpoint)) {
                    cur_active_cows.insert(get<2>(cowpoint))
                }else{
                    cur_active_cows.remove(get<2>(cowpoint))
                }

                last = current_time;
            }
            cout << total_time << endl;
        }