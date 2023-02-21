#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> dead;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        dead.push_back({u,v});
    }
    sort(dead.begin(),dead.end());
    int sm=0;
    int maxlate=0;
    for(auto a:dead){
        sm+=a.second;
        if(sm-a.first>=10){
            maxlate=max(maxlate,sm-a.first);
        }
    }
    if(maxlate==0){
        cout<<0;
    }
    else{
        cout<<(maxlate-10)*1000;
    }
}