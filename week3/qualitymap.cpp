#include <bits/stdc++.h>

using namespace std;

int n, m;
int lv1 = 0, lv2 = 0;
vector<string> mp;
int visi[100][100] = {{0}};

struct location
{
    int c;
    int r;
};

void bfs(vector<string> mp, int n1, int m1)
{
    if(visi[n1][m1]){
        return;
    }
    int mission = 1;
    char ps = mp[n1][m1];
    queue<location> q;
    int count = 0;
    int columm = m1, row = n1;

    location st;
    location nnode;
    st.c = m1;
    st.r = n1;
    q.push(st);
    visi[n1][m1] = 1;
    // int r = 0;
    // cout << curx << " " << cury << endl;   
    while (!q.empty())
    {

        int cur_columm = q.front().c;
        int cur_row = q.front().r;
        // cout << curx << " " << cury << endl;
        visi[cur_row][cur_columm] = 1;
        if (ps == '*' && mp[cur_row][cur_columm] == '$')
        {
            mission = 2;
        }
        else if (ps == '$' && mp[cur_row][cur_columm] == '*')
        {
            mission = 2;
        }
        mp[cur_row][cur_columm] = 'x';
        
        q.pop();

        if (visi[cur_row + 1][cur_columm] == 0 && cur_row + 1 < n && mp[cur_row + 1][cur_columm] != '#')
        {

            visi[cur_row + 1][cur_columm] = 1;
            nnode.c = cur_columm;
            nnode.r = cur_row + 1;
            q.push(nnode);
        }
        if (visi[cur_row][cur_columm - 1] == 0 && cur_columm - 1 >= 0 && mp[cur_row][cur_columm - 1] != '#')
        {
            visi[cur_row][cur_columm - 1] = 1;
            nnode.c = cur_columm - 1;
            nnode.r = cur_row;
            q.push(nnode);
        }
        if (visi[cur_row][cur_columm + 1] == 0 && cur_columm + 1 < m && mp[cur_row][cur_columm + 1] != '#')
        {
            visi[cur_row][cur_columm + 1] = 1;
            nnode.c = cur_columm + 1;
            nnode.r = cur_row;
            q.push(nnode);
        }
        if (visi[cur_row - 1][cur_columm] == 0 && cur_row - 1 >= 0 && mp[cur_row - 1][cur_columm] != '#')
        {
            visi[cur_row - 1][cur_columm] = 1;
            nnode.c = cur_columm;
            nnode.r = cur_row - 1;
            q.push(nnode);
        }

        // if (r == 5)
        // {
        //     break;
        // }
    }
    for (auto a : mp)
    {
        for (auto b : a)
        {
            if(b=='x'){
                count+=1;
            }
            // cout << b;
        }
        // cout << endl;
    }

    
    // cout << endl;
    // cout << "mission: " << mission << endl;
    if (mission == 1)
    {

        lv1 += count;
    }
    else if (mission == 2)
    {

        lv2 += count;
    }
}

int main()
{

    cin >> n >> m;
    string ln;
    for (int i = 0; i < n; i++)
    {
        cin >> ln;
        mp.push_back(ln);
    }
    // for(auto a:mp){
    //     for ( auto b:a)
    //     {
    //         cout<<b;
    //     }
    //     cout<<endl;

    // }
    for (int i = 0; i < mp.size(); i++)
    {
        for (int j = 0; j < mp[i].length(); j++)
        {
            // cout<<mp[i][j]<<endl;

            if (mp[i][j] == '*' || mp[i][j] == '$')
            {
                bfs(mp, i, j);
            }
        }
    }
    cout << lv2 << " " << lv1;
}