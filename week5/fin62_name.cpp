#include <bits/stdc++.h>

using namespace std;

int main(){
    string name;
    cin>>name;
    string text;
    cin>>text;
    int in=0;
    int ans=0;
    for(int i=0;i<text.size();i++){
        if(text[i]==name[in]){
            in+=1;
            if(in==name.size()){
                in=0;
                ans+=1;
            }
        }
    }
    cout<<ans;
}