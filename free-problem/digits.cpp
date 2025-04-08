    #include <iostream>
    #include <cmath>
    #define int long long

    using namespace std;

    char dudu(int k) {
        int digits = 1, start = 1, count = 9;

        while (k > digits * count) {
            k -= digits * count;
            digits++;
            start *= 10;
            count *= 10;
        }

        int number = start + (--k / digits);
        int index = k % digits;

        return to_string(number)[index];
    }

    int32_t main() {
        int k, j;

        cin >> k;

        for(int i = 0; i < k; i++) {
            cin >> j;

            cout << dudu(j) << endl;
        }
        return 0;
    }