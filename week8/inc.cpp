#include <bits/stdc++.h>

using namespace std;

int s[2000];
int l[2000];
int idx[2000];
 vector <int> ansl;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        l[i] = 1;
        idx[i]=-1;
    }
    int mx_idx=0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i] > s[j] && l[i] < l[j] + 1)
            {
                idx[i]=j;
                l[i] = l[j] + 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(l[mx_idx]<l[i]){
            mx_idx=i;
        }
    }
    int win = 0;
    for (int i = 0; i < n; i++)
    {
        if (l[i] > win)
        {

            win = l[i];
        }
    }
    cout << win << "\n";
    ansl.push_back(mx_idx);
    int i=mx_idx;
    while(idx[i]!=-1){
        ansl.push_back(idx[i]);
        i=idx[i];
    }

    for(auto a=ansl.rbegin();a!=ansl.rend();a++){
        cout<<s[*a]<<" ";
    }

}

/*
5
1
2
2
3
4
*/

/*
5
1
-1
2
-2
3
*/

/*
5
5
4
3
2
1
*/

/*
5
1
1
1
1
1
*/

/*
5
-1
-2
-4
0
-6
*/