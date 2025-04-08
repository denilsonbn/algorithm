#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void dfs(int in, vector<vector<int>> graph, vector<bool>& vis, vector<int>& dist) {
    vis[in] = 1;

    //eu posso pegar a folha aqui tbm

    for (auto node:graph[in]) {
        if (!vis[node]) {
            dist[node] = dist[in] + 1;
            vis[node] = 1;
            dfs(node, graph, vis, dist);
        }
    }

}

string ans(int param, vector<int> dist, vector<int> leaf) {

    for (int i=1; i<= (int) dist.size(); i++) {
        if (leaf[i] == 1 && dist[i] != param) return "mal";
    }
    return "bem";
}

int main() {

    int k;
    cin >> k;

    vector<vector<int>> graph(k+1);
    vector<bool> vis(k+1);
    vector<int> leaf(k+1, 0);

    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        leaf[a]++;
        leaf[b]++;
    }

    vector<int> dist(k+1, 0);

    dfs(0, graph, vis, dist);

    int param = 0;

    for (int i=1; i<=k; i++) {
        if (leaf[i] == 1) {
            param = dist[i];
            break;
        }
    }

    cout << ans(param, dist, leaf) << "\n";


    return 0;
}