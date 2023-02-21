#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> Graph[], vector<pair<int, int>> hos_st, int n, int k, int h)
{
    queue<pair<int, pair<int, int>>> q;
    vector<int> meet;
    int vi[n] = {0};
    int walk[n][2] = {0};
    int visited[n][2] = {0};
    for (int i = 0; i < n; i++)
    {
        visited[i][0] = 0;
        visited[i][1] = 0;
        walk[i][0] = 0;
        walk[i][1] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        if (hos_st[i].second == 0)
        {
            visited[hos_st[i].first][0] = 1;
            q.push({hos_st[i].second, {hos_st[i].first, h}});
            meet.push_back(hos_st[i].first);
            vi[hos_st[i].first] = 1;
        }
        else
        {
            visited[hos_st[i].first][1] = 1;
            q.push({hos_st[i].second, {hos_st[i].first, h * 2}});
            meet.push_back(hos_st[i].first);
            vi[hos_st[i].first] = 1;
        }
    }
    int lnk = 0;
    while (!q.empty())
    {
        pair<int, pair<int, int>> t = q.front();
        q.pop();
        // cout<<"village: "<<t.first+1<<" HP: "<<t.second<<endl;
        // lnk+=1;
        for (auto a : Graph[t.second.first])
        {
            if (visited[a][t.first] == 0 && t.second.second >= walk[t.second.first][t.first] + 1)
            {
                visited[a][t.first] = 1;
                walk[a][t.first] = walk[t.second.first][t.first] + 1;
                q.push({t.first, {a, t.second.second}});
                if (vi[a] == 0)
                {
                    meet.push_back(a);
                    vi[a]=1;
                }
            }
        }
    }

    // cout << endl;
    for (int i = 0; i < meet.size(); i++)
    {
        // cout << meet[i] + 1 << endl;
        lnk+=1;
    }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout<<i+1<<": "<<walk[i][0]<<" "<<walk[i][1]<<endl;
    // }
    cout << lnk;
}

int main()
{
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    vector<int> hos;
    for (int i = 0; i < k; i++)
    {
        int hs;
        cin >> hs;
        hos.push_back(hs - 1);
    }
    vector<int> status;
    for (int i = 0; i < k; i++)
    {
        int st;
        cin >> st;
        status.push_back(st);
    }
    vector<pair<int, int>> hos_st;
    for (int i = 0; i < k; i++)
    {
        hos_st.push_back({hos[i], status[i]});
    }
    vector<int> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a - 1].push_back(b - 1);
        Graph[b - 1].push_back(a - 1);
    }
    bfs(Graph, hos_st, n, k, h);
}

/*
7 6 1 2
2
0
1 2
2 3
3 4
4 5
5 6
6 7
*/

/*
7 7 2 1
4 2
0 1
1 2
7 1
1 3
3 4
4 5
6 5
3 6
*/

/*
10 9 2 2
9 1
1 0
1 2
2 3
3 4
5 4
5 6
6 7
7 8
9 8
9 10
*/

/*
7 7 2 1
4 1
0 1
1 2
7 1
1 3
3 4
4 5
6 5
3 6
*/