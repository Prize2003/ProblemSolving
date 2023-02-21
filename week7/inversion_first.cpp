#include<bits/stdc++.h>
using namespace std;

long long int InversionCount(vector<long long int> &a, long long int l, long long int r){
    if (l == r) 
        return 0;

    long long int mid = (l+r)/2;
    long long int ans = InversionCount(a,l,mid) + InversionCount(a,mid+1,r);
    vector<long long int> tmp(r-l+1);
    int i = l, j = mid+1, k = 0;
    while (i <= mid && j <= r){
        if (a[i] <= a[j]){
            tmp[k++] = a[i++];
        }else{
            tmp[k++] = a[j++];
            ans += mid-i+1;
        }
    }

    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }
    while (j <= r) 
    {
        tmp[k++] = a[j++];
    }
    for (int i = l; i<=r; i++)
    {
        a[i] = tmp[i-l];
    }
    
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    long long int n,ans=0;
    cin >> n;
    vector<long long int> a(n+10);
    for (int i = 0; i<n ;i++){
        long long int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    ans = InversionCount(a,0,n-1);
    cout << ans << '\n';
    return 0;
}