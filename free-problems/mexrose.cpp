#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == k) ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}