#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
vector<int> price;
string candy;

int solve(int left, int right) {
    // base cases
    if(left >= right) {
        return 0;
    }
    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    //left and right are same
    if(candy[left] == candy[right]) {
        dp[left][right] = solve(left+1, right-1);
    }
    else {
        //choices add to left or add to right
        int priceleft = price[candy[left] - 'a'] + solve(left+1, right);
        int priceright = price[candy[right] - 'a'] + solve(left, right-1);

        dp[left][right] = min(priceleft, priceright);
    }

    return dp[left][right];
}

int main() {
    int n, k;
    cin >> n >> k;
    price.resize(k);
    dp.resize(n, vector<int>(n, -1));
    
    for(int i = 0; i < k; i++) {
        cin >> price[i];
    }

    cin >> candy;

    cout << solve(0, n-1) << endl;

    return 0;
}