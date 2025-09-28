#include <bits/stdc++.h>
using namespace std;
    
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int rep;
    cin>>rep;
    
    while(rep--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
    
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        vector<vector<int>> maxLen(n, vector<int>(n,0));
    
        for(int i=0; i<n; i++){
            isPal[i][ i] = true;
            maxLen[i][i]= 1;
        }
    
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                isPal[i][i+1] = true;
                maxLen[i][i+1] = 2;
            }
    
            else{
                maxLen[i][i+1] = 1;
            }
        }
    
        for(int len=3; len<=n; len++){
            for(int i = 0;i<=n-len; i++){
                int j = i+len - 1;
                if(s[i] == s[j] &&  isPal[i+1][j-1]){
                    isPal[i][j]=true;
                    maxLen[i][j]= len;
                }
                else{
                    isPal[i][j] = false;
                    maxLen[i][j] = max(maxLen[i+1][j], maxLen[i][j-1]);
                }
            }
        }
    
        while(m--){
            int l,r;
            cin>>l>>r;
            l--, r--;
            cout<<maxLen[l][r]<<"\n";
        }
    }
}