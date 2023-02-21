#include <bits/stdc++.h>

using namespace std;

int village = 1;
int mainvillage[100000];

void MagicVillage(vector<pair<int, int>> Graph[], int n, int start, int hp)
{
    // cout << endl;
    queue<int> q;
    int visit[n] = {0};
    q.push(start);
    visit[start] = 1;
    int status[n] = {0};
    int HP[n] = {0};
    HP[start] = hp;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for (auto a : Graph[t])
        {
            if (status[t] == 1)
            {
                status[a.first] = 1;
            }
            if (visit[a.first] == 0 && HP[t] > 0)
            {
                visit[a.first] = 1;
                
                HP[a.first] = HP[t] - 1;
                q.push(a.first);
                if (a.second == 1)
                {
                    status[a.first] = 1;
                }
                if (status[a.first] == 1&&mainvillage[a.first]==0)
                {
                    // cout << a.first << endl;
                    village += 1;
                    
                }
                mainvillage[a.first]=1;
               
            }
        }
    }
    // cout<<endl;
    // cout << village << endl;
}

void bfs(vector<pair<int, int>> Graph[], int magic[], int n, int h)
{
    queue<int> q;
    int visit[n] = {0};
    q.push(0);
    visit[0] = 1;
    int HP[n] = {0};
    HP[0] = h;
    mainvillage[0]=1;
    
    int PassMagicVillage[n] = {};
    if(magic[0]==1){
        PassMagicVillage[0] = HP[0];
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto a : Graph[t])
        {
            if (visit[a.first] == 0 && a.second == 0 && HP[t] > 0)
            {
                visit[a.first] = 1;
                mainvillage[a.first]=1;
                HP[a.first] = HP[t] - 1;
                village += 1;
                q.push(a.first);
                if (magic[a.first] == 1)
                {
                    PassMagicVillage[a.first] = HP[a.first];
                }
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "HP: " << PassMagicVillage[i] << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        if (PassMagicVillage[i] > 0)
        {
            MagicVillage(Graph, n, i, PassMagicVillage[i]);
        }
    }
    cout<<village<<endl;
}

int main()
{
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    int magic[n] = {0};
    for (int i = 0; i < k; i++)
    {
        int mg;
        cin >> mg;
        magic[mg - 1] = 1;
    }

    vector<pair<int, int>> Graph[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graph[a - 1].push_back({b - 1, c});
        Graph[b - 1].push_back({a - 1, c});
    }
    // for (int i = 0; i < k; i++)
    // {
    //     cout << "magic[mg-1]: " << magic[i] << endl;
    // }
    bfs(Graph, magic, n, h);
}
// 6 5 0 2
// 1 2 0
// 3 2 0
// 4 1 0
// 4 5 0
// 5 6 0

// 7 7 1 3
// 2
// 1 2 0
// 7 1 1
// 1 3 0
// 3 4 0
// 4 5 0
// 6 5 0
// 3 6 1

// 7 7 1 3
// 1
// 1 2 1
// 7 1 1
// 1 3 1
// 3 4 1
// 4 5 1
// 6 5 1
// 3 6 1

// 7 7 1 1000000
// 2
// 1 2 0
// 7 1 1
// 1 3 0
// 3 4 0
// 4 5 0
// 6 5 0
// 3 6 1

// 7 7 1 3
// 2
// 1 2 0
// 7 1 1
// 1 3 1
// 3 4 1
// 4 5 1
// 6 5 1
// 3 6 1