#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    vector<pair<long long, long long>> dist;

    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        long long da = (x - x1) * 1LL * (x - x1) + (y - y1) * 1LL * (y - y1);
        long long db = (x - x2) * 1LL * (x - x2) + (y - y2) * 1LL * (y - y2);
        dist.push_back({da, db});
    }

    long long result = LLONG_MAX;
    for (int i = 0; i <= n; ++i) {
        long long r1 = 0;
        for (int j = 0; j < i; ++j) {
            r1 = max(r1, dist[j].first);
        }

        long long r2 = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[j].first > r1) {
                r2 = max(r2, dist[j].second);
            }
        }

        result = min(result, r1 + r2);
    }

    cout << result << endl;
    return 0;
}