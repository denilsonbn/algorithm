#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> rest;

    while(n--) {
        int l, r;
        cin >> l >> r;
        rest.push_back({l, 1});
        rest.push_back({r, -1});
    }

    sort(rest.begin(), rest.end());

    int cont = 0, ans = 0;

    for (auto& e:rest) {
        cont += e.second;
        ans = max(ans, cont);
    }

    cout << ans << "\n";

    return 0;
}