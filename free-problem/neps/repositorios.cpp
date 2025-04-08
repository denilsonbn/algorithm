#include <iostream>
#include <map>

using namespace std;

int main() {
    int p, v;
    cin >> p >> v;

    map<int, int> repo, up;

    while(p--) {
        int a, b;
        cin >> a >> b;
        repo[a] = b;
    }

    while(v--) {
        int a, b;
        cin >> a >> b;
        if (repo[a] < b) {
            up[a] = max(up[a], b);
        }
    }

    for (auto& e:up) {
        cout << e.first << " " << e.second << "\n";
    }


    return 0;
}