#include <iostream>
#include <vector>
#include <limits>
#define ll long long

using namespace std;

vector<ll> nums, seg;

ll build(int node, int l, int r) {
    if (l == r) return seg[node] = nums[l];
    int m = (r + l) >> 1;
    return seg[node] = min(build(node*2, l, m), 
    build(node*2+1, m+1, r));
}

void update(int node, int l, int r, int i, ll value) {
    if (l == r) {
        seg[node] = nums[i] = value;
        return;
    }
    int m = (l + r) >> 1;
    if (i <= m) update(node*2, l, m, i, value);
    else update(node*2+1, m+1, r, i, value);
    
    seg[node] = min(seg[node*2], seg[node*2+1]);

}

ll query(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return LLONG_MAX;
    if (l >= a && r <= b) return seg[node];
    
    int m = (l + r) >> 1;
    
    return min(query(node*2, l, m, a, b), 
    query(node*2+1, m+1, r, a, b));

}

int main() {
     int n, k;
     cin >> n >> k;
     nums.resize(n);
     seg.resize(4*n);
     
     for (int i = 0; i < n; i++) {
         cin >> nums[i];
     }

     build(1, 0, n-1);
     
     while(k--) {
         ll op, x, y;
         cin >> op >> x >> y;
         if (op == 1) {
             update(1, 0, n-1, x, y);
         } else {
             cout << query(1, 0, n-1, x, y-1) << "\n";
         }
     }
     
     return 0;
}