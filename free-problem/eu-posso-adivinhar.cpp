#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void solve(int k) {
    stack<int> pilha;
    queue<int> fila;
    priority_queue<int> filaP;

    int ans = 0;

    bool a = 1, b = 1, c = 1;

    for (int i=0; i<k; i++) {
        int op, value;
        cin >> op >> value;
        if (op == 1) { 
            ans++;
            pilha.push(value);
            fila.push(value);
            filaP.push(value);
        }
        else {
            ans--;
            if (pilha.top() == value && a) pilha.pop();
            else a = 0;

            if (fila.front() == value && b) fila.pop();
            else b = 0;
            
            if (filaP.top() == value && c) filaP.pop();
            else c = 0;
        }
    }

    if (ans != pilha.size() && ans != fila.size() && ans != filaP.size()) {
        cout << "impossible\n";
        return;
    }

    if (a && b || a && c || c && b) {
        cout << "not sure\n";
        return;
    }

    if (ans == pilha.size()) cout << "stack\n";
    else if ( ans == fila.size()) cout << "queue\n";
    else if (ans == filaP.size()) cout << "priority queue\n";

}

int main() {

    int k;
    
    while(cin >> k) {
        solve(k);
    }



    return 0;
}