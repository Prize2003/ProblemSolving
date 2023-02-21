#include <bits/stdc++.h>

using namespace std;

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

int mst( set<pair<int,pair<int,int>>> &edge,int n,int m){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int ans=0;
    for (auto a:edge)
    {
        if (find_parent(a.second.first) != find_parent(a.second.second))
        {
            union_set(a.second.first, a.second.second);
            ans+=a.first;
        }
    }
    int check=find_parent(parent[0]);
    bool ck=1;
    for(int i=0;i<n;i++){
        if(find_parent(parent[i])!=check){
            ck=0;
        }
    }
    if(ck){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    set<pair<int,pair<int,int>>> edge;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge.insert({w,{a-1,b-1}});
        int ans=mst(edge,n,i+1);
        cout<<ans<<"\n";
    }

}

/*
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 2
*/