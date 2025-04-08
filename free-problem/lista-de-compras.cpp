#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {
    int k;
    cin >> k;
    cin.ignore();

    for (int i=0; i<k; i++) {
        string food;
        getline(cin, food);
        set<string> list;
        int t = 0;

        istringstream iss(food);

        string f;

        while(iss >> f) {
            if (list.find(f) == list.end()) t++;
            list.insert(f);
        }

        int c = 0;

        for (auto e:list) {
            c++;
            if (c == t) {
                cout << e;
                break;
            }
            cout << e << " ";
        }

        cout << "\n";

    }

    return 0;
}
