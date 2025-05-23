#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int n, p, b;
    cin >> n >> p >> b;
    
    int sr, sc;
    cin >> sr >> sc;
    
    vector<pair<int, int>> popcorn[101];
    vector<pair<int, int>> boulders[101];
    
    for (int i = 0; i < p; i++) {
        int r, c, t;
        cin >> r >> c >> t;
        popcorn[t].push_back({r, c});
    }
    
    for (int i = 0; i < b; i++) {
        int r, c, t;
        cin >> r >> c >> t;
        boulders[t].push_back({r, c});
    }
    

    int dp[101][100][100];
    memset(dp, -1, sizeof(dp));

    //initial state
    dp[0][sr][sc] = 0;
    
    //movement vectors
    int dr[] = {0, 0, 1, -1, 0};
    int dc[] = {1, -1, 0, 0, 0};
    
    //calculate every step
    for (int t = 0; t <= 99; t++) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (dp[t][r][c] == -1) continue;
                
                //try all moves
                for (int d = 0; d < 5; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    
                    int next_time = t + 1;
                    int currpopcorn = dp[t][r][c];
                    
                    //boulder
                    for (auto& pos : boulders[next_time]) {
                        if (pos.first == nr && pos.second == nc) {
                            currpopcorn = currpopcorn - ((currpopcorn + 1) / 2);
                            break;
                        }
                    }
                    
                    //popcorn
                    for (auto& pos : popcorn[next_time]) {
                        if (pos.first == nr && pos.second == nc) {
                            currpopcorn++;
                        }
                    }
                    
                    dp[next_time][nr][nc] = max(dp[next_time][nr][nc], currpopcorn);
                }
            }
        }
    }
    
    int maxpopcorn = 0;
    for (int t = 0; t <= 100; t++) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (dp[t][r][c] != -1) {
                    maxpopcorn = max(maxpopcorn, dp[t][r][c]);
                }
            }
        }
    }
    
    cout << maxpopcorn << endl;
    
    return 0;
}