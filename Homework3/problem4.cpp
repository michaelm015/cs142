#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    int r, c;
    cin >> r >> c;
    
    vector<string> lake(r);
    vector<vector<int>> melt_day(r, vector<int>(c, 3000));
    
    int swan1_x = -1, swan1_y = -1;
    int swan2_x = -1, swan2_y = -1;
    
    for (int i = 0; i < r; i++) {
        cin >> lake[i];
        for (int j = 0; j < c; j++) {
            if (lake[i][j] == 'L') {
                if (swan1_x == -1) {
                    swan1_x = i;
                    swan1_y = j;
                } else {
                    swan2_x = i;
                    swan2_y = j;
                }
                lake[i][j] = '.';
            }
        }
    }
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (lake[i][j] == '.') {
                melt_day[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                if (lake[nx][ny] == 'X' && melt_day[nx][ny] == 3000) {
                    melt_day[nx][ny] = melt_day[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int left = 0, right = 0;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (melt_day[i][j] < 3000) {
                right = max(right, melt_day[i][j]);
            }
        }
    }
    
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> bfs_q;
        
        bfs_q.push({swan1_x, swan1_y});
        visited[swan1_x][swan1_y] = true;
        
        bool can_meet = false;
        
        while (!bfs_q.empty() && !can_meet) {
            int x = bfs_q.front().first;
            int y = bfs_q.front().second;
            bfs_q.pop();
            
            if (x == swan2_x && y == swan2_y) {
                can_meet = true;
                break;
            }
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                    if (!visited[nx][ny] && melt_day[nx][ny] <= mid) {
                        visited[nx][ny] = true;
                        bfs_q.push({nx, ny});
                    }
                }
            }
        }
        
        if (can_meet) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}