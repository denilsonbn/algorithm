#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int build(int node, int l, int r, vector<ll>& nums, vector<ll>& seg) {
    if (l == r) return seg[node] = nums[l];

    int m = (l + r) >> 1;

    return seg[node] = build(node*2, l, m, nums, seg)
        + build(node*2+1, m+1, r, nums, seg);
}

void update(int node, int l, int r, int i, ll value, vector<ll>& nums, vector<ll>& seg) {
    if (l == r) {
        seg[node] = nums[l] = value;
        return;
    }

    int m = (r+l) >> 1;

    if (i >= l && i <= m) {
        update(node*2, l, m, i, value, nums, seg);
    } else {
        update(node*2+1, m+1, r, i, value, nums, seg);
    }

    seg[node] = seg[node*2] + seg[node*2+1];
    
}

ll query(int node, int l, int r, int a, int b, vector<ll>& nums, vector<ll>& seg) {
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return seg[node];
    int m = (l+r) >> 1;
    return query(node*2, l, m, a, b, nums, seg) +
    query(node*2+1, m+1, r, a, b, nums, seg);
}

int main() {
    int k, q;
    cin >> k >> q;

    vector<ll> nums(k);
    vector<ll> seg(4*k);

    for (int i = 0; i < k; i++) {
        cin >> nums[i];
    }

    build(1, 0, k-1, nums, seg);
    
    while(q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            update(1, 0, k-1, x, y, nums, seg);
        } else {
            cout << query(1, 0, k-1, x, y-1, nums, seg) << '\n';
        }
        q--;
    }

    return 0;
}