#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> yep, no;

    string ans = "";

    while (true) {

        string n, list;
        cin >> n >> list;

        if (n == "FIM") break;
        if (list == "YES") yep.insert(n);
        else no.insert(n);

        if (n.size() > ans.size() && list == "YES") {
            ans = n;
        }


    } 

    for (auto e:yep) cout << e << "\n";
    for (auto e:no) cout << e << "\n";
    
    cout << "\n";
    cout << "Amigo do Habay:" << "\n" << ans << "\n";

    return 0;
}