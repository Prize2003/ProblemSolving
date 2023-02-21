#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int name;
    int idx;
};

void bfs(vector<int> Graph[], int n)
{
    string ans = "yes";
    queue<vector<int>> q;
    int visit[n] = {0};
    q.push(Graph[0]);
    visit[0] = 1;
    queue<int> head;
    head.push(0);
    int r = 1;

    while (!q.empty() && ans == "yes")
    {
        vector<int> t = q.front();
        int h = head.front();
        q.pop();
        head.pop();
        // cout << "round: " << r << endl;
        // r += 1;
        // cout << "head: " << h << endl;
        for (auto a : t)
        {

            // cout << "a: " << a << endl;
            // cout<<"visit[a]: "<<visit[a]<<endl;
            // cout<<"a: "<<a<<endl;
            if (visit[a - 1] == 0)
            {
                // cout << "in" << endl;
                if (visit[h] == 1)
                {
                    // cout << "h=1" << endl;
                    visit[a - 1] = 2;
                    q.push(Graph[a - 1]);

                    head.push(a - 1);
                }
                else if (visit[h] == 2)
                {
                    // cout << "h=2" << endl;
                    visit[a - 1] = 1;
                    q.push(Graph[a - 1]);
                    head.push(a - 1);
                }
            }
            // cout << "visit[h]: " << visit[h] << endl;
            // cout << "visit[a-1]: " << visit[a - 1] << endl;
            if ((visit[h] == 1 && visit[a - 1] == 1) || (visit[h] == 2 && visit[a - 1] == 2))
            {
                ans = "no";
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<int> Graph[n];
        for (int j = 0; j < m; j++)
        {
            int u, v;
            cin >> u >> v;
            Graph[u - 1].push_back(v);
            Graph[v - 1].push_back(u);
        }
        // cout << "n:" << n << endl
        //      << endl;
        // cout << "Graph:" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << i + 1 << ": ";
        //     for (auto a : Graph[i])
        //     {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        bfs(Graph, n);
    }
}

/*
1
4 4
1 2
1 4
4 3
2 3
*/