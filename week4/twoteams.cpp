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

        while (!q.empty() && ans == "yes")
        {
            vector<int> t = q.front();
            int h = head.front();
            q.pop();
            head.pop();
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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> Graph[m][n];

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[i][a - 1].push_back(b - 1);
        Graph[i][b - 1].push_back(a - 1);
        // if(isBipartite(Graph,n)){
        //     ans+=1;
        // }
    }
    int l = 0, r = m - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (isBipartite(Graph[mid], n))
        {
            ans += mid - l;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << ans << "\n";
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