#include <bits/stdc++.h>

using namespace std;

void shortestpath(vector<int> Graph[], int n,vector<int> start,vector<int> finish)
{
    queue<int> q;
    int visit[n] = {0};
    int distance[n] = {0};
    for(auto a: start){
        q.push(a);
        visit[a] = 1;
    }
    // if (start == finish)
    // {
    //     // cout<<"l";
    //     cout<< 0;
    // }
    while (!q.empty())
    {
        int t = q.front();
        // cout<<"t: ";
        // cout<<t+1<<endl;
        // cout<<endl;
        q.pop();
        // cout<<"finish: "<<finish+1<<endl;
        for (auto a : Graph[t])
        {

            if (visit[a] == 0)
            {
                visit[a] = 1;
                q.push(a);
                distance[a] = distance[t] + 1;
            }
        }
    }
    for(auto a:finish){
        cout<<distance[a]<<endl;
    }
    // cout<<"distance[finish]: "<<distance[finish]<<endl;
}

// cout<<distance[finish]<<endl;


int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a - 1].push_back(b - 1);
        Graph[b - 1].push_back(a - 1);
    }
    vector<int> store;
    for (int i = 0; i < s; i++)
    {
        int c;
        cin >> c;
        store.push_back(c - 1);
    }
    vector<int> factory;
    for (int i = 0; i < t; i++)
    {
        int f;
        cin >> f;
        factory.push_back(f - 1);
    }
    shortestpath(Graph, n,store,factory);
    // for (auto a : factory)
    // {
    //     int mn = 100000000;
    //     for (auto b : store)
    //     {
    //         int dis;
    //         dis = shortestpath(Graph, n, b, a);

    //         if (dis < mn)
    //         {
    //             mn = dis;
    //             // cout<<"mn: "<<mn<<endl;
    //         }
    //     }
    //     cout << mn << endl;
    // cout<<endl;
    // }
}
// 8 9 3 5
// 1 3
// 2 3
// 3 4
// 4 5
// 2 5
// 4 6
// 5 6
// 7 5
// 8 7
// 1 2 8
// 1 6 5 4 7