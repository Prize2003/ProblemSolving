#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];         // adjacency list
    vector<int> indegree(n, 0); // indegree of each node

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    queue<int> s;
    int notTopo = 0;
    for (int i = 0; i < n; i++)
        if (notTopo == 0 && indegree[i] == 0)
        {
            q.push(i);
            s.push(i);
            indegree[i] = -1;
        }
    if (q.empty()) notTopo = 1;
    if (notTopo)
    {
        cout << "no";
        return 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
                s.push(v);
                indegree[v] = -1;
            }
        }

    }
    for (int i = 0; i < s.size(); i++)
        cout << s.front() + 1 << endl, s.pop();
    return 0;
}