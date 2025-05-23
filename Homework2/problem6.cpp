#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    //base cases
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    } else if (n == 2) {
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> adj(n+1);
    vector<int> degree(n+1, 0);
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    queue<int> leaves;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 1) {
            leaves.push(i);
        }
    }

    int remaining = n;
    int distance = 0;

    while(remaining > 2) {
        int leafcount = leaves.size();
        remaining -= leafcount;

        for(int i = 0; i < leafcount; i++) {
            int leaf = leaves.front();
            leaves.pop();

            for(int neighbor : adj[leaf]) {
                degree[neighbor]--;
                if(degree[neighbor] == 1) {
                    leaves.push(neighbor);
                }
            }
        }

        distance++;
    }

    if(remaining == 2) {
        distance++;
    }

    cout << distance << endl;

    return 0;
}