#include <bits/stdc++.h>

using namespace std;

int ready = 0;

bool bfs(vector<string> mass, int x1, int x2, int y1, int y2, int m, int n)
{
    bool ans;
    int px1, px2, py1, py2,ox1,ox2,oy1,oy2, p = 0;
    // int o = 0;
    while (1)
    {
        ox1=x1;
        ox2=x2;
        oy1=y1;
        oy2=y2;
        // cout << "old x1 :" << x1 << " x2 :" << x2 << " y1 :" << y1 << " y2 :" << y2 << endl;
        if (x1 == 0)
        {
            if (mass[y2 + 1][x1] == '.' && mass[y2 + 1][x2] == '.')
            {
                mass[y2 + 1][x1] = 'x';
                mass[y2 + 1][x2] = 'x';
                y1 += 1;
                y2 += 1;
                px1 = x1;
                px2 = x2;
                py1 = y1;
                py2 = y2;
            }
            else if (mass[y1][x2 + 1] == '.' && mass[y2][x2 + 1] == '.')
            {
                mass[y1][x2 + 1] = 'x';
                mass[y2][x2 + 1] = 'x';
                x1 += 1;
                x2 += 1;
            }
            else if(y1!=0&&mass[y1 - 1][x1] == '.' && mass[y1 - 1][x2] == '.'){
                mass[y1 - 1][x1] = 'x';
                mass[y1 - 1][x2] = 'x';
                y1 -= 1;
                y2 -= 1;
            }
            else if ((mass[y2 + 1][x1] != '.' || mass[y2 + 1][x2] != '.') && (mass[y1][x1 - 1] != '.' || mass[y2][x1 - 1] != '.') && (mass[y1][x2 + 1] != '.' || mass[y2][x2 + 1] != '.')&& y1!=0)
            {
                x1 = px1;
                x2 = px2;
                y1 = py1;
                y2 = py2;
                if ((mass[y1][x1 - 1] != '.' || mass[y2][x1 - 1] != '.') && (mass[y1][x2 + 1] != '.' || mass[y2][x2 + 1] != '.'))
                {
                    y1 -= 1;
                    y2 -= 1;
                    px1 = x1;
                    px2 = x2;
                    py1 = y1;
                    py2 = y2;
                }
            }
        }
        else if (x2 == m - 1)
        {
            if (mass[y2 + 1][x1] == '.' && mass[y2 + 1][x2] == '.')
            {
                mass[y2 + 1][x1] = 'x';
                mass[y2 + 1][x2] = 'x';
                y1 += 1;
                y2 += 1;
                px1 = x1;
                px2 = x2;
                py1 = y1;
                py2 = y2;
            }
            else if (mass[y1][x1 - 1] == '.' && mass[y2][x1 - 1] == '.')
            {
                mass[y1][x1 - 1] = 'x';
                mass[y2][x1 - 1] = 'x';
                x1 -= 1;
                x2 -= 1;
            }
            else if(y1!=0&&mass[y1 - 1][x1] == '.' && mass[y1 - 1][x2] == '.'){
                mass[y1 - 1][x1] = 'x';
                mass[y1 - 1][x2] = 'x';
                y1 -= 1;
                y2 -= 1;
            }
            else if ((mass[y2 + 1][x1] != '.' || mass[y2 + 1][x2] != '.') && (mass[y1][x1 - 1] != '.' || mass[y2][x1 - 1] != '.') && (mass[y1][x2 + 1] != '.' || mass[y2][x2 + 1] != '.')&& y1!=0)
            {
                x1 = px1;
                x2 = px2;
                y1 = py1;
                y2 = py2;
                if ((mass[y1][x1 - 1] != '.' || mass[y2][x1 - 1] != '.') && (mass[y1][x2 + 1] != '.' || mass[y2][x2 + 1] != '.'))
                {
                    y1 -= 1;
                    y2 -= 1;
                    px1 = x1;
                    px2 = x2;
                    py1 = y1;
                    py2 = y2;
                }
            }
        }
        else
        {
            if (mass[y2 + 1][x1] == '.' && mass[y2 + 1][x2] == '.')
            {
                mass[y2 + 1][x1] = 'x';
                mass[y2 + 1][x2] = 'x';
                y1 += 1;
                y2 += 1;
                px1 = x1;
                px2 = x2;
                py1 = y1;
                py2 = y2;
            }
            else if (mass[y1][x1 - 1] == '.' && mass[y2][x1 - 1] == '.')
            {
                mass[y1][x1 - 1] = 'x';
                mass[y2][x1 - 1] = 'x';
                x1 -= 1;
                x2 -= 1;
            }
            else if (mass[y1][x2 + 1] == '.' && mass[y2][x2 + 1] == '.')
            {
                mass[y1][x2 + 1] = 'x';
                mass[y2][x2 + 1] = 'x';
                x1 += 1;
                x2 += 1;
            }
            else if(y1!=0&&mass[y1 - 1][x1] == '.' && mass[y1 - 1][x2] == '.'){
                mass[y1 - 1][x1] = 'x';
                mass[y1 - 1][x2] = 'x';
                y1 -= 1;
                y2 -= 1;
            }
            else if ((mass[y2 + 1][x1] != '.' || mass[y2 + 1][x2] != '.') && (mass[y1][x1 - 1] != '.' || mass[y2][x1 - 1] != '.') && (mass[y1][x2 + 1] != '.' || mass[y2][x2 + 1] != '.')&& y1!=0)
            {
                x1 = px1;
                x2 = px2;
                y1 = py1;
                y2 = py2;
                if ((mass[y1][x1 - 1] != '.' || mass[y2][x1 - 1] != '.') && (mass[y1][x2 + 1] != '.' || mass[y2][x2 + 1] != '.'))
                {
                    y1 -= 1;
                    y2 -= 1;
                    px1 = x1;
                    px2 = x2;
                    py1 = y1;
                    py2 = y2;
                }
            }
        }
        // cout << "new x1 :" << x1 << " x2 :" << x2 << " y1 :" << y1 << " y2 :" << y2 << endl<<endl;
        if (y2 == n - 1)
        {
            ready = 1;
            // cout<<"l"<<endl;
            ans = true;
            break;
        }
        else if (ox1==x1&&ox2==x2&&oy1==y1&&oy2==y2)
        {
            ans = false;
            //    cout<<";"<<endl;
            break;
        }
        // o += 1;
    }
    return ans;
}

int main()
{
    int n, m, x1 = 0, x2 = 1, y1 = 0, y2 = 1;
    bool ans = true;
    string path;
    cin >> n >> m;
    vector<string> mass;
    for (int i = 0; i < n; i++)
    {
        cin >> path;
        mass.push_back(path);
    }
    while (!ready)
    {
        // cout<<x1<<" "<<x2<<endl;

        if (x2 == m)
        {
            ans = false;
            break;
        }
        if (mass[y1][x1] == '.' && mass[y1][x2] == '.' && mass[y2][x1] == '.' && mass[y2][x2] == '.')
        {
            mass[y1][x1] = 'x';
            mass[y1][x2] = 'x';
            mass[y2][x1] = 'x';
            mass[y2][x2] = 'x';
            ans = bfs(mass, x1, x2, y1, y2, m, n);
        }
        x1 += 1;
        x2 += 1;
    }
    if (ans)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}
