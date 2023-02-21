#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dis;
    for (int i = 0; i < n; i++)
    {
        int food;
        cin >> food;
        if (i + 1 >= food)
        {
            dis.push_back((i + 1) - food);
        }
        else
        {
            dis.push_back(((i + 1) - food) + n);
        }
    }
    // for (auto a : dis)
    // {
    //     cout << a << endl;
    // }
    sort(dis.begin(), dis.end());
    int key = dis[0];
    // cout<<"first: "<<dis[0]<<endl;
    int mrepeat = 1;
    int repeat = 1;
    // cout<<endl;
    for (int i = 1; i < n; i++)
    {
        // cout << repeat << endl;
        if (dis[i] == key)
        {
            repeat += 1;
        }

        else
        {
            if (repeat > mrepeat)
            {
                mrepeat = repeat;
            }
            repeat = 0;
            key = dis[i];
        }
    }
    if (repeat > mrepeat)
    {
        mrepeat = repeat;
    }
    cout << mrepeat+1;
}
/*
5
4 5 2 3 1
*/
/*
8
1 2 3 5 4 6 7 8
*/

/*
10
3 4 5 6 7 8 9 10 1 2
*/

/*
5
1 2 3 4 5
*/

/*
10
1 2 4 3 5 6 8 7 9 10
*/