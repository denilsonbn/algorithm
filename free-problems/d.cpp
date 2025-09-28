#include <bits/stdc++.h>
using namespace std;
    
bool isGood(vector<int> &vet, int k){
    int i=0, j=k-1; 
    int last = -1;
    
    while(i<=j){
        if(vet[i] <= vet[j]){
            if(vet[i] < last)return false;
            last = vet[i];
            i++;
        }
    
        else{
            if(vet[j] < last) return false;
            last = vet[j];
            j--;
        }
    }
    return true;
}   
    
int main(){
    int rep;
    cin>>rep;
    
    while(rep--){
        int m;
        cin>>m;
    
        vector<int> vet(m);
        
    
        for(int i=0; i<m; i++)cin>>vet[i];
        if(m==1){
            cout<<"1\n";
            continue;
        }
    
    
        int low=1, high= m, ans=0;
        
        while(low<= high){
            int mid=(low+high)/2;
            if(isGood(vet, mid)){
                ans = mid;
                low = mid+1;
            }
    
            else{
                high = mid-1;
            }
        }
    
        cout<<ans<<"\n";
    }
}