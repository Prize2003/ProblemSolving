#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> start;
    vector<int> finish;
    for (int i = 0; i < 2 * n; i++)
    {
        int st;
        cin >> st;
        if (i <= n - 1)
        {
            start.push_back(st);
        }
        else
        {
            finish.push_back(st);
        }
    }
    sort(start.begin(),start.end());
    
}