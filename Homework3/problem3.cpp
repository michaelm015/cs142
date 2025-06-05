#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, pair<int, int>> State;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    int n, t;
    cin >> n >> t;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    pq.push(make_pair(0, make_pair(0, 0)));
    dist[0][0] = 0;

    while (!pq.empty()) {
        State top = pq.top();
        pq.pop();

        int curr_time = top.first;
        int x = top.second.first;
        int y = top.second.second;

        if (x == n - 1 && y == n - 1) {
            cout << curr_time << endl;
            return 0;
        }

        if (curr_time <= dist[x][y]) {
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int extra_time = (grid[nx][ny] == 'b') ? t : 0;
                    int new_time = curr_time + 1 + extra_time;

                    if (new_time < dist[nx][ny]) {
                        dist[nx][ny] = new_time;
                        pq.push(make_pair(new_time, make_pair(nx, ny)));
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
