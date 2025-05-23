#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
vector<vector<int>> h;
vector<vector<int>> dp;
int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int dfs(int i, int j) {
    //base cases
    if(dp[i][j] != 0) {
        return dp[i][j];
    }
    dp[i][j] = 1;
    
    for(int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];

        if(ni >= 0 && ni < r && nj >= 0 && nj < c && h[ni][nj] < h[i][j]) {
            dp[i][j] = max(dp[i][j], 1+dfs(ni, nj));
        }
    }
    
    return dp[i][j];
}

int main() {
    cin >> r >> c;
    h.resize(r, vector<int>(c));
    dp.resize(r, vector<int>(c, 0));
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> h[i][j];
        }
    }

    int maxpath = 0;
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            maxpath = max(maxpath, dfs(i, j));
        }
    }
    
    cout << maxpath << endl;

    return 0;
}