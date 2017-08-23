#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=25;
double dp[N],f[N][N];
int main(){
	double p;
	while(~scanf("%lf",&p)){
		dp[0]=1.0/p,dp[1]=1.0/p+(1.0-p)/p*dp[0];
		for(int i=2;i<=19;++i)	dp[i]=1.0/p+(1.0-p)/p*(dp[i-2]+dp[i-1]);
		f[1][0]=dp[0],f[1][1]=f[1][0]+dp[0];
		for(int i=1;i<=19;++i){
			f[i+1][i]=f[i][i]+dp[i];
			f[i+1][i+1]=f[i+1][i]+dp[i];
		}
		printf("%.10lf\n",f[20][19]);
	}
	return 0;
}
