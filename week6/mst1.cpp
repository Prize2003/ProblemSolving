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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    pair<int, pair<int, int>> edge[m];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;       
        edge[i]={w, {a, b}};
    }
    sort(edge,edge+m);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int ans=0;
    for (int i=0;i<m;i++)
    {
        if (find_parent(edge[i].second.first) != find_parent(edge[i].second.second))
        {
            union_set(edge[i].second.first, edge[i].second.second);
            ans+=edge[i].first;
        }
    }
    cout<<ans;
}

/*
4 5
1 2 10
1 3 20
3 4 5
4 2 7
2 3 12
*/