#include <iostream>
#include <vector>

using namespace std;

vector<int> sz, sets;

int find(int p) {
    if (sets[p] == p) return p;
    return sets[p] = find(sets[p]);
}

void uni(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sets[b] = a;
    sz[a] += sz[b];
}

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    sz.assign(n, 1);
    sets.resize(n);

    for (int i = 0; i < n; i++) {
        sets[i] = i;
    }

    while(k--) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        if (op == "union") uni(--u, --v);
        else {
            if (find(--u) == find(--v)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}