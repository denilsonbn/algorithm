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

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n;
    cin  >> n;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    son.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vis[0] = 1;

    dfs(0);

    cout << "\n";

    for (int i = 0; i <= n; i++) {
        cout << i << " " << son[i] << "\n";
    }

    return 0;
}