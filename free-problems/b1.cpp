#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    int cont = 0;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((nums[i] ^ nums[j]) == nums[i]) cont++;
        }
    }

    cout << cont << "\n";

    
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}