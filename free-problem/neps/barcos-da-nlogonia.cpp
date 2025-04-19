#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <queue>

#define IOS cin.tie(0)->ios_base::sync_with_stdio(false);
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define MAXN 1e9
#define LOG 20

using namespace std;

vector<int> dsu, sz;
vector<tii> temp;
vector<vector<pii>> graph, up;
vector<int> depth;
vector<bool> vis;

int find(int p) {
    if (dsu[p] == p) return p;
    return dsu[p] = find(dsu[p]);
}

void uni(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    dsu[b] = a;
}

void bfs() {
    
    vis[1] = 1;

    queue<int> fila;
    fila.push(1);

    while(!fila.empty()) {
        int curr = fila.front();
        fila.pop();

        for (auto& e:graph[curr]) {
            if (!vis[e.second]) {
                vis[e.second] = 1;
                up[e.second][0] = {e.first, curr};
                depth[e.second] = depth[curr] + 1;
                fila.push(e.second);
            }
        }
    }

}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    int ans = MAXN;

    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            ans = min(ans, up[a][j].first);
            a = up[a][j].second;
        }
    }

    if (a == b) return ans;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j].second != up[b][j].second) {
            ans = min(ans, min(up[a][j].first, up[b][j].first));
            a = up[a][j].second;
            b = up[b][j].second;
        }
    }

    return min(ans, min(up[a][0].first, up[b][0].first));

}

int main() {
    IOS
    
    int n, b;
    cin >> n >> b;

    dsu.resize(n+1);
    sz.assign(n+1, 1);
    graph.resize(n+1);
    depth.assign(n+1, 0);
    vis.assign(n+1, 0);
    up.assign(n+1, vector<pii>(LOG));

    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }

    for (int j = 0; j < LOG; j++) {
        up[0][j] = {MAXN, 0};
        up[1][j] = {MAXN, 0};
    }

    for (int i = 0; i < b; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        temp.push_back({w, a, b});
    }

    sort(temp.rbegin(), temp.rend());

    for (auto [w, a, b]:temp) {
        if (find(a) != find(b)) {
            uni(a, b);
            graph[a].push_back({w, b});
            graph[b].push_back({w, a});
        }
    }

    bfs();

    for (int j = 1; j < LOG; j++) {
        for (int i = 2; i <= n; i++) {
            up[i][j].first = min(up[i][j-1].first, up[up[i][j-1].second][j-1].first);
            up[i][j].second = up[up[i][j-1].second][j-1].second;
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}