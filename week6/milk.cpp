#include <bits/stdc++.h>

using namespace std;

int parent[100000];

int find_parent(int v)
{
    if (parent[v] != v)
    {
        return parent[v] = find_parent(parent[v]);
    }
    return v;
}

void union_set(int a, int b)
{

    a = find_parent(a);
    b = find_parent(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int j = 0; j < n; j++)
    {
        parent[j] = j;
    }
    for (int i = 0; i < q; i++)
    {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        x--;
        y--;

        if (opt == 'q')
        {
            if (find_parent(x) == find_parent(y))
            {
                cout << "yes" << '\n';
            }
            else
            {
                cout << "no" << '\n';
            }
        }
        else if (opt == 'c')
        {
            union_set(x, y);
        }
    }
}

/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/