#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long

using namespace std;

ull expr(string s) {
    string n = "";
    ull sum = 0;
    
    for (auto& e:s) {
        if (e == '+') {
            sum += stoull(n);
            n = "";
        } else {
            n.push_back(e);
        }
    }
    
    return sum + stoull(n);

}

ull sum(string k) {
    int t = (int)k.size() - 1;
    ull ans = 0;
    
    for (int i = 0; i < (1 << t); i++) {
        string num = "";
        
        for (int j = 0; j < t; j++) {
            num.push_back(k[j]);
            if (i & (1 << j)) num.push_back('+');
        }
        num.push_back(k.back());
        ans += expr(num);
    }
    
    return ans;

}

int main() {
     cin.tie(0)->ios_base::sync_with_stdio(false);
     string k;
     cin >> k;
     
     cout << sum(k) << "\n";
     
     return 0;
}
    