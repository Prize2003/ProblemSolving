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
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[j-1]==t[i-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    cout<<c[m][n];

}


/*
AABBCDEF
ABECEF
*/

/*
AAABBBABCABC
AABACABCEDF
*/