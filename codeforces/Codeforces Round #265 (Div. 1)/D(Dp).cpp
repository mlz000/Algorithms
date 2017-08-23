#include<bits/stdc++.h>
using namespace std;
const int N=605;
const double eps=1e-50;
double dp[2][N];
int main(){
	dp[0][1]=1.0;
	double ans=0.0,k;
	int n;
	scanf("%d%lf",&n,&k);
	for(int i=1;i<=n;++i){
		for(int j=0;j<N;++j)	ans+=dp[(i-1)&1][j]*(j/2.0+j/(j+1.0));
		for(int j=0;j<N;++j)	dp[i&1][j]=dp[(i-1)&1][j]*(1.0-1.0/(j+1)/k);
		for(int j=0;j<N;++j)	dp[i&1][j+1]+=dp[(i-1)&1][j]/k/(j+1.0);
		for(int j=0;j<N;++j)	if(dp[i&1][j]<eps)	dp[i&1][j]=0.0;
	}
	printf("%.10lf",ans);
	return 0;
}
