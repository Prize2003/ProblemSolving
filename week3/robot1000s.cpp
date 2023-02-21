#include <bits/stdc++.h>

using namespace std;

int main()
{
    string opt;
    cin >> opt;
    int k;
    cin >> k;
    int N = 0;
    int W = 0;
    int E = 0;
    int S = 0;
    for (int i = 0; i < opt.size(); i++)
    {
        if (opt[i] == 'N')
        {
            N += 1;
        }
        if (opt[i] == 'W')
        {
            W += 1;
        }
        if (opt[i] == 'E')
        {
            E += 1;
        }
        if (opt[i] == 'S')
        {
            S += 1;
        }
    }
    int mx=0,lost=0;
    if(N>S){
        mx=N;
        lost=S;
    }
    else{
        mx=S;
        lost=N;
    }
    if(W>E){
        mx+=W;
        lost+=E;
    }
    else{
        mx+=E;
        lost+=W;
    }
    if(lost>k){
        lost-=k;
    }
    else{
        lost=k-lost;
    }
    cout<<(mx-lost)*2;
}

/*
NNEESW
2
*/