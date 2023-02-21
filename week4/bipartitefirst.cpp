/*
    Task    : 1.bipartite
    Author    : First
    School    : KU
    Language: C++
    Created    : 23 January 2023 [13:20]
    Algo    : Bipatite Graph
    Status    : 
*/
#include<bits/stdc++.h>
using namespace std;


bool isBipartite(vector<int> adj[], int src,int n, int m)
{
    cout << "Hey!";
    queue<int> q;
    int color[n] = {0};
    color[src] = 1; // 0 = no color, 1 = red, 2 = blue , set 'starting point' to be 'Red'
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (color[v] == 0)
            {
                color[v] = (color[u]==1)? 2 : 1; // set color of 'v' to be opposite of 'u'
                q.push(v);
            } // if color of 'v' is same as 'u' then it's not bipartite
            else if (color[v] == color[u])
                return false;
        }
    }
    return true;
}

int main(){
    int nLoops,n,m,u,v;
    cin >> nLoops;
    for (int i=0; i<nLoops ; i++)
    {
        cin >> n >> m;
        vector<int> adj[n];
        for (int j=0; j<m; j++)
        {
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (isBipartite(adj,0,n,m))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}