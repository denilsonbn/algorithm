#include <iostream>
#include <vector>

using namespace std;

vector<int> subset;

void sub(int n, int k) {
    if (n == k) {
        for (auto e:subset) cout << e << " ";
        cout << "\n";
        return;
    }

    sub(n, k+1);
    subset.push_back(k);
    sub(n, k+1);
    subset.pop_back();

}

vector<int> nums={1, 2, 3};

void create(int n) {

    vector<int> sets[(1 << n)];

    for (int b=0; b<(1 << n); b++) {
        
        for (int i=0; i<n; i++) {
            if (b & (1 << i)) sets[b].push_back(i);
        }

    }

    for (int i=0; i<8; i++) {
        for (auto e:sets[i]) cout << e << " ";
        cout << "\n";
    }

}




int main() {
    int n; cin >> n;

    sub(n, 0);

    create(3);


}