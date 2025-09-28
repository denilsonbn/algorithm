#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    int ans = 0;

    for (int i = 0; i < n - 1; i+=2) {
        ans = max(abs(nums[i] - nums[i+1]), ans);
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