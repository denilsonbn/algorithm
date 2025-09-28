#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    n *= 2;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m = n / 2;

    cout << a[m] - a[m-1] << "\n";
}

int main() {

    int t;

    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}