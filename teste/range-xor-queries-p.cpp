#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& xorq, int n) {
    for (int i=1; i<n; i++) {
        xorq[i] = xorq[i] ^ xorq[i-1];
    }


}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> xorq(n);

    for (int i=0; i<n; i++) cin >> xorq[i];

    solve(xorq, n);

    while (k--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a == 0) {cout << xorq[b] << "\n"; continue;}
        int ans = xorq[b] ^ xorq[a-1];
        cout << ans << "\n";

    }


    return 0;
}