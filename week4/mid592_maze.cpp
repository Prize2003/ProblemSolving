#include <bits/stdc++.h>

using namespace std;

int visited[25][25];
int key[25][25];
char Graph[100][100];

struct Node
{
    int first, second, key;
};

string bfs(int n, pair<int, int> start, pair<int, int> finish)
{
    queue<Node> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
            key[i][j] = 0;
        }
    }
    // string test = "#";
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = 1;
    string ans = "no";
    while (!q.empty())
    {
        Node t = q.front();
        q.pop();
        int row = t.first;
        int column = t.second;
        // cout << endl;
        // for (int k=0;k<Graph->size();k++)
        // {
        //     for (auto b : Graph[k])
        //     {
        //         cout << b;
        //     }
        //     cout << endl;
        // }
        // cout<<"l"<<endl;

        // cout << endl;
        // cout << "row: " << row << " column: " << column << " key: " << t.key << endl;
        if (row == finish.first && column == finish.second)
        {
            ans = "yes";
            break;
        }
        if (row != n - 1 && Graph[row + 1][column] != '#' && visited[row + 1][column] == 0)
        {

            // cout << "S" << endl;
            // cout<<Graph[row + 1][column]<<endl;
            if (Graph[row + 1][column] == 'O')
            {
                // cout << "key S: " << key[row + 1][column] << endl;
                t.key++;
                if (t.key <= 1)
                {
                    q.push({row + 1, column, t.key});
                }
            }
            // else if (Graph[row + 1][column] == 'O' &&t.key == 1)
            // {
            //     t.key++;
            //     q.push({row + 1, column, t.key});
            // }
            else
            {
                q.push({row + 1, column, t.key});
            }
            visited[row + 1][column] = 1;
        }
        if (row != 0 && Graph[row - 1][column] != '#' && visited[row - 1][column] == 0)
        {
            // cout << "N" << endl;

            if (Graph[row - 1][column] == 'O')
            {
                // cout << "key N: " << key[row - 1][column] << endl;
                t.key++;
                if (t.key <= 1)
                {
                    q.push({row - 1, column, t.key});
                }
            }
            // else if (Graph[row - 1][column] == 'O' && t.key == 1)
            // {
            //     t.key++;
            //     q.push({row - 1, column, t.key});
            // }
            else
            {
                q.push({row - 1, column, t.key});
            }
            visited[row - 1][column] = 1;
        }
        if (column != n - 1 && Graph[row][column + 1] != '#' && visited[row][column + 1] == 0)
        {
            // cout << "E" << endl;
            if (Graph[row][column + 1] == 'O' )
            {
                // cout << "key E: " << key[row][column + 1] << endl;
                t.key++;
                if (t.key <= 1)
                {
                    q.push({row, column + 1, t.key});
                }
            }
            // else if (Graph[row][column + 1] == 'O' && t.key == 1)
            // {
            //     t.key++;
            //     q.push({row, column + 1, t.key});
            // }
            else
            {
                q.push({row, column + 1, t.key});
            }
            visited[row][column + 1] = 1;
        }
        if (column != 0 && Graph[row][column - 1] != '#' && visited[row][column - 1] == 0)
        {
            // cout << "W" << endl;
            if (Graph[row][column - 1] == 'O')
            {
                // cout << "key W: " << key[row][column - 1] << endl;
                t.key++;
                if (t.key <= 1)
                {
                    q.push({row, column - 1, t.key});
                }
            }
            // else if (Graph[row][column - 1] == 'O' && t.key == 1)
            // {
            //     t.key++;
            //     q.push({row, column - 1, t.key});
            // }
            else
            {
                // cout<<column - 1<<endl;
                q.push({row, column - 1, t.key});
            }
            visited[row][column - 1] = 1;
        }
    }
    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Graph[i][j];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;
        pair<int, int> start;
        start.first = sx - 1;
        start.second = sy - 1;
        pair<int, int> finish;
        finish.first = fx - 1;
        finish.second = fy - 1;
        string ans;
        ans = bfs(n, start, finish);
        cout << ans << endl;
    }
    // cout<<endl;
    // for(auto a:Graph){
    //     for ( auto b:a)
    //     {
    //         cout<<b;
    //     }
    //    cout<<endl;
    // }
}
/*
6 2
...#.#
.###.#
......
####.#
..#..#
...#..
1 3 5 5
1 5 5 1
*/

/*
7 4
#.#....
..#####
#......
#.#O###
#.#..#.
#.##O##
#.#....
2 1 3 7
2 1 5 4
2 1 1 6
2 1 7 6
*/

/*
20 1
....................
##############.#####
....................
.###################
....................
############.#######
....................
#####.#.#.##########
....................
################.###
....................
#.##################
....................
##################O#
....................
######O######.######
....................
OOOOOOOOOOOOOOOOOOOO
....................
O##################.
1 1 20 20
*/

/*
20 1
#..................#
##############O#####
#..................#
##############.#####
#..................#
############.#######
#..................#
#####.#.#.##########
#..................#
################.###
#..................#
#.##################
#..................#
####.#############O#
#..................#
######O######.######
#..................#
#OOOOOOOOOOOOOO.OOOO
#..................#
####################
1 2 19 19
*/