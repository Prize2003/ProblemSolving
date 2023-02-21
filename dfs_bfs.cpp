#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &v, int current, int *visited)
{
    cout << "DFS CURRENT : " << current + 1 << endl;
    visited[current] = 1;
    for (int i = 0; i < v[current].size(); i++)
    {
        if (not visited[v[current][i]])
        {
            dfs(v, v[current][i], visited);
        }
    }
}

void bfs(vector<vector<int>> &v, int start, int *visited)
{
    queue<int> q;
    int current;
    q.push(start);
    while (not q.empty())
    {
        current = q.front();
        cout << "BFS CURRENT : " << current + 1 << endl;
        visited[current] = 1;
        q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            if (not visited[v[current][i]])
            {
                visited[v[current][i]] = 1;
                q.push(v[current][i]);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v;
    int visited[n] = {0};
    v.resize(n);
    for (int i = 0; i < e; i++)
    {
        int f, t;
        cin >> f >> t;
        v[f - 1].push_back(t - 1);
    }
    // cout << v[0][0] << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1 << "->";
        for (int j = 0; j < v.at(i).size(); j++)
        {
            cout << v[i][j] + 1 << " ";
        }
        cout << endl;
    }
    dfs(v, 0, visited);
    int visited2[n] = {0};
    cout << endl;
    bfs(v, 0, visited2);
    return 0;
}

/*
10 23
1 2
1 5
2 4
2 5
2 8
3 4
3 8
3 9
4 2
4 3
5 1
5 10
7 5
7 8
7 10
8 2
8 3
8 7
8 9
9 3
9 8
10 5
10 7
 */
