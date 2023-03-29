
#include <bits/stdc++.h>

using namespace std;

int c[500][500];

int main(){
    string s,t;
    cin>>s;
    cin>>t;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    string lcs="";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[j-1]==t[i-1]){
                c[i][j]=c[i-1][j-1]+1;
                lcs+=s[j-1];
            }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    cout<<c[m][n]<<"\n";
    string ans_rev="";
    int i=m, j=n;
    while(i>0 && j>0){
        if(s[j-1]==t[i-1]){
            ans_rev+=s[j-1];
            i-=1;
            j-=1;
        }
        else if(c[i-1][j]>c[i][j-1]){
            i-=1;
        }
        else{
            j-=1;
        }
    }
    string ans="";
    for(int i=ans_rev.size()-1;i>=0;i--){
        ans+=ans_rev[i];
    }
    cout<<ans;
}
