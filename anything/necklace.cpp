#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    list<int> l[5] = {{1, 6, 7}, {2, 8, 9}, {3, 10}, {4, 11}, {5, 12}};
    list<int>::iterator it[5];
    for (int i = 0; i < 5; i++)
    {
        it[i] = l[i].begin();
    }
    l[0].splice(++l[0].begin(), l[4]);
    for (int i = 0; i < 5; i++)
    {
        cout << *it[i] << endl;
    }
    return 0;
}