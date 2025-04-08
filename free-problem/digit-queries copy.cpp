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
    
}

int main() {
    int k;
    cin >> k;

    cout << position(k) << "\n";


    return 0;
}