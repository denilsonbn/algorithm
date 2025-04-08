#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool sub(string a, string b) {
    
    size_t  j = 0;

    for (size_t i = 0; i < b.size(); i++) {
        if (a[j] == b[i]) {
            j++;
        } else {
            j = 0;
            if (a[j] == b[i]) j++;
        }
        if (j == a.size()) return 1;
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<pair<size_t, string>> word(n);

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        word[i] = {name.size(), name};
    }

    sort(word.begin(), word.end());

    int cont = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (sub(word[i].second, word[j].second)) cont++;
        }
    }

    cout << cont << "\n";

    return 0;
}