#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> dp(32, vector<int>(1010, -1));

    int numRollsToTarget(int n, int k, int target) {
        if (target == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][target] != -1) return dp[n][target];

        int cont = 0;

        for (int i = 1; i <= k; i++) {
            if (target - i >= 0) {
                dp[n][target] = numRollsToTarget(n - 1, k, target - i);
            }
        }

        return dp[n][target];

    }
};

int main() {

    int n, k, t;
    cin >> n >> k >> t;

    Solution solution;

    cout << solution.numRollsToTarget() << "\n";

    return 0;
}

