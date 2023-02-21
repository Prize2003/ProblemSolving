#include <bits/stdc++.h>

using namespace std;

char maze[100][100];
int dig[100][100];
int distanced[100][100];
int visited[100][100];

int bfs(int r, int c, pair<int, int> start, pair<int, int> finish, int st_row, int st_column)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            visited[i][j] = 0;
            dig[i][j] = 0;
            distanced[i][j] = 10000000;
        }
    }
    distanced[start.first][start.second] = 0;
    visited[start.first][start.second] = 1;
    // maze[start.second][start.first] = 'S';
    // maze[finish.first][finish.second] = 'F';
    q.push({start.first, start.second});
    int wrong = 1;
    // maze[start.second][start.first] = 'x';
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int row = t.first;
        int column = t.second;
        // cout << endl;
        // cout << "row: " << row << " column: " << column << endl;
        // cout <<"dis: "<< distanced[row][column] << endl;
        if (row == finish.first && column == finish.second) // meet finish point break.
        {
            wrong = 0;
            // cout << "meet" << endl;
            break;
        }
        if (row != r - 1 && maze[row + 1][column] != '#' && visited[row + 1][column] == 0)
        {
            // cout << "S" << endl;
            if ((row + 1 != st_row || column != st_column) && maze[row + 1][column] == '.')
            {
                // cout<<"S"<<endl;
                distanced[row + 1][column] = distanced[row][column] + 1;
                visited[row + 1][column] = 1;
                // maze[row + 1][column] = 'x';
                q.push({row + 1, column});
            }
            else if (row + 1 == st_row && column == st_column && row != r - 2 && maze[row + 2][column] == '.')
            {
                distanced[row + 1][column] = distanced[row][column] + 1;
                visited[row + 1][column] = 1;
                // maze[row + 1][column] = 'x';
                q.push({row + 1, column});
            }
        }
        if (row != 0 && maze[row - 1][column] != '#'  && visited[row - 1][column] == 0)
        {
            // cout << "N" << endl;
            if ((row - 1 != st_row || column != st_column) && maze[row - 1][column] == '.')
            {
                distanced[row - 1][column] = distanced[row][column] + 1;
                visited[row - 1][column] = 1;
                // maze[row - 1][column] = 'x';
                q.push({row - 1, column});
            }
            else if (row - 1 == st_row && column == st_column && row > 1 && maze[row - 2][column] == '.')
            {
                distanced[row - 1][column] = distanced[row][column] + 1;
                visited[row - 1][column] = 1;
                // maze[row - 1][column] = 'x';
                q.push({row - 1, column});
            }
        }
        if (column != c - 1 && maze[row][column + 1] != '#' && visited[row][column + 1] == 0)
        {
            // cout << "E" << endl;
            if ((row != st_row || column + 1 != st_column) && maze[row][column + 1] == '.')
            {
                distanced[row][column + 1] = distanced[row][column] + 1;
                visited[row][column + 1] = 1;
                // maze[row][column + 1] = 'x';
                q.push({row, column + 1});
            }
            else if (row == st_row && column + 1 == st_column && column != c - 2 && maze[row][column + 2] == '.')
            {
                distanced[row][column + 1] = distanced[row][column] + 1;
                visited[row][column + 1] = 1;
                // maze[row][column + 1] = 'x';
                q.push({row, column + 1});
            }
        }
        if (column != 0 && maze[row][column - 1] != '#'  && visited[row][column - 1] == 0)
        {
            // cout << "W" << endl;
            if ((row != st_row || column - 1 != st_column) && maze[row][column - 1] == '.')
            {
                distanced[row][column - 1] = distanced[row][column] + 1;
                visited[row][column - 1] = 1;
                // maze[row][column - 1] = 'x';
                q.push({row, column - 1});
            }
            else if (row == st_row && column - 1 == st_column && column > 1 && maze[row][column - 2] == '.')
            {
                distanced[row][column - 1] = distanced[row][column] + 1;
                visited[row][column - 1] = 1;
                // maze[row][column - 1] = 'x';
                q.push({row, column - 1});
            }
        }
    }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << maze[i][j];
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << distanced[i][j]<<" ";
    //     }
    //     cout<<endl;
    //     // if (wrong)
    //     // {
    //     //     cout << -1 << endl;
    //     // }
    //     // else
    //     // {
    //     //     cout << distanced[finish.second][finish.first] << endl;
    //     // }
    // }
    return distanced[finish.first][finish.second];
}

int main()
{
    int r, c;
    cin >> r >> c;
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    pair<int, int> start = {a - 1, b - 1};
    pair<int, int> finish = {x - 1, y - 1};
    queue<pair<int, int>> star;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '*')
            {
                star.push({i, j});
            }
        }
    }
    int mn = 10000000;
    while (!star.empty())
    {
        pair<int, int> t = star.front();
        star.pop();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == t.first && j == t.second)
                {
                    int pmn;
                    maze[i][j] = '.';
                    // cout << "i: " << i << " j: " << j << endl;
                    pmn = bfs(r, c, start, finish, i, j);
                    // cout << "pmn: " << pmn << endl;
                    if (pmn < mn)
                    {
                        mn = pmn;
                        // cout << "mn: " << mn << endl;
                    }
                    maze[i][j] = '*';
                }
            }
        }
    }
    if (mn == 10000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mn << endl;
    }
}

/*
6 5
2 2 4 2
#####
#...#
#**.#
#.*.#
#...#
#####
*/

/*
6 5
2 2 4 2
#####
#...#
#.*.#
#.*.#
#...#
#####
*/

/*
6 5
2 2 5 2
#####
#...#
#***#
#***#
#...#
#####
*/

/*
6 5
2 2 5 4
#####
#...#
#.###
#*..#
###.#
#####
*/

/*
40 40
2 2 39 2
########################################
#..................##..................#
#..................##..................#
#*################.##*################.#
#.#................##.#................#
#.#######*########.##.#######*########.#
#.#................##.#................#
#.#.#################.#.################
#.#................##.#................#
#.#######*########.##.#######*########.#
#.#................##.#................#
#.#.#################.#.################
#.#................##.#................#
#.#########*######.##.#########*######.#
#.#................##.#................#
#.#.#################.#.################
#.#................##.#................#
#.################.##.################.#
#......................................#
######################################.#
######################################.#
#..................##..................#
#..................##..................#
#*################.##*################.#
#.#................##.#................#
#.#######*########.##.#######*########.#
#.*................##.#................#
#.#.#################.#.################
#.#................##.#................#
#.#######*########.##.#######*########.#
#.#................##.#................#
#.#.#################.#.################
#.#................##.#................#
#.#########*######.##.#########*######.#
#.#................##.#................#
#.#.#################.#.################
#.#................##.#................#
#.################.##.################.#
#................#.....................#
########################################
*/