#include <iostream>
#include <vector>
using namespace std;



long long SumIncreasingSequence(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, long long>> dp;

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), make_pair(arr[i], 0LL)) - dp.begin() - 1;
        long long currsum = arr[i];
        
        if(pos >= 0) {
            currsum += dp[pos].second;
        }

        pos = lower_bound(dp.begin(), dp.end(), make_pair(arr[i], currsum)) - dp.begin();

        if(pos == dp.size()) {
            dp.push_back(make_pair(arr[i], currsum));
        } else if(dp[pos].first == arr[i]) {
            dp[pos].second = max(dp[pos].second, currsum);
        } else {
            dp.insert(dp.begin() + pos, make_pair(arr[i], currsum));
        }

        for(int j = pos + 1; j < dp.size();) {
            if(dp[j].second <= currsum) {
                dp.erase(dp.begin() + j);
            } else {
                j++;
            }
        }
    }

    long long sum = 0;
    for(int i = 0; i < dp.size(); i++) {
        sum = max(sum, dp[i].second);
    }

    return sum;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << SumIncreasingSequence(arr) << endl;

    return 0;
}