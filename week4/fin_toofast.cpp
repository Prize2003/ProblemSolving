#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int b;
    int w;
    int s;
};

void bfs(vector<Node> Graph[], int n)
{
    queue<Node> q;
    q.push({0, 0, 0});
    int path[n][2];
    for (int i = 0; i < n; i++)
    {
        path[i][0] = 10000000;
        path[i][1] = 10000000;
    }
    path[0][0] = 0;
    int visit[n][2] = {0};
    while (!q.empty())
    {
        // for (int i = 0; i < n; i++)
        // {
        //     // cout << path[i][0] << " " << path[i][1] << " ";
        // }
        // cout << endl;
        Node t = q.front();
        // cout << "t: " << t.b << endl;
        q.pop();
        // cout << "No. " << t.b << " ";
        // cout << "wt: " << t.w << " ";
        for (auto &a : Graph[t.b])
        {
            // cout << "wa: " << a.w << " No. " << a.b << " ";
            if (path[a.b][0] > a.w + t.w)
            {
                // cout<<"l"<<endl;

                if (a.s == 0)
                {
                    path[a.b][0] = a.w + t.w;
                    // cout << "ts: " << t.s << endl;
                    // cout << "as: " << a.s << endl;
                    if (a.b != n - 1)
                    {
                        q.push({a.b, a.w + t.w, 0});
                    }
                }
                if (a.s == 1)
                {
                    path[a.b][1] = a.w + t.w;
                    // cout << "express\n";
                    if (a.b != n - 1)
                    {
                        q.push({a.b, a.w + t.w, 1});
                    }
                }
            }
            if (path[a.b][1] > a.w + t.w)
            {
                // cout<<"l"<<endl;
                if (t.s == 1 && a.s == 0)
                {
                    path[a.b][1] = a.w + t.w;
                    // cout << "ts: " << t.s << endl;
                    // cout << "as: " << a.s << endl;
                    if (a.b != n - 1)
                    {
                        q.push({a.b, a.w + t.w, a.s});
                    }
                }
            }
        }
    }

    if (path[n - 1][0] != 10000000 || path[n - 1][1] != 10000000)
    {
        cout << min(path[n - 1][0], path[n - 1][1]);
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Node> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, w, s;
        cin >> a >> b >> w >> s;
        Graph[a - 1].push_back({b - 1, w, s});
        Graph[b - 1].push_back({a - 1, w, s});
    }
    bfs(Graph, n);
}