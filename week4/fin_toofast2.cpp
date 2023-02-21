#include <bits/stdc++.h>

using namespace std;

int visited[150000][2];

void dijktra(vector<pair<int, pair<int, int>>> Graph[], int n)
{

    set<pair<int, pair<int, int>>> pq;
    pq.insert({0, {0, 0}});
    for (int i = 0; i < n; i++)
    {
        visited[i][0] = 0;
        visited[i][1] = 0;
    }
    int distance[n][2];
    for (int i = 0; i < n; i++)
    {
        distance[i][0] = 150000;
        distance[i][1] = 150000;
    }
    distance[0][0] = 0;
    int wrong = 1;
    // int ex[n] = {0};
    while (!pq.empty())
    {
        pair<int, pair<int, int>> t = *pq.begin();
        pq.erase(*pq.begin());
        if (t.second.first == n - 1)
        {
            wrong = 0;
        }

        if(visited[t.second.first][t.second.second]==1){
            continue;
        }
        visited[t.second.first][t.second.second] = 1;

        
        // cout << "node :" << t.second.first <<" status: "<<t.second.second<< " dis: "<<t.first<<endl;
        for (auto a : Graph[t.second.first])
        {
            int weigth = a.first;
            int node = a.second.first;
            int express = a.second.second;
            // if (t.second.second == 1)
            // {
            //     express = 0;
            // }
            // if (visit[node] == 0)
            // {
            if (visited[node][t.second.second] == 0)
            {
                if (t.second.second == 0 )
                {
                    // cout<<"a"<<endl;
                    if (express == 0&& (distance[node][0] > distance[t.second.first][0] + weigth))
                    {
                        // visit[node] = 1;
                        // cout<<"asf: "<<node<<endl;
                        distance[node][0] = distance[t.second.first][0] + weigth;
                        pq.insert({distance[node][0], {node, 0}});
                    }
                    else if (express == 1&& (distance[node][1] > distance[t.second.first][0] + weigth))
                    {
                        // cout << "asf: " << node << endl;

                        // visit[node] = 1;
                        distance[node][1] = distance[t.second.first][0] + weigth;
                        pq.insert({distance[node][1], {node, 1}});
                        // pq.insert({distance[t.second.first], {node,0}});
                    }
                    // }
                }
                else if (t.second.second == 1 && (distance[node][1] > distance[t.second.first][1] + weigth) && express == 0)
                {
                    // cout<<"b"<<endl;
                    distance[node][1] = distance[t.second.first][1] + weigth;
                    pq.insert({distance[node][1], {node, 1}});
                }
            }
            // else if(t.second.second==1){
            //     distance[node] = distance[t.second.first] + weigth;
            //     pq.insert({distance[node], {node,0}});
            // }
        }
    }
    // cout<<endl;
    // cout<<"ans: "<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout <<distance[i][0] <<" "<< distance[i][1]<< endl;
    // }
    // cout << distance[n - 1];
    if (!wrong)
    {
        if (distance[n - 1][0] < distance[n - 1][1])
        {
            cout << distance[n - 1][0];
        }
        else
        {
            cout << distance[n - 1][1];
        }
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
    vector<pair<int, pair<int, int>>> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c, s;
        cin >> a >> b >> c >> s;
        Graph[a - 1].push_back({c, {b - 1, s}});
        Graph[b - 1].push_back({c, {a - 1, s}});
    }
    dijktra(Graph, n);
}
/*
4 5
1 2 10 0
1 3 20 0
3 4 5 0
4 2 7 0
2 3 12 0
*/

/*
5 6
1 2 10 0
2 3 10 0
1 3 5 1
3 4 10 0
4 5 10 0
3 5 4 1
*/

/*
5 4
1 2 10 0
2 3 10 1
3 4 10 0
4 5 10 1
*/

