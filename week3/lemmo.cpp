#include <bits/stdc++.h>

using namespace std;

char table[200][200];

int right(int w,int h){

}

int left(int w,int h){

}

int main(){
    int w,h;
    cin>>w>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>table[i][j];
        }
    }
    int treasure=0;
    for(int i=0;i<w;i++){
        int l,r;
        r=right(w,h);
        l=left(w,h);
    }

}