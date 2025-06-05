#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 1e6 + 5;

int r, c;
int shyness[1005][1005];
vector<bool> visited(MAXN, false);
int minCost[MAXN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

int getIndex(int x, int y) {
    return x * c + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> shyness[i][j];
        }
    }

    int totalNodes = r * c;
    fill(minCost, minCost + totalNodes, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    minCost[0] = 0;
    pq.push({0, 0});
    
    int totalCandies = 0;
    int nodesAdded = 0;
    
    while (!pq.empty() && nodesAdded < totalNodes) {
        int cost = pq.top().first;
        int nodeIdx = pq.top().second;
        pq.pop();
        
        if (visited[nodeIdx]) continue;
        
        visited[nodeIdx] = true;
        totalCandies += cost;
        nodesAdded++;
        
        int x = nodeIdx / c;
        int y = nodeIdx % c;
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (isValid(nx, ny)) {
                int neighborIdx = getIndex(nx, ny);
                
                if (!visited[neighborIdx]) {
                    int costOption1 = shyness[x][y];
                    int costOption2 = shyness[nx][ny];
                    int edgeCost = min(costOption1, costOption2);
                    
                    if (edgeCost < minCost[neighborIdx]) {
                        minCost[neighborIdx] = edgeCost;
                        pq.push({edgeCost, neighborIdx});
                    }
                }
            }
        }
    }
    
    cout << totalCandies << '\n';
    
    return 0;
}