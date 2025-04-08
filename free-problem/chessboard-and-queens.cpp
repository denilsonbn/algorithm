#include <iostream>

using namespace std;

const int MAXN = 10;

char chess[MAXN][MAXN];
bool rows[MAXN], colums[MAXN], di1[20], di2[20];

int queens(int t=0) {
    if (t == 8) return 1;

    for (int i=1; i<=8; i++) {
        
    }


} 

int main() {

    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            char pt;
            cin >> pt;
            if (pt == '*') {
                rows[i] = colums[j] = di1[i+j] = di2[i-j+8] = 1;
            }
        }
    }


    return 0;
}