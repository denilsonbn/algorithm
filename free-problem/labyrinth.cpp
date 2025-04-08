#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1e3;

char matrix[MAXN][MAXN];
int vis[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];

vector<int> dx = {0, 1, -1, 0}, dy = {1, 0, 0, -1};
vector<char> dic = {'R', 'D', 'U', 'L'};

bool verif(int a, int b, int r, int c) {
    return a < r && a >= 0 && b < c && b >= 0 && vis[a][b] < 1 && matrix[a][b] != '#'; 
}

vector<char> ans;

bool bfs(int r, int c, pair<int, int> A, pair<int, int> B) {
    queue<pair<int, int>> next;
    next.push(A);
    vis[A.first][A.second] = 1;

    while(!next.empty()) {
        pair<int, int> curr = next.front();
        next.pop();

        for (int k=0; k<4; k++) {
            int new_a = curr.first + dx[k];
            int new_b = curr.second + dy[k];
            if (verif(new_a, new_b, r, c)) {

                parent[new_a][new_b] = curr;

                if (matrix[new_a][new_b] == 'B') {
                    return 1;
                }
                vis[new_a][new_b] = 1;
                next.push({new_a, new_b});
            }
        }
        
    }
    return 0;
}

void backtrack(pair<int, int> A, pair<int, int> B) {
    pair<int, int> curr = B;
    vector<char> ans;

    while (curr != A) {
        pair<int, int> par = parent[curr.first][curr.second];

        if (par.first == curr.first+1) ans.push_back('U');
        else if(par.first == curr.first-1) ans.push_back('D');
        else if (par.second == curr.second+1) ans.push_back('L');
        else if (par.second == curr.second-1) ans.push_back('R');

        curr = par;
    }

    reverse(ans.begin(), ans.end());
    if (ans.size()) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto e:ans) cout << e;
        cout << "\n";
    }
    else cout << "NO\n";

}


int main() {
    int r, c;
    pair<int, int> A, B;
    cin >> r >> c;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A') {
                A.first = i;
                A.second = j;
            }
            else if (matrix[i][j] == 'B') {
                B.first = i;
                B.second = j;
                vis[i][j] = -1;
            }
        }
    }

    bool ans = bfs(r, c, A, B);

    if (ans) backtrack(A, B);
    else cout << "NO\n";

    return 0;
}