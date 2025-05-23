#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);

    for(int i = 0;i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    
    set<pair<int, int>> possible;
    possible.insert({0, 0});

    for(int i = 0; i < n; i++) {
        int s = cows[i].first;
        int f = cows[i].second;

        vector<pair<int, int>> to_add;

        for (const auto& p : possible) {
            int curr_s = p.first;
            int curr_f = p.second;
            int new_s = curr_s + s;
            int new_f = curr_f + f;
            
            to_add.push_back({new_s, new_f});
        }

        for(const auto& p : to_add) {
            possible.insert(p);
        }
    }

    int sum = 0;
    for (const auto& p : possible) {
        int ts = p.first;
        int tf = p.second;
        if (ts >= 0 && tf >= 0) {
            sum = max(sum, ts + tf);
        }
    }

    cout << sum << endl;

    return 0;
}