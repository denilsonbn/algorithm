#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> p;
vector<int> dist;

int32_t main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    dist.resize(n-1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }

    for (int i = 0; i < n - 1; i++) {
        if (p[i].first == p[i+1].first) {
            dist[i] = abs(p[i].second - p[i+1].second);
        }
        else {
            dist[i] = abs(p[i].first - p[i+1].first);
        }
    }

    long long sum = 0;
    long long inf = 1, sup = dist[0] - 1;

    for (int i = 1; i < n-1; i++) {
        
        sum = dist[i] - sum;

        if (i & 1) inf = max(inf, 1 - sum);
        else sup = min(sup, sum - 1);
    }

    cout << sup << " " << inf << "\n";

    if (inf > sup) {
        cout << "-1\n";
    }
    else {
        cout << sup << "\n";
    }
    
    return 0;
}