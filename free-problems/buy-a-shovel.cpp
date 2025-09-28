#include <iostream>

using namespace std;

int main() {
    int k, r;
    cin >> k >> r;

    int royal = k;

    int cont = 1;

    while (true) {
        if ((k - r) % 10 == 0) {
            break;
        }
        if (k % 10 == 0) break;
        k += royal;
        cont++;
    }

    cout << cont << "\n";

    return 0;
}