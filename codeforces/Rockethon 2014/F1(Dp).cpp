#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,k;
long long a[N],dp[N][N];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)	scanf("%I64d",&a[i]);
	for(int j=1;j<=k;++j){
		long long M=-1e14;
		for(int i=1;i<=n;++i){
			M=max(M,dp[i-1][j-1]-a[i]);
			dp[i][j]=max(dp[i-1][j],M+a[i]);
		}
	}
	printf("%I64d\n",dp[n][k]);
	return 0;
}
