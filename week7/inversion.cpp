#include <bits/stdc++.h>

using namespace std;


typedef long long int lng;

lng arr[200000];
lng  tmp[200000];

lng merge(lng a, lng mid,
          lng b)
{
    lng i=a, j=mid, k=a,inv = 0;
    while ((i <= mid - 1) && (j <= b)) {
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            k+=1;
            i+=1;
        }
        else {
            tmp[k] = arr[j];
            k+=1;
            j+=1;
            inv += (mid - i);
        }
    }
    for(i;i <= mid - 1;i++){
        tmp[k] = arr[i];
        k+=1;
    }
    for(j;j <= b;j++){
        tmp[k] = arr[j];
        k+=1;
    }
    for (i = a; i <= b; i++)
        arr[i] = tmp[i];
  
    return inv;
}


lng MS(lng a, lng b)
{
    lng mid, inv = 0;
    if (b > a) {
        mid = (b + a) / 2;
        inv +=MS(a, mid)+MS(mid + 1, b)+merge(a, mid + 1, b);
    }
    return inv;
}



int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lng ans=MS(0,n-1);
    cout<<ans;
}

/*
5
1 
3
10 
2
7
*/