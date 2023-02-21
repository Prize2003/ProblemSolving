#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> Graph[n];
    int in[n] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        in[v - 1] += 1;
        Graph[u - 1].push_back(v);
    }
    // cout << endl;
    // cout << "Graph:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << ": ";
    //     for (auto a : Graph[i])
    //     {
    //         cout << a << " ";
    //     }
    //     cout << "in: " << in[i];
    //     cout << endl;
    // }
    // cout << endl;
    vector<int> ans;
    int found = 1;
    int mistake=0;
    int c=0;

    while (found)
    {
        vector<vector<int>> de;
        found = 0;
        int mis = 1;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                mis = 0;
            }
        }
        // cout<<mis<<endl;
        if (mis&c!=n)
        {
            mistake=1;
            break;
        }
        for (int i = 0; i < n; i++)
        {

            if (in[i] == 0)
            {
                found = 1;
                c+=1;
                ans.push_back(i + 1);
                in[i] = -1;
                de.push_back(Graph[i]);
            }
        }
        for (auto a : de)
        {
            for (auto b : a)
            {
                in[b - 1] -= 1;
            }
        }
    }
    if (mistake)
    {
        cout << "no";
    }
    else
    {
        for (auto a : ans)
        {
            cout << a << endl;
        }
    }
}

// 4 4
// 1 2
// 1 4
// 3 4
// 2 4