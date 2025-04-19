#include <iostream>
#include <vector>
#include <queue>

#define IOS cin.tie(0)->ios_base::sync_with_stdio(false);
#define LOG 20

using namespace std;

vector<vector<int>> graph, up;
vector<int> depth;
vector<bool> vis;

void bfs() {
    queue<int> fila;
    vis[1] = 1;
    fila.push(1);

    while(!fila.empty()) {
        int curr = fila.front();
        fila.pop();

        for (auto e:graph[curr]) {
            if (!vis[e]) {\
                depth[e] = depth[curr] + 1;
                up[e][0] = curr;
                vis[e] = 1;
                fila.push(e);
            }
        }
    }


}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    int ans = k;

    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }

    if (a == b) return ans;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
            ans += ((1 << j) * 2);
        }
    }

    return ans + 2;

}

int main() {
    IOS

    int n, q;
    cin >> n >> q;
    graph.resize(n+1);
    depth.assign(n+1, 0);
    vis.assign(n+1, 0);
    up.assign(n+1, vector<int>(LOG));

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();
    up[0].assign(LOG, 0);
    up[1].assign(LOG, 0);

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}