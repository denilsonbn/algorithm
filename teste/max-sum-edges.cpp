#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> nums(n), freq(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // vertice a se liga com vertice b
    while(m--) {
        int a, b;
        cin >> a >> b;
        freq[a]++;
        freq[b]++;
    }
    // maiores frequencia(vizinhos) com os maiores valores
    sort(nums.rbegin(), nums.rend());
    sort(freq.rbegin(), freq.rend());

    int ans = 0;

    // se um no tem k vizinhos, entao seu valor ira ser contado k vezes
    for (int i = 0; i < n; i++) {
        ans += nums[i] * freq[i];
    }

    cout << ans << "\n";


    return 0;
}
