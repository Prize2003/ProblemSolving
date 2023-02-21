#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> ans;
    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
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
        vector<int> potoans;
        int found = 1;
        while (found)
        {
            vector<vector<int>> de;
            found = 0;
            for (int i = 0; i < n; i++)
            {

                if (in[i] == 0)
                {
                    found = 1;
                    potoans.push_back(i + 1);
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
        int c = 0;
        for (auto b : potoans)
        {
            if (c < potoans.size()-1)
            {
                cout << b << " ";
            }
            else
            {
                cout << b<<endl;
            }
            c+=1;
            
        }
        ans.push_back(potoans);
    }
    // for (auto a : ans)
    // {
    //     int c = 0;
    //     for (auto b : a)
    //     {
    //         if (c < a.size()-1)
    //         {
    //             cout << b << " ";
    //         }
    //         else
    //         {
    //             cout << b;
    //         }
    //         c+=1;
    //     }
    // }
    // cout<<endl;
}
// 2 1
// 1 2
// 2 1
// 2 1
// 0 0
