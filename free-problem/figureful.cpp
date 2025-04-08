#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    map<pair<int, int>, string> user;
    int n; 
    cin >> n;

    while(n--) {
        int a, b;
        string name;
        cin >> a >> b >> name;
        user[{a, b}] = name;
    }

    int k;
    cin >> k;

    while(k--) {
        int a, b;
        cin >> a >> b;
        cout << user[{a, b}] << "\n";
    }

    return 0;
}