#include <bits/stdc++.h>

using namespace std;

int chain[100001];

int main(){
    int l,n;
    for(int i=0;i<l;i++){
        cin>>chain[i];
    }
    int itr=0;
    for(int i=0;i<n;i++){
        char opt;
        int num;
        cin>>opt;
        if(opt=='C'){
            int num;
            cin>>num;

        }
        else if(opt=='F'){
            if(itr!=l-1){
                itr+=1;
            }
        }
        else if(opt=='B'){
            if(itr!=0){
                itr-=1;
            }
        }
       
    }
}