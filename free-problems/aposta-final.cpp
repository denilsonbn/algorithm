#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, q1, q2;
    cin >> a >> b >> q1 >> q2;

    double p1 = (a / 100.0) * q1, p2 = (b / 100.0) * q2;

    if (p1 > p2) cout << "1\n";
    else if (p1 < p2) cout << "2\n";
    else cout << "0\n";


    return 0;
}