#include <bits/stdc++.h>
using namespace std;

int c[600][600];

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();

    for (int i = 1; i <= m; i++)
    {
        c[i][0] = i * -2;
    }
    for (int j = 1; j <= n; j++)
    {
        c[0][j] = j * -2;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == t[i - 1])
            {
                c[i][j] = max(c[i - 1][j - 1] + 1, max(c[i - 1][j] - 2, c[i][j - 1] - 2));
            }
            else
            {
                c[i][j] = max(c[i - 1][j - 1] -1, max(c[i - 1][j] - 2, c[i][j - 1] - 2));
            }
        }
    }

    int i = m, j = n;
    int ans = 0;
    int idx = 0;
    string a = "", b = "";
    while (i > 0 || j > 0)
    {
        if (i > 0 && c[i - 1][j] - 2 == c[i][j])
        {
            a += '-';
            b += t[i - 1];
            i--;
        }
        else if (j > 0 && c[i][j - 1] - 2 == c[i][j])
        {
            a += s[j - 1];
            b += '-';
            j--;
        }
        else
        {
            a += s[j - 1];
            b += t[i - 1];
            i--;
            j--;
        }
        if (a[idx] != b[idx])
        {
            ans++;
        }
        idx += 1;
    }

    cout << ans << endl;
    // for (int i = a.size() - 1; i >= 0; i--)
    // {
    //     cout << a[i] << "";
    // }
    // cout << "\n";
    // for (int i = a.size() - 1; i >= 0; i--)
    // {
    //     cout << b[i] << "";
    // }
    // cout << "\n";
}

/*
AAABBBCCC
ZBBCCCD
*/

/*
ABCDEFGH
AABEEGHFI
*/

/*
YTVCAYBSCAS
ABSBCIASC
*/

/*
Fix this code when I input
teacher
botcher
Output must be 3
*/