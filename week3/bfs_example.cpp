#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
char Graph[100][100];
bool visited[100][100] = {{false}};
queue<pair<int, int>> q;

void dfs(int r, int c)
{
    Graph[r][c] = 'x';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Graph[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    
    int current_row = r;
    int current_col = c;
    visited[current_row][current_col] = true;
    if (current_row + 1 < n and (not visited[current_row + 1][current_col]))
    {
        dfs(r+1,c);
    }
    if (current_row - 1 >= 0 and (not visited[current_row - 1][current_col]))
    {
        dfs(r-1,c);
    }
    if (current_col + 1 < n and (not visited[current_row][current_col + 1]))
    {
        dfs(r,c+1);
    }
    if (current_col - 1 >= 0 and (not visited[current_row][current_col - 1]))
    {
        dfs(r,c-1);
    }
}

void bfs(int r, int c)
{
    int current_row = r, current_col = c;
    q.push({current_row, current_col});
    while (!q.empty())
    {
        // cout << q.front().first << " " << q.front().second << endl;
        current_row = q.front().first;
        current_col = q.front().second;
        Graph[current_row][current_col] = 'x';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << Graph[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        visited[current_row][current_col] = true;
        q.pop();
        if (current_row + 1 < n and (not visited[current_row + 1][current_col]))
        {
            visited[current_row + 1][current_col] = true;
            q.push({current_row + 1, current_col});
        }
        if (current_row - 1 >= 0 and (not visited[current_row - 1][current_col]))
        {
            visited[current_row - 1][current_col] = true;
            q.push({current_row - 1, current_col});
        }
        if (current_col + 1 < n and (not visited[current_row][current_col + 1]))
        {
            visited[current_row][current_col + 1] = true;
            q.push({current_row, current_col + 1});
        }
        if (current_col - 1 >= 0 and (not visited[current_row][current_col - 1]))
        {
            visited[current_row][current_col - 1] = true;
            q.push({current_row, current_col - 1});
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Graph[i][j];
        }
    }

    dfs(5, 5);

    return 0;
}