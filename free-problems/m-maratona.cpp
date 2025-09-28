#include <bits/stdc++.h>

using namespace std;

vector<int> nums, vet, seg;

int main() {
    int n, k;
    cin >> n >> k;
    nums.resize(n);
    vet.resize(n);
    seg.resize(n*4);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    return 0;
}