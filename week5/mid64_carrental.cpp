#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int c;
    int p;
    int w;
};

int main()
{
    int k, n;
    cin >> k >> n;
    vector<Node> car;
    for (int i = 0; i < k; i++)
    {
        int cc, pp, ww;
        cin >> cc >> pp >> ww;
        Node nd;
        nd.c = cc;
        nd.p = pp;
        nd.w = ww;
        car.push_back(nd);
    }
    vector<int> stock;
    for (int i = 0; i < n; i++)
    {
        int st;
        cin >> st;
        stock.push_back(st);
    }
    int pay=1000000000;
    for (int i = 0; i < k; i++)
    {
        int sm = 0;
        int l = 1;
        Node contract = car[i];
        for (int j = 0; j < n; j++)
        {
            // cout<<"sm: "<<sm<<endl;
            if (sm <= contract.w)
            {
                sm += stock[j];
            }
            if (sm > contract.w){
                sm=stock[j];
                l+=1;
            }
        }
        if(l!=n){
            int pyy=contract.c+l*contract.p;
            if(pyy<pay){
                pay=pyy;
            }
        }
        // cout<<l<<endl;
    }
    cout<<pay;
}
// 4 6
// 50 100 20
// 100 10 10
// 0 1000 1000
// 10 10 5
// 5 4 3 3 3 7