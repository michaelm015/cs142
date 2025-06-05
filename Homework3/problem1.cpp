#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int MAXN = 1e6 + 5;

vector<int> tree[MAXN];
unordered_set<int> traitors;
vector<bool> visited(MAXN, false);

int dfs(int node) {
    if (traitors.count(node)) return 0;
    visited[node] = true;
    int count = 1;

    for (int child : tree[node]) {
        if (!visited[child] && !traitors.count(child)) {
            count += dfs(child);
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
        tree[i].push_back(parent);
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        traitors.insert(t);
    }

    int maxConnected = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !traitors.count(i)) {
            int componentSize = dfs(i);
            maxConnected = max(maxConnected, componentSize);
        }
    }
    
    cout << maxConnected << '\n';
    return 0;
}
