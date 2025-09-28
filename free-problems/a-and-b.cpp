#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int tot = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i+1]) tot++;
    }

    if (tot <= 2) cout << "0\n";
    else {
        cout << ceil(tot / 4.0) << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}