#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long

using namespace std;

vector<ull> sefor(int s) {

    vector<ull> ans;
    
    for (int i = 0; i < (1 << s); i++) {
        string num="";
        int seven = 0, four = 0;
        for (int k = 0; k < s; k++) {
            if (i & (1 << k)) {
                num.push_back('4');
                four++;
            }
            else {
                num.push_back('7');
                seven++;
            }
        }
        if (seven == four) {
            ull n = stoull(num);
            ans.push_back(n);
        }   
    }
    
    return ans;

}

int main() {
     cin.tie(0)->ios_base::sync_with_stdio(false);
     string k;
     cin >> k;
     
     int t = (int)k.size();
     if (t & 1) t++;
     
     vector<ull> ans = sefor(t);
     
     sort(ans.begin(), ans.end());
     
     int r = stoi(k);
     for (auto& e:ans) {
         if (e >= r) {
             cout << e << "\n";
             break;
         } 
     }
     
     return 0;
}
