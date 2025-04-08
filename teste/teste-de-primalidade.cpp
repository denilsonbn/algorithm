#include <bits/stdc++.h>

using namespace std;

vector<int> multiplos;

void fatores(int n) {
    

    for (int i=1; i*i<=n; i++) {

        if (n%i == 0) {
            if (i == n/i) multiplos.push_back(i);
            else {multiplos.push_back(i); multiplos.push_back(n/i);}
        }

    }
}

void fatores_primos(int n) {

    for (int i=1; i<=n; i++) {

    }

}

int main() {
    int num; cin >> num;

    fatores(num);

    for (auto e:multiplos) cout << e << " ";



    return 0;
}
