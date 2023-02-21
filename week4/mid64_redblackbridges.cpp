#include <bits/stdc++.h>

using namespace std;

int visited[50000][3];
int dis[50000][3];

void bfs(vector<pair<int, int>> Graph[], int n, int s, int tt)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            visited[i][j] = 0;
            dis[i][j] = 0;
        }
    }
    visited[s][0] = 1;
    q.push({s, 0});
    int wrong = 1;
    // cout<<"tt: "<<tt+1<<endl;
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        // cout << "t: " << t.first + 1 << endl;
        // cout<<"tt: "<<tt<<endl;
        // cout << "dis: " << dis[t.first][0] << " " << dis[t.first][1] << " " << dis[t.first][2] << endl;
        if (tt == t.first)
        {
            // cout<<"k"<<endl;
            wrong = 0;
        }
        for (auto a : Graph[t.first])
        {

            // if (t.second==1)
            // {
            //     a.second=1;
            // }
            // else if (t.second == 2)
            // {
            //     a.second = 2;
            // }
            // cout<<a.second<<" "<<color[t][a.second]<<endl;
            // cout << a.first << " " << a.second << endl;
            if (t.second == 0 && visited[a.first][a.second] == 0)
            {
                // cout << "a1: " << a.first + 1 << endl;
                visited[a.first][a.second] = 1;
                q.push({a.first, a.second});
                dis[a.first][a.second] = dis[t.first][0] + 1;
            }
            else if ((a.second == t.second || a.second == 0) && visited[a.first][t.second] == 0)
            {
                // cout << "a2: " << a.first + 1 << endl;
                visited[a.first][t.second] = 1;
                q.push({a.first, t.second});
                dis[a.first][t.second] = dis[t.first][t.second] + 1;
            }
        }
        // cout << endl;
    }

    if (!wrong)
    {
        int mn = 10000000;
        for (int i = 0; i < 3; i++)
        {
            if (dis[tt][i] != 0 && dis[tt][i] < mn)
            {

                mn = dis[tt][i];
                // cout << mn<<endl;
            }
        }
        cout << mn;
        // cout << dis[tt][0] << " " << dis[tt][1] << " " << dis[tt][2];
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<pair<int, int>> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graph[a - 1].push_back({b - 1, c});
        Graph[b - 1].push_back({a - 1, c});
    }
    // cout<<endl;
    // cout<<"Graph:"<<endl;
    // int i=0;
    // for(auto a:Graph){
    //     cout<<i<<": ";
    //     for(auto b:a){
    //         cout<<b.first<<" ";
    //     }
    //     cout<<endl;
    //     i+=1;
    // }
    // cout<<endl;
    bfs(Graph, n, s - 1, t - 1);
}

/*
6 7 2 4
2 5 0
3 4 2
6 5 0
3 6 0
1 4 1
2 1 2
1 3 0
*/

/*
3 2 1 3
1 2 1
2 3 2
*/

/*
3 2 1 3
1 2 1
2 3 1
*/

/*
6 7 2 4
2 5 0
3 4 1
6 5 0
3 6 0
1 4 1
2 1 2
1 3 0
*/
