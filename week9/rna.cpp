#include <bits/stdc++.h>

using namespace std;

int ans[500][500];

int main()
{
    string b;
    cin >> b;
    int n = b.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 5; j < n; j++)
        {
            if ((b[i] == 'G' && b[j] == 'C') || (b[i] == 'C' && b[j] == 'G') || (b[i] == 'A' && b[j] == 'U') || (b[i] == 'U' && b[j] == 'A'))
            {
                ans[i][j] = max(ans[i][j], ans[i + 1][j - 1] + 1);
            }
            for (int k = i; k < j; k++)
            {
                ans[i][j] = max(ans[i][j], ans[i][k] + ans[k + 1][j]);
            }
        }
    }
    cout << ans[0][n - 1] << "\n";
}

/*
GCGAUGCGCAUAACG
*/
/*
GCGAUGCGCAUAACGCGCAAAAAGCGU
*/