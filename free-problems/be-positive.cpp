#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int m = 0, z = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == -1) m++;
        if (a == 0) z++;
    }

    int ans = 0;

    if (m&1) ans += 2;
    
    ans += z;

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