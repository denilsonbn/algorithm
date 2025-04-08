#include <iostream>
#include <cmath>
#define int long long

using namespace std;

char dudu(int k) {
    
}

int32_t main() {
    int k;

    cin >> k;

    int digits = 1, start = 1, count = 9;

    while (k > digits * count) {
        k -= digits * count;
        digits++;
        start *= 10;
        count *= 10;
    }

    int number = start + floor((--k) / digits);
    int index = k % digits;

    cout << to_string(number)[index] << endl;
    return 0;
}