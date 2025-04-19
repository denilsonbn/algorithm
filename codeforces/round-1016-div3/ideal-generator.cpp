#include <iostream>

#define IOS cin.tie(0)->ios_base::sync_with_stdio(false)

using namespace std;

void solve() {

    int a;
    cin >> a;
    if (a == 1) {
        cout << "yes\n";
        return;
    }

    if (a & 1) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    IOS;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}