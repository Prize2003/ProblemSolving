#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int s;
    int t;
    int number;
};

int cmp(Node a,Node b){
    return a.t<b.t;
}


int main()
{
    
    int n;
    cin >> n;
    vector<Node> timeline;
    for (int i = 0; i < n; i++)
    {
        Node tm;
        int ss, tt;
        cin >> ss >> tt;
        tm.s = ss;
        tm.t = tt;
        tm.number=i+1;
        timeline.push_back(tm);
    }
    sort(timeline.begin(),timeline.end(),cmp);
    int ans=1;
    int stp=1;
    int visit[n]={0};
    int ed=timeline[0].t;
    for(auto a:timeline){
        if(a.s>=ed){
            ed=a.t;
            ans+=1;
        }
    }
    cout<<ans;
}