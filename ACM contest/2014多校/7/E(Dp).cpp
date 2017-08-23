#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1505;
long long dp[N][N];
int main(){
	int T,n,x,y,z,t;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		printf("Case #%d: ",tt);
		scanf("%d%d%d%d%d",&n,&x,&y,&z,&t);
		for(int i=0;i<=n;++i)
			for(int j=0;j<=i;++j)	
				dp[i][j]=0;
		for(int i=1;i<=n;++i)
			for(int j=0;j<=i;++j){
				int time=t+j*z;
				dp[i][j]=dp[i-1][j]+(long long)(i-j-1)*y*(t+j*z);
				if(j>=1)	dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(long long)(i-j)*y*(t+(j-1)*z));
			}
		long long ans=0ll;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=i;++j)
				ans=max(ans,dp[i][j]+(long long)(n-i)*x*(t+j*z)+(long long)(n-i)*(t+j*z)*(i-j)*y);
		printf("%I64d\n",ans);
	}
	return 0;
}
