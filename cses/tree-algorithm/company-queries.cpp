#include <iostream>
#include <vector>
#include <queue>

const int LOG = 20;

using namespace std;

vector<vector<int>> up;
vector<int> depth;
vector<vector<int>> graph;

void bfs() {
    queue<int> fila;
    fila.push(1);

    while (!fila.empty()) {
        int curr = fila.front();
        fila.pop();

        for (auto e:graph[curr]) {
            depth[e] = depth[curr] + 1;
            fila.push(e);
        }
    }
}

int solve() {
    int a, b;
    cin >> a >> b;

    if (depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];

    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }

    if (a == b) {
        return a;
    }

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];

}

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    up.assign(n+1, vector<int>(LOG));
    depth.assign(n+1, 0);
    graph.resize(n+1);

    up[1][0] = 0;

    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
        graph[up[i][0]].push_back(i);
    }
    
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    bfs();

    while(q--) {
        cout << solve() << "\n";
    }

    return 0;
}