#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<int> Graph[], int n, int com1, int com2)
{
    int visit[n] = {0};
    queue<int> q;
    q.push(0);
    visit[0] = 1;
    int br = 1;
    while (!q.empty())
    {     
        int t = q.front();
        q.pop();
        for (auto a : Graph[t])
        {
            // cout<<"before\n";
            // cout<<"t: "<<t+1<<" a: "<<a+1<<endl;
            if ((t != com1 || a != com2) &&(t != com2 || a != com1))
            {
                // cout<<"after\n";
                // cout<<"t: "<<t+1<<" a: "<<a+1<<endl;
                
                // cout<<"before: visit[t]: "<<visit[t]<<" visit[a]: "<<visit[a]<<endl;
                
                if (visit[t] == 1 && visit[a] == 0)
                {
                    visit[a] = 2;
                    q.push(a);
                }
                else if (visit[t] == 2 && visit[a] == 0)
                {
                    visit[a] = 1;
                    q.push(a);
                }
                else if ((visit[t] == 1 && visit[a] == 1) || (visit[t] == 2 && visit[a] == 2))
                {
                    br = 0;
                }
                
            //    cout<<"after: visit[t]: "<<visit[t]<<" visit[a]: "<<visit[a]<<endl;
            }
            
        }
        // cout << "br: " << br << endl;
        // cout<<endl;
        if(br==0){
            break;
        }
    }
    // cout<<"total br: "<<br<<endl;
    return br;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> Graph[n];
    vector<pair<int, int>> ttt;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ttt.push_back({x - 1, y - 1});
        Graph[x - 1].push_back(y - 1);
        Graph[y - 1].push_back(x - 1);
    }
    // cout << "Graph: " << endl;
    // int v=1;
    // for (auto a : Graph)
    // {
    //     cout<<v<<": " ;
    //     for (auto b : a)
    //     {
    //         cout<< b +1<< " ";
    //     }
    //     v+=1;
    //     cout << endl;
    // }
    // cout << endl;
    bool bipartite = 0;
    pair<int, int> ans;
    for (int i = 0; i < m; i++)
    {

        // cout << "ttt[i].first: " << ttt[i].first+1 << endl
        //      << "ttt[i].second: " << ttt[i].second+1 << endl;
        bipartite = bfs(Graph, n, ttt[i].first, ttt[i].second);
        if (bipartite)
        {
            ans = ttt[i];
            break;
        }
        // cout << endl;
    }

    cout << ans.first + 1 << " " << ans.second + 1;
}
// 5 5
// 2 3
// 1 2
// 3 1
// 1 4
// 2 4

// 3 3
// 1 2
// 2 3
// 1 3