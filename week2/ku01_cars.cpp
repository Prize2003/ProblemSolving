#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> eff;
    cin>>n;
    for(int i=0;i<n;i++){
        int p,v;
        cin>>p>>v;
        eff.push_back(v);
    }
    reverse(eff.begin(),eff.end());
    int lval=eff[0];
    int trash=0;
    for(int i=1;i<n;i++){
        if(eff[i]<lval){
            trash+=1;
        }
        else{
            lval=eff[i];
        }
    }
    cout<<trash;
}