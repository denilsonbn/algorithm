#include <iostream>

using namespace std;

int co[50], di1[50], di2[50];


int queen(int n, int k) {
    if (k == n) return 1;

    int ans = 0;

    for (int c=0; c<n; c++) {
        if (co[c] || di1[k-c+n-1] || di2[k+c]) continue;
        co[c] = di1[k-c+n-1] = di2[k+c] = 1;
        ans += queen(n, k+1);
        co[c] = di1[k-c+n-1] = di2[k+c] = 0;
    }

    return ans;

}

int main() {
    int n; cin >> n;
    cout << queen(n, 0) << "\n";

    return 0;
}