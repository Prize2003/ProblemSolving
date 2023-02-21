#include <bits/stdc++.h>

using namespace std;

int speed[200000];
set<pair<int,pair<int,int>>> edge;

int parent[100000];

int find_parent(int v)
{
    if (parent[v] != v)
    {
        return parent[v] = find_parent(parent[v]);
    }
    return v;
}

void union_set(int a, int b)
{

    a = find_parent(a);
    b = find_parent(b);
    if (a != b)
    {
        parent[b] = a;
      
    }
}


int mst(int n,int m){
    int ans=0;
    for (auto a:edge)
    {
        int time=ceil(a.first/(speed[a.second.first]+speed[a.second.second]));
        if (find_parent(a.second.first) != find_parent(a.second.second))
        {
            union_set(a.second.first, a.second.second);
            if(a.first>ans){
                ans=a.first;
            }
        }
    }
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>speed[i];
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        double w;
        cin>>a>>b>>w;
        edge.insert({w,{a,b}});
    }
    int ans=mst(n,m);
    if(ans%2==0){
        cout<<ans/2<<"\n";
    }
    else{
       cout<<ans/2+1<<"\n"; 
    }
}

/*
5 7
1 1 1 1 1
1 2 2
1 4 6
1 5 5
2 3 8
2 4 4
2 5 7
3 4 2
*/