#include <bits/stdc++.h>

using namespace std;


int bfs(vector <int> Graph[],int n,int start,int h){
    queue <int> q;
    int visit[n]={0};
    q.push(start);
    visit[start]=1;
    int walk[n]={0};
    int lnk=1;
    while(!q.empty()){

        int t=q.front();
        // cout<<"t: "<<t+1<<endl;
        q.pop();
        // if(walk[t]==h){
        //     break;
        // }
        for(auto a:Graph[t]){
            if(visit[a]==0&&walk[t]+1<=h){
                visit[a]=1;
                q.push(a);
                walk[a]=walk[t]+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(walk[i]<=h&&walk[i]!=0){
            lnk+=1;
        }
    }
    return lnk;
}

int main(){
    int n,m,h;
    cin>>n>>m>>h;
    vector <int> Graph[n];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        Graph[a-1].push_back(b-1);
        Graph[b-1].push_back(a-1);
    }
    // for(auto a:Graph[0]){
    //     cout<<a+1<<endl;
    // }

    int hospital=0;
    for(int i=0;i<n;i++){
        // cout<<"village: "<<i+1<<endl;
        int contract=bfs(Graph,n,i,h);
        // cout<<"contract: "<<contract<<endl;
        hospital=max(contract,hospital);
        // cout<<endl;
    }
    cout<<hospital;
}
// 7 7 2
// 1 2
// 7 1
// 1 3
// 3 4
// 4 5
// 6 5
// 3 6