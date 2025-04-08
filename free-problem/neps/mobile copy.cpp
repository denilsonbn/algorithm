#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> son;

void dfs(int n) {

    for (auto& e:graph[n]) {
        if (!vis[e]) {
            vis[e] = 1;
            dfs(e);
            son[n] += son[e] + 1;
        }
    }

}

bool bfs(int n) {
    vector<bool> vis_q(100010, 0);
    queue<int> fila;
    fila.push(n);
    vis_q[n] = 1;

    while(!fila.empty()) {
        int curr = fila.front();
        fila.pop();
        if (graph[curr].empty()) continue;

        int equal = 0;

        for (auto e:graph[curr]) {
            if (!vis_q[e]) equal = son[e];
        }

        for (auto e:graph[curr]) {
            if (!vis_q[e]) {
                if (son[e] != equal) {
                    return 0;
                }
                vis_q[e] = 1;
                fila.push(e);
            }
        }
    }

    return 1;

}

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    graph.resize(100010);
    vis.assign(100010, 0);
    son.assign(100010, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vis[0] = 1;

    dfs(0);

    if(bfs(0)) {
        cout << "bem\n";
    } else {
        cout << "mal\n";
    }

    return 0;
}
