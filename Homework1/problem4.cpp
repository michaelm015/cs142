#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    set<pair<int, pair<int, int>>> two_dart_combos;

    for (int i = 0; i < n; i++) {
        two_dart_combos.insert({scores[i], {i + 1, 0}});
        for (int j = i; j < n; j++) {
            int sum = scores[i] + scores[j];
            if (sum <= m) {
                two_dart_combos.insert({sum, {i + 1, j + 1}});
            }
        }
    }

    vector<pair<int, pair<int, int>>> sorted_combos(two_dart_combos.begin(), two_dart_combos.end());
    sort(sorted_combos.rbegin(), sorted_combos.rend());

    vector<int> result;
    int best_total = -1;

    for (int i = 0; i < sorted_combos.size(); i++) {
        for (int j = i; j < sorted_combos.size(); j++) {
            int total_score = sorted_combos[i].first + sorted_combos[j].first;

            if (total_score <= m) {
                if (total_score > best_total) {
                    best_total = total_score;
                    result = {
                        sorted_combos[i].second.first, // First dart from the first pair
                        sorted_combos[i].second.second, // Second dart from the first pair
                        sorted_combos[j].second.first, // First dart from the second pair
                        sorted_combos[j].second.second  // Second dart from the second pair
                    };
                }

                if (total_score == m) {
                    break;
                }
            }
        }

        if (best_total == m) {
            break;
        }
    }

    if (result.empty()) {
        result = {0, 0, 0, 0};
    }

    for (int i = 0; i < 4; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
