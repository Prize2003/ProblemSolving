#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> Graph[], int n)
{
    int visit[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (visit[i])
        {
            continue;
        }
        string ans = "yes";
        queue<vector<int>> q;
        q.push(Graph[i]);
        visit[i] = 1;
        queue<int> head;
        head.push(i);
        int r = 1;

        while (!q.empty() && ans == "yes")
        {
            vector<int> t = q.front();
            int h = head.front();
            q.pop();
            head.pop();
            // cout << "round: " << r << endl;
            r += 1;
            // cout << "head: " << h << endl;
            for (auto a : t)
            {

                // cout << "a: " << a << endl;
                // cout<<"visit[a]: "<<visit[a]<<endl;
                // cout<<"a: "<<a<<endl;
                if (visit[a] == 0)
                {
                    // cout << "in" << endl;
                    if (visit[h] == 1)
                    {
                        // cout << "h=1" << endl;
                        visit[a] = 2;
                        q.push(Graph[a]);

                        head.push(a);
                    }
                    else if (visit[h] == 2)
                    {
                        // cout << "h=2" << endl;
                        visit[a] = 1;
                        q.push(Graph[a]);
                        head.push(a);
                    }
                }
                // cout << "visit[h]: " << visit[h] << endl;
                // cout << "visit[a]: " << visit[a] << endl;
                // cout << endl;
                if ((visit[h] == 1 && visit[a] == 1) || (visit[h] == 2 && visit[a] == 2))
                {
                    ans = "no";
                }
            }
            // cout << ans << endl;
        }
        if (ans == "yes")
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

pair<int, int> match[200000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        match[i] = {a - 1, b - 1};
    }
    // vector<int> Graph[n];
    // for (int i = 0; i < 1; i++)
    // {
    //     Graph[match[i].first].push_back(match[i].second);
    //     Graph[match[i].second].push_back(match[i].first);
    // }
    // bool ck = isBipartite(Graph, n);
    // cout << ck;
    int l = 0, r = m - 1;
    int mid = (l + r) / 2;
    // cout<<mid;
    int br = 1;
    while (br)
    {
        mid = (l + r) / 2;
        vector<int> Graph[n];
        for (int i = 0; i <= mid; i++)
        {
            Graph[match[i].first].push_back(match[i].second);
            Graph[match[i].second].push_back(match[i].first);
        }
        vector<int> fGraph[n];
        if (mid + 1 < m)
        {
            for (int i = 0; i <= mid + 1; i++)
            {
                fGraph[match[i].first].push_back(match[i].second);
                fGraph[match[i].second].push_back(match[i].first);
            }
            bool ck1 = isBipartite(Graph, n);
            bool ck2 = isBipartite(fGraph, n);
            if (ck1 && !ck2)
            {
                br = 0;
            }
            else
            {
                if (ck1)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
        }
        else{
            mid=m-1;
            br=0;
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << "i: " << i + 1 << "\n";
        //     for (auto a : Graph[i])
        //     {
        //         cout << a + 1 << " ";
        //     }
        //     cout << endl;
        // }
    }
    cout << mid + 1 << "\n";
}

/*
3 3
1 2
2 3
3 1
*/

/*
5 7
1 2
2 3
3 4
4 1
4 5
5 2
5 1
*/

/*
5 2
1 2
4 5
*/