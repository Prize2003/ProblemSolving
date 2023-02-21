#include <bits/stdc++.h>

using namespace std;

long long int dis(vector<int> hight)
{
    int i = 0;
    int st = hight[0];
    vector<int> distance;
    for (auto a : hight)
    {
        if (i != 0)
        {
            if (a >= st)
            {
                distance.push_back(a - st);
            }
            else
            {
                distance.push_back(st - a);
            }
            st=a;
        }
        i++;
    }
    long long int sm=0;
    for(auto a:distance){
        sm+=a;
    }
    // cout<<"sm: "<<sm<<endl;
    return sm;
}

int main()
{
    int n;
    cin >> n;
    vector<int> hight;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        hight.push_back(h);
    }
    long long int mn=1000000000000005;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j&&i!=j+1&&i!=j-1){
                // cout<<"i: "<<i<<"j:"<<j<<endl;
                int t=hight[j];
                hight[j]=hight[i];
                long long int d=dis(hight);
                if(d<mn){
                    mn=d;
                }
                hight[j]=t;
            }
        }
    }
    cout<<mn;
}
/*
5
10 15 20 12 19
*/