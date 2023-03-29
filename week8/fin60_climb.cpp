#include <bits/stdc++.h>

using namespace std;

char cliff[100][100];
int power[100][100];

int bfs(int h,int w){
    queue <pair<int,int>> q;
    q.push({h-1,0});
    power[h-1][0]=0;
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        // cout<<"h: "<<t.first<<" w: "<<t.second<<"\n";
        if(t.first!=0&&cliff[t.first-1][t.second]!='X'&&power[t.first-1][t.second]>power[t.first][t.second]+5){
            power[t.first-1][t.second]=power[t.first][t.second]+5;
            q.push({t.first-1,t.second});
        }
        if(t.first!=h-1&&cliff[t.first+1][t.second]!='X'&&power[t.first+1][t.second]>power[t.first][t.second]){
            power[t.first+1][t.second]=power[t.first][t.second];
            q.push({t.first+1,t.second});
        }
        if(t.second!=0&&cliff[t.first][t.second-1]!='X'&&power[t.first][t.second-1]>power[t.first][t.second]+1){
            power[t.first][t.second-1]=power[t.first][t.second]+1;
            q.push({t.first,t.second-1});
        }
        if(t.second!=w-1&&cliff[t.first][t.second+1]!='X'&&power[t.first][t.second+1]>power[t.first][t.second]+1){
            power[t.first][t.second+1]=power[t.first][t.second]+1;
            q.push({t.first,t.second+1});
        }
    }
    if(power[0][w-1]==10000000){
        return -1;
    }
    else{
        return power[0][w-1];
    }
}

int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>cliff[i][j];
            power[i][j]=10000000;
        }
    }
    int ans=bfs(h,w);
    cout<<ans;
}

/*
4 5
...X.
...X.
...X.
.X...
*/

/*
6 4
....
....
....
....
....
....
*/

/*
4 5
...X.
...X.
...XX
.X...
*/

/*
6 7
...XXX.
.X.X...
.X...XX
..X....
...XXX.
.X.....
*/