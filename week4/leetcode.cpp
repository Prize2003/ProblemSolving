#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &Graph)
    {
        for (int i = 0; i < Graph.size(); i++)
        {
            string ans = "yes";
            queue<vector<int>> q;
            int visit[100] = {0};
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
                cout << "round: " << r << endl;
                r += 1;
                cout << "head: " << h << endl;
                for (auto a : t)
                {

                    cout << "a: " << a << endl;
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
                    cout << "visit[h]: " << visit[h] << endl;
                    cout << "visit[a]: " << visit[a] << endl;
                    cout << endl;
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
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    if (Solution().isBipartite(graph))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}

/*
5 5
0 4
0 1
1 2
2 3
3 4
*/