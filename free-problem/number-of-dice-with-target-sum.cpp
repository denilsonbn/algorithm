#include <iostream>

using namespace std;

const int MAXN = 1e6, MOD = 1e9+7;

long long dp[MAXN];
bool vis[MAXN];

long long ways(int target, int play, int faces) {
    if (play == 0 && target == 0) return 1;
    if (play < 0 || target < 0) return 0;

    if (vis[target]) return dp[target];
    vis[target] = 1;

    for (int i=1; i<=faces; i++) {
        dp[target] = (dp[target] % MOD + ways(target-i, play-1, faces) % MOD) % MOD;
    }

    return dp[target];

}

int main() {
    long long play, faces, target;
    cin >> play >> faces >> target;

    cout << ways(target, play, faces) << "\n";


    return 0;
}