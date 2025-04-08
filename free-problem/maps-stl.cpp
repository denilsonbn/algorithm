#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int k;
    cin >> k;
    unordered_map<string, int> costume;

    while(k--) {
        int op;
        string name;
        cin >> op >> name;

        if (op == 1) {
            int value;
            cin >> value;
            if (costume[name]) {
                costume[name] += value;
            }
            else costume[name] = value;
        }
        else if (op == 2) {
            costume.erase(name);
        }
        else if (op == 3) {
            cout << costume[name] << "\n";
        }

    }

    return 0;
}
