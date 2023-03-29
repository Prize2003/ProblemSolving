#include <bits/stdc++.h>

using namespace std;

int banana[200000] = {0};

int score[200000] = {0};
int mx_sc[200000] = {0};
int n;

// version loop

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> banana[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        if (i == 1 || i == 2)
        {
            score[i] = 0;
            mx_sc[i] = 0;
        }
        else
        {
            int p = banana[i];
            if (mx_sc[i - 1] < p + mx_sc[i - 3])
            {
                mx_sc[i] = p + mx_sc[i - 3];
            }
            else
            {
                mx_sc[i] = mx_sc[i - 1];
            }
            // for (int j = 1; j <= i - 3; j++)
            // {
            //     if (score[j] > mx)
            //     {
            //         mx = score[j];
            //     }
            // }

            score[i] = p + mx_sc[i - 3];
            if (score[i] > ans)
            {
                ans = score[i];
            }
        }
        // cout << i << ")" << endl;
        // cout << "mx_sc[i]: " << mx_sc[i] << endl;
        // cout << "score[i]: " << score[i] << endl;
    }
    cout << ans;
}

// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> banana[i];
//     }

// }

/*
12
1
2
5
4
3
0
6
1
2
7
2
1
*/