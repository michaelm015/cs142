#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9 + 5;

struct Edge {
    int to;
    int bumps;
    int dist;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({b, c, d});
        graph[b].push_back({a, c, d});
    }

    typedef tuple<int, int, int> State;
    priority_queue<State, vector<State>, greater<State>> pq;

    vector<pair<int, int>> best(n, make_pair(INF, INF));
    pq.push(make_tuple(0, 0, 0));
    best[0] = make_pair(0, 0);

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int bumps = get<0>(current);
        int dist = get<1>(current);
        int node = get<2>(current);

        if (make_pair(bumps, dist) > best[node]) {
            continue;
        }

        for (int i = 0; i < graph[node].size(); ++i) {
            Edge edge = graph[node][i];
            int new_bumps = bumps + edge.bumps;
            int new_dist = dist + edge.dist;

            if (make_pair(new_bumps, new_dist) < best[edge.to]) {
                best[edge.to] = make_pair(new_bumps, new_dist);
                pq.push(make_tuple(new_bumps, new_dist, edge.to));
            }
        }
    }

    cout << best[n - 1].first << " " << best[n - 1].second << endl;

    return 0;
}