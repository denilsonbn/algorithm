#include <iostream>
#include <vector>
#include <climits>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

vector<ll> nums;
vector<pll> seg;

pll rest(pll a, pll b) {
    if (a.first < b.first) return a;
    else if (b.first < a.first) return b;
    else return {a.first, b.second + a.second};
}

pll build(int node, int l, int r) {
    if (l == r) {
        return seg[node] = {nums[l], 1};
    }
    int m = (r + l) >> 1;
    return seg[node] = rest(build(node*2, l, m), 
    build(node*2+1, m+1, r));
}

void update(int node, int l, int r, int i, ll value) {
    if (l == r) {
        nums[i] = value;
        seg[node] = {value, 1};
        return;
    }
    int m = (l + r) >> 1;
    if (i <= m) update(node*2, l, m, i, value);
    else update(node*2+1, m+1, r, i, value);
    
    seg[node] = rest(seg[node*2], seg[node*2+1]);

}

pll query(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return {LLONG_MAX, 1};
    if (l >= a && r <= b) return seg[node];
    
    int m = (l + r) >> 1;
    
    return rest(query(node*2, l, m, a, b), 
    query(node*2+1, m+1, r, a, b));

}

int main() {
     cin.tie(0)->ios_base::sync_with_stdio(false);
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
             pll ans = query(1, 0, n-1, x, y-1);
             cout << ans.first << " " << ans.second << "\n";
         }
     }
     
     return 0;
}