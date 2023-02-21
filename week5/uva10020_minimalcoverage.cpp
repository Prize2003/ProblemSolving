#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    // cout << endl;
    for (int i = 0; i < n; i++)
    {

        int start = 0, finish;
        cin >> finish;
        // cout<<finish;
        vector<pair<int, int>> time;
        int s = 1, t = 1;
        while (s != 0 || t != 0)
        {
            cin >> s >> t;
            // cout<<"s: "<<s<<" t: "<<t<<endl;
            if (((s < start && t > start) || (s >= start && finish > s))&&(s!=t))
            {
                time.push_back({s, t});
            }
        }
        // sort(time.begin() , time.end());
        // cout<<endl;
        // for (auto a : time)
        // {
        //     cout <<"sf: "<< a.first << " " << a.second << endl;
        // }
        vector<pair<int, int>> ans;
        int l=0;
        while (start < finish)
        {
            int mx = 0;
            int hv = 0;
            pair<int, int> num;
            for (auto a : time)
            {
                if (a.first <= start && a.second > mx&&a.second>start)
                {
                    // cout<<"first: "<<a.first<<" second: "<<a.second<<endl;
                    hv = 1;
                    mx = a.second;
                    num = a;
                }
            }
            if (hv)
            {
                l+=1;
                // cout<<"hv: "<<hv<<endl;
                start = mx;
                ans.push_back(num);
            }
            
            else
            {
                l=0;
                break;
            }
            // cout<<"start: "<<start<<endl;
        }
        cout << l << endl;
        if (l != 0)
        {
            for (auto a : ans)
            {
                cout << a.first << " " << a.second << endl;
            }
        }
        cout << endl;
    }
}

/*
1
-1 0
-5 -3
2 5
0 0
*/

/*
1
-1 0
0 1
0 0
*/