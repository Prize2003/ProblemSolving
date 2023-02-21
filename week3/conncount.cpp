#include <bits/stdc++.h>

using namespace std;

int bfs(vector<int> node[], int n)
{
    queue<int> q;
    int visit[n] = {0};
    int p = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(visit[i]==1) continue;
        ans++;
        q.push(i);
        visit[i] = 1;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto a : node[t])
            {
                if (visit[a] == 0)
                {
                    visit[a] = 1;
                    q.push(a);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, m, a, b, ans;
    cin >> n >> m;
    vector<int> node[n];
    for (int i = 0; i < n; i++)
    {
        // node[i].push_back(i+1);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        node[a - 1].push_back(b - 1);
        node[b - 1].push_back(a - 1);
    }
    ans = bfs(node, n);
    cout << ans;

    // for(auto a:node){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
}
