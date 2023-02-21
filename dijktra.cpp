#include <bits/stdc++.h>

using namespace std;

void bfs(vector<pair<int, int>> Graph[], int n)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    int path[n] = {100000000};
    for (int i = 0; i < n; i++)
    {
        path[i] = 10000000;
    }
    path[0] = 0;
    vector<pair<int, int>> nsure;
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int mn = 1000000;
        for (auto a : Graph[t.first])
        {
            if (path[a.first] >a.second + t.second)
            {
                path[a.first] = a.second + t.second;
                q.push({a.first, a.second + t.second});
            }       
        }
    }
    cout << path[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Graph[a - 1].push_back({b - 1, w});
        Graph[b - 1].push_back({a - 1, w});
    }
    bfs(Graph, n);
}