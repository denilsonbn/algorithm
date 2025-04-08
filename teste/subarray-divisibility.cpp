#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n;
    vector<ll> nums(n);
 
    for (int i=0; i<n; i++) cin >> nums[i];
 
    vector<ll> sub(n);
    map<ll, ll> freq;
    freq[0] = 1;
 
    ll ans = 0, sum=0;
 
    for (int i=0; i<n; i++) {
        sum += nums[i];

        ans += freq[((sum%n)+n)%n];
        freq[((sum%n)+n)%n]++;

    }
 
 
    cout << ans << "\n";
 
    return 0;
}
