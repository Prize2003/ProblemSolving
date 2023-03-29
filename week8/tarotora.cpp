#include <bits/stdc++.h>

using namespace std;

pair<int, int> tarotora[1000];

int main()
{
    int c, n, k;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int hp=100000000;
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            tarotora[j] = {a, b};
        }
        vector<vector<int>> ans, aa, bb;
        map<pair<int, int>, int> mp;
        vector<int> fr, fa, fb;
        fr.push_back(tarotora[0].first);
        fr.push_back(tarotora[0].second);
        fa.push_back(1);
        fb.push_back(0);
        fa.push_back(0);
        fb.push_back(1);
        ans.push_back(fr);
        aa.push_back(fa);
        bb.push_back(fb);

        for (int j = 1; j < n; j++)
        {
            for (int l = 0; l < ans[j - 1].size(); l++)
            {
                int ans_left = ans[j - 1][l] + tarotora[j].first;
                int akl = aa[j - 1][l] + 1;
                int bkl = bb[j - 1][l];
                if (((mp[{akl, bkl}] != 0 && mp[{akl, bkl}] > ans_left) || mp[{akl, bkl}] == 0)&&abs(akl-bkl)<=k)
                {
                    mp[{akl, bkl}] = ans_left;
                }
                else if(abs(akl-bkl)>k){
                    mp[{akl, bkl}] = 100000000;
                }
                int ans_right = ans[j - 1][l] + tarotora[j].second;
                int akr = aa[j - 1][l];
                int bkr = bb[j - 1][l] + 1;
                if (((mp[{akr, bkr}] != 0 && mp[{akr, bkr}] > ans_right) || mp[{akr, bkr}] == 0)&&abs(akr-bkr)<=k)
                {
                    mp[{akr, bkr}] = ans_right;
                }
                else if(abs(akr-bkr)>k){
                    mp[{akr, bkr}] = 100000000;
                }
            }
            vector<int> nans, naa, nbb;
            for (auto as : mp)
            {
                nans.push_back(as.second);
                naa.push_back(as.first.first);
                nbb.push_back(as.first.second);
                if(abs(as.first.first-as.first.second)<=k&&(as.first.first+as.first.second)==n&&as.second<hp){
                    hp=as.second;
                }
                // cout << a.second << " " << a.first.first << " " << a.first.second << endl;
            }
            // cout<<hp<<"\n";
            ans.push_back(nans);
            aa.push_back(naa);
            bb.push_back(nbb);
            // cout << endl;
            mp.clear();
        }
        cout<<hp<<"\n";
    }

    return 0;
}

/*
2
4 2
1 2
1 2
1 2
1 2
4 2
5 2
2 5
5 2
2 5
*/

/*
1
5 2
1 2
1 100
1 2
1 100
1 2
*/

/*
1
5 2
1 2
1 2
1 100
1 100
1 2
*/

/*
1
5 2
1 2
1 2
1 2
1 2
1 2
*/