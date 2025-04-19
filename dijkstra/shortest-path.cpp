#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define pii pair<unsigned long long, unsigned long long>
#define ll unsigned long long
#define int unsigned long long

using namespace std;

const int INF = 1e18;

vector<vector<pii>> graph;
vector<ll> dist;
vector<int> parent;
stack<pii> ans;

void dijkstra(int& s) {
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> next;
    next.push({0, s});

    while (!next.empty()) {
        int curr = next.top().second;
        ll w = next.top().first;
        next.pop();

        for (auto e:graph[curr]) {
            if (w + e.second < dist[e.first]) {
                parent[e.first] = curr;
                dist[e.first] = w + e.second;
                next.push({dist[e.first], e.first});
            }
        }
    }
}

void find(int s) {

    int p = parent[s];

    while (s != p) {
        ans.push({s, p});
        s = p;
        p = parent[s];
    }
}

void solve(int s) {
    if (dist[s] == INF) {
        cout << "-1\n";
        return;
    }

    find(s);

    cout << dist[s] << " " << ans.size() << "\n";

    
    while(!ans.empty()) {
        cout << ans.top().second << " " << ans.top().first << "\n";
        ans.pop();
    }
}

int32_t main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    graph.resize(n);
    dist.assign(n, INF);
    parent.resize(n);

    for (int i = 0; i < n; i++) parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(s);

    solve(t);

    return 0;
}