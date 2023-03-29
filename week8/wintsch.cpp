#include <bits/stdc++.h>
using namespace std;

pair<int, pair<int, int>> sch[2000];

int find_index(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (sch[n].second.first>=sch[i].second.second)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, t, w;
        cin >> s >> t >> w;
        sch[i] = {w, {s, t}};
    }
    int mx[n];
    mx[0]=sch[0].first;
    vector <int> ansl[n];
    ansl[0].push_back(0);
    for(int i=1;i<n;i++){
        int idx=find_index(i);
        int cur=sch[i].first;
        if(idx!=-1){
            cur+=mx[idx];
        }
        if(mx[i-1]<cur){
            mx[i]=cur;
            if(idx!=-1){
                ansl[i]=ansl[idx];
            }
            ansl[i].push_back(i);
        }
        else{
            ansl[i]=ansl[i-1];
            mx[i]=mx[i-1];
        }
    }
    cout<<mx[n-1]<<"\n";
    cout<<ansl[n-1].size()<<"\n";
    for(auto a:ansl[n-1]){
      cout<<a+1<<" ";
    }
}

/*
3
1 3 2
2 4 3
3 5 2
*/

/*
3
1 3 2
2 4 10
3 5 2
*/

/*
5
1 2 3
2 4 7
1 3 4
2 3 9
8 9 1
*/