#include <bits/stdc++.h>

using namespace std;

char alpha[100];
int l[100];

int d(int a, int b)
{
    for (int i = 0; i < 26; i++)
    {
        l[i] = 100;
    }
    l[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (t + 1 < 26 && t + 1 != a && l[t + 1] > l[t] + 1)
        {
            l[t + 1] = l[t] + 1;

            q.push(t + 1);
        }
        if (t - 1 > -1 && t - 1 != a && l[t - 1] > l[t] + 1)
        {
            l[t - 1] = l[t] + 1;

            q.push(t - 1);
        }
        if (t == 25 && a != 0 && l[0] > l[25] + 1)
        {
            l[0] = l[25] + 1;

            q.push(0);
        }
        if (t == 0 && a != 25 && l[25] > l[0] + 1)
        {
            l[25] = l[0] + 1;

            q.push(25);
        }
    }
    return l[b];
}

int min_dis(string wd)
{
    wd = "A" + wd;
    vector<int> dp(26, 30000);
    dp[wd[0] - 'A'] = 0;
    int a = wd[0] - 'A';
    int sz = wd.size();
    for (int i = 1; i < sz; i++)
    {
        int b = wd[i] - 'A';
        vector<int> dp1(26, 30000);
        for (int j = 0; j < 26; j++)
        {
            if (dp[j] != 30000)
            {
                if(dp1[a]> dp[j] + d(j, b)){
                    dp1[a]=dp[j] + d(j, b);
                }
                if(dp1[j]>dp[j] + d(a, b)){
                    dp1[j]=dp[j] + d(a, b);
                }
            }
        }
        dp = dp1;
        a = b;
    }
    int mn = 30000;
    for (auto as : dp)
    {
        if (as < mn)
        {
            mn = as;
        }
    }
    return mn;
}

int main()
{
    int n;
    cin >> n;
    if (n <= 10)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            string wd;
            cin >> wd;
            ans.push_back(min_dis(wd));
        }
        for (auto a : ans)
        {
            cout << a << "\n";
        }
    }
}

/*
3
BYEBYE
YOUBELONGWITHME
HELLOWORLD
*/

/*
5
ABCDE
QBT
XFE
QAT
QAZ
*/

/*
5
ABCDE
DEC
ALL
IIO
HBK
*/

/*
4
PYTHON
C
CPP
JAVA
*/