#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> nums(n);

    for (int i=0; i<n; i++) {
        int value;
        cin >> value;
        nums[i] = {value, i};
    }

    sort(nums.begin(), nums.end());

    for (int i=0; i<n; i++) {
        int curr = sum - nums[i].first;
        if (curr < 0) continue;
        
        //two pointers logic
        int l=0, r=n-1;
        while(l < r) {
            int rest = nums[l].first + nums[r].first;
            if (l != i && r != i && rest == curr) {
                cout << nums[i].second+1 << " " << nums[l].second+1 << " " << nums[r].second+1 << "\n";
                return 0;
            }
            else if (rest > curr) {
                r--;
            }
            else l++;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
