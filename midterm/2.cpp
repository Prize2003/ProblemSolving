#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> *Graph,int n)
{
    int visit[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if(visit[i])
        {
            continue;
        }
        string ans = "yes";
        queue<vector<int>> q;
        q.push(Graph[i]);
        visit[i] = 1;
        queue<int> head;
        head.push(i);
        int r = 1;

        while (!q.empty() && ans == "yes")
        {
            vector<int> t = q.front();
            int h = head.front();
            q.pop();
            head.pop();
            // cout << "round: " << r << endl;
            r += 1;
            // cout << "head: " << h << endl;
            for (auto a : t)
            {

                // cout << "a: " << a << endl;
                // cout<<"visit[a]: "<<visit[a]<<endl;
                // cout<<"a: "<<a<<endl;
                if (visit[a] == 0)
                {
                    // cout << "in" << endl;
                    if (visit[h] == 1)
                    {
                        // cout << "h=1" << endl;
                        visit[a] = 2;
                        q.push(Graph[a]);

                        head.push(a);
                    }
                    else if (visit[h] == 2)
                    {
                        // cout << "h=2" << endl;
                        visit[a] = 1;
                        q.push(Graph[a]);
                        head.push(a);
                    }
                }
                // cout << "visit[h]: " << visit[h] << endl;
                // cout << "visit[a]: " << visit[a] << endl;
                // cout << endl;
                if ((visit[h] == 1 && visit[a] == 1) || (visit[h] == 2 && visit[a] == 2))
                {
                    ans = "no";
                }
            }
            // cout << ans << endl;
        }
        if (ans == "yes")
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int k;
    int n, m;
    cin >> n >> m >> k;
    vector<int> Graph[n];
    int deg[n];
    vector<pair<int, int>> edge;
    for (int j = 0; j < m; j++)
    {
        int u, v;
        cin >> u >> v;
        edge.push_back({u - 1, v - 1});
        deg[u - 1]++;
        deg[v - 1]++;
    }
    int m_deg[n];
    for (int i = 0; i < n; i++)
    {
        if (deg[i] >= k)
        {
            m_deg[i] = 1;
        }
        else
        {
            m_deg[i] = 0;
        }
    }
    for (auto a : edge)
    {
        if (m_deg[a.first] || m_deg[a.second])
        {
            continue;
        }
        else
        {
            Graph[a.first].push_back(a.second);
            Graph[a.second].push_back(a.first);
        }
    }
    if (isBipartite(Graph,n))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}

/*
5 6 4
1 2
1 3
1 4
1 5
2 3
4 5
*/

/*
6 10 4
1 2
1 3
1 4
1 5
1 6
2 3
3 4
4 5
5 6
6 2
*/