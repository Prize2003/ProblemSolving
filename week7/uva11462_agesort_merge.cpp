#include <bits/stdc++.h>

using namespace std;

int st[2000003];

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> st[i];
        }
        sort(st, st + n);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                cout << st[i]<<" ";
            }
            else{
                cout << st[i]<<"\n";
            }
        }
    }
}