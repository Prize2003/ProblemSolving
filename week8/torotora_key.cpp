#include <bits/stdc++.h>
using namespace std;
int dp[100005][250];
/*  j += 1 when taro fight 
	j -=1 when tora fight
    recurrence : dp[i][k] = min(dp[i-1][k-1]+taro[i],dp[i-1][k+1]+tora[i]) 
*/

int main(){
	int T,n,k,taro,tora,st,en;
	scanf("%d",&T);
	while(T--){
	    scanf("%d %d",&n,&k);
	    st=200-k;
	    en=200+k;
	    for(int i=0;i<=n;i++){
	        for(int j=st-1;j<=en+1;j++){
	            dp[i][j]=1e9;
	        }
	    }
	    
		dp[0][200]=0;
		
	    for(int i=1;i<=n;i++){
	        scanf("%d %d",&taro,&tora);
	        for(int j=st;j<=en;j++){
	            dp[i][j]=min(dp[i-1][j-1]+taro,dp[i-1][j+1]+tora);
	            // printf("%d ",dp[i][j]);
	        // }printf("\n");
            }
	    }
	
	    int ans=1e9;
	    for(int j=st;j<=en;j++){
	        //printf("%d ",dp[1][b]);
	        ans=min(ans,dp[n][j]);
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
