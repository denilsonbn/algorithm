#include <iostream>

using namespace std;

int position(int n) {
    if (n <= 9) return n;
    int num = n - 9, pot = 10;

    int digits = 2, nine = 9 * pot;

    while (num - nine * digits > 0) {
        num -= nine * digits;
        pot *= 10;
        nine = 9 * pot;
        digits++;
    }

    cout << num << "\n";

    int sum = num/digits;

    cout << sum << "\n";

    pot += sum;

    cout << pot << "\n";

    if (num%digits == 0) pot--;

    string ans = to_string(pot);

    cout << ans << "\n";

    int pos = (sum % digits) - 1;

    cout << sum % digits << "o\n";

    cout << pos << "\n";

    return ans[pos];
    
}

int main() {
    int k;
    cin >> k;

    int ans = position(k);

    cout << ans << "\n";

    return 0;
}