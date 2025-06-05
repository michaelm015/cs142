#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000000;

int parent[MAXN];
int size_arr[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (size_arr[rx] < size_arr[ry]) {
        parent[rx] = ry;
        size_arr[ry] += size_arr[rx];
    } else {
        parent[ry] = rx;
        size_arr[rx] += size_arr[ry];
    }
}

struct Operation {
    string type;
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    map<pair<int, int>, bool> edge_exists;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edges.push_back(make_pair(u, v));
        edge_exists[make_pair(u, v)] = true;
    }

    int k;
    cin >> k;
    vector<Operation> ops(k);
    set<pair<int, int>> to_remove;

    for (int i = 0; i < k; ++i) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (x > y) swap(x, y);
        ops[i] = {s, x, y};
        if (s == "remove") {
            to_remove.insert(make_pair(x, y));
        }
    }

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size_arr[i] = 1;
    }

    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (to_remove.find(make_pair(u, v)) == to_remove.end()) {
            unite(u, v);
        }
    }

    vector<string> results;

    for (int i = k - 1; i >= 0; --i) {
        string type = ops[i].type;
        int x = ops[i].x;
        int y = ops[i].y;

        if (type == "query") {
            if (find(x) == find(y)) {
                results.push_back("Yes");
            } else {
                results.push_back("No");
            }
        } else if (type == "remove") {
            unite(x, y);
        }
    }

    for (int i = results.size() - 1; i >= 0; --i) {
        cout << results[i] << endl;
    }

    return 0;
}