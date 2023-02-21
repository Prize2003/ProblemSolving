#include <bits/stdc++.h>

using namespace std;

int visited[1000][1000];

void bfs(vector<int> Graph[], int n, int power)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    int ans = 0;
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int i = t.first;
        int j = t.second;
        if (i == n - 1 && j == n - 1)
        {
            ans = 1;
            break;
        }

        if (i != n - 1 && Graph[i + 1][j] - Graph[i][j] <= power && visited[i + 1][j] == 0)
        {
            visited[i + 1][j] = 1;
            q.push({i + 1, j});
        }
        if (i != 0 && Graph[i - 1][j] - Graph[i][j] <= power && visited[i - 1][j] == 0)
        {
            visited[i - 1][j] = 1;
            q.push({i - 1, j});
        }
        if (j != n - 1 && Graph[i][j + 1] - Graph[i][j] <= power && visited[i][j + 1] == 0)
        {
            visited[i][j + 1] = 1;
            q.push({i, j + 1});
        }
        if (j != 0 && Graph[i][j - 1] - Graph[i][j] <= power && visited[i][j - 1] == 0)
        {
            visited[i][j - 1] = 1;
            q.push({i, j - 1});
        }
        // int di1[4] = {0,0,1,-1};
        // int di2[4] = {-1,1,0,0};
        // for(int k=0;k<4;k++){
        //     int u = i+di1[k];
        //     int v = j+di2[k];
        //     if(u<0 || v <0 || u>=n || v>=n)
        //     {
        //         continue;
        //     }
        //     if(visit[u][v] == 0 && Graph[u][v]-Graph[i][j]<=power)
        //     {
        //         visit[u][v] = 1;
        //         q.push(make_pair(u,v));
        //     }
        // }
    }

    if (ans)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> Graph[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            Graph[i].push_back(a);
        }
    }
    bfs(Graph, n, k);
    // cout<<endl;
    // for(auto a:Graph){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
}
/*
4 20
10 15 45 20
20 6 46 13
50 36 12 72
40 40 24 4
*/

/*
4 30
10 15 45 20
20 6 46 13
50 36 12 72
40 40 24 4
*/
/*
4 30
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/
/*
4 0
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 0
*/
/*
4 30
31 31 1 32
1 1 1 32
32 32 32 31
31 31 31 31
*/