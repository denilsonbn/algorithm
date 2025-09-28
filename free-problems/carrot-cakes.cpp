#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int t1 = n / k;

    t1 += (n % k == 0) ? 0 : 1;

    t1 = t1 * t;

    int t2 = 0, c = 0;

    vector<int> cake(100000, 0);

    for (int i = t; i <= 10000; i+=t) {
        cake[i] = 1;
    }

    for (int i = d + t; i <= 10000; i+= t) {
        cake[i]++;
    }

    for (int i = 0; i <= 10000; i++) {
        if (cake[i]) {
            t2 = i;
            c += (k * cake[i]);
        }
        if (c >= n) break;
    }

    if (t1 > t2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}