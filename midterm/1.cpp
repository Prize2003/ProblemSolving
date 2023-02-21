#include <bits/stdc++.h>

using namespace std;

int country[50][50];
int visited[50][50];
int visa[50][50];

void bfs(int r, int c, pair<int, int> &start, pair<int, int> &finish)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            visited[i][j] = 0;
            visa[i][j] = 100000;
        }
    }
    q.push({start.first, start.second});
    visited[start.first][start.second] = 1;
    visa[start.first][start.second] = 0;
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int row = t.first;
        int column = t.second;
        // cout<<"row: "<<row<<" column: "<<column<<endl;
        // cout<<"visa: "<<visa[row][column]<<endl;
        // cout<<endl;
        if (row + 1 < r && visa[row + 1][column] > visa[row][column])
        {
            visited[row + 1][column] = 1;
            if (country[row + 1][column] != country[row][column])
            {
                if (visa[row + 1][column] > visa[row][column] + 1)
                {
                    visa[row + 1][column] = visa[row][column] + 1;
                    q.push({row + 1, column});
                }
            }
            else
            {
                visa[row + 1][column] = visa[row][column];
                q.push({row + 1, column});
            }
        }
        if (row - 1 >= 0 && visa[row - 1][column] > visa[row][column])
        {
            visited[row - 1][column] = 1;
            if (country[row - 1][column] != country[row][column])
            {
                if(visa[row-1][column] > visa[row][column] + 1)
                {
                    visa[row - 1][column] = visa[row][column] + 1;
                    q.push({row - 1, column});
                }
            }
            else
            {
                visa[row - 1][column] = visa[row][column];
                q.push({row - 1, column});
            }
        }
        if (column + 1 < c && visa[row][column + 1] > visa[row][column])
        {
            visited[row][column + 1] = 1;
            if (country[row][column + 1] != country[row][column])
            {
                if(visa[row][column + 1] > visa[row][column] + 1)
                {
                    visa[row][column + 1] = visa[row][column] + 1;
                    q.push({row, column + 1});
                }
            }
            else
            {
                visa[row][column + 1] = visa[row][column];
                q.push({row, column + 1});
            }
        }
        if (column - 1 >= 0 && visa[row][column - 1] > visa[row][column])
        {
            visited[row][column - 1] = 1;
            if (country[row][column - 1] != country[row][column])
            {
                if(visa[row][column - 1] > visa[row][column] + 1)
                {
                    visa[row][column - 1] = visa[row][column] + 1;
                    q.push({row, column - 1});
                }
            }
            else
            {
                visa[row][column - 1] = visa[row][column];
                q.push({row, column - 1});
            }
        }
    }
    // cout<<"finish: "<<finish.first<<" "<<finish.second<<endl;
    cout << visa[finish.first][finish.second];
}

int main()
{
    int r, c, a, b, x, y;
    cin >> r >> c >> a >> b >> x >> y;
    // cout<<r<<" "<<c<<" "<<a<<" "<<b<<" "<<x<<" "<<y;
    pair<int, int> start = {a - 1, b - 1};
    pair<int, int> finish = {x - 1, y - 1};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> country[i][j];
        }
    }
    bfs(r, c, start, finish);
    return 0;
}

/*
5 8 1 1 1 5
1 1 2 2 2 3 3 3
1 4 2 2 2 3 3 3
4 4 2 2 2 5 6 3
4 4 4 4 5 5 6 6
4 4 5 5 5 6 6 6
*/
/*
5 8 1 1 5 7
1 1 2 2 2 3 3 3
1 4 2 2 2 3 3 3
4 4 2 2 2 5 6 3
4 4 4 4 5 5 6 6
4 4 5 5 5 6 6 6
*/
/*
4 5 1 2 4 3
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
*/
/*
5 8 1 1 5 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1
*/

/*
5 8 1 1 5 4
1 1 2 2 2 3 3 3
1 4 2 2 2 3 3 3
4 4 2 2 2 5 6 3
4 4 4 4 5 5 6 6
4 4 5 5 5 6 6 6
*/

/*
5 8 1 1 5 6
1 1 2 2 2 6 6 3
1 4 2 2 2 3 6 3
4 4 2 2 2 5 6 3
4 4 4 4 5 5 6 6
4 4 5 5 5 6 6 6
*/