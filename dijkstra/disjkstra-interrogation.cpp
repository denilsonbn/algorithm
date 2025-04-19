#include <iostream>
#include <queue>
#include <utility>

#define IOS cin.tie(0)->ios_base::sync_with_stdio(false)
#define pii pair<long long, int>
#define ll long long
#define INF 1e15

using namespace std;

vector<vector<pii>> graph;
vector<ll> dist;
vector<int> parent, ans;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    fila.push({0, 1});
    dist[1] = 0;

    while(!fila.empty()) {
        pii curr  = fila.top();
        fila.pop();

        for (auto& e:graph[curr.second]) {
            if (curr.first + e.first < dist[e.second]) {
                dist[e.second] = curr.first + e.first;
                parent[e.second] = curr.second;
                fila.push({dist[e.second], e.second});
            }
        }
    }
}

void bfs(int n) {
    if (parent[n] == n) return;

    bfs(parent[n]);

    ans.push_back(n);
}

void solve() {
    cout << "1" << " ";
    for (auto& e:ans) {
        cout << e << " ";
    }
    cout << "\n";
}

void path(int n) {
    if (dist[n] == INF) {
        cout << "-1\n";
        return;
    }

    bfs(n);
    
    solve();
}


int main() {
    IOS;

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    dist.assign(n+1, INF);
    parent.assign(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    dijkstra();

    path(n);

    return 0;
}