#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int max=0,b,count=0;
    cin >> n;
    for (int i = 0; i<n;i++)
    {
        int a;
        cin >> a;
        if (i==0 || a-b == 1 || a-b == n-1)
        {
            count++;
        }
        else 
        {
            if (max < count)
            {
                max = count;
            }
            count = 1;
        }
    }
    cout << max;
    return 0;
}