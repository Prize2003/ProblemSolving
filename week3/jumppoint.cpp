#include <bits/stdc++.h>

using namespace std;

struct location
{
    int c;
    int r;
    int ix;
    int passs = 0;
};

int main()
{
    int n, r, x, y;
    cin >> n >> r;
    location leaf[1500];
    int distance[1500] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        leaf[i].c = x;
        leaf[i].r = y;
        leaf[i].ix = i;
    }
    leaf[n].c = 100;
    leaf[n].r = 100;
    leaf[n].ix = n;
    double dis;
    queue<location> q;
    location st;
    st.c = 0;
    st.r = 0;
    st.passs = 1;
    st.ix=-1;
    q.push(st);

    int i = 0;

    while (!q.empty())
    {
        dis = 0;
        location t = q.front();
        q.pop();
        for (int i = 0; i < n + 1; i++)
        {
            if (!leaf[i].passs)
            {
                dis =(leaf[i].c - t.c)*(leaf[i].c - t.c) + (leaf[i].r - t.r)*(leaf[i].r - t.r);

                // cout << "dis: " << dis << endl;
                if (dis <= r * r)
                {
                    distance[i] = distance[t.ix] + 1;
                    leaf[i].passs = 1;
                    q.push(leaf[i]);
                    // px = t.xx;
                    // py = t.yy;
                    // idx=i;
                }
            }
        }

    }
    if (distance[n] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << distance[n];
    }
}
