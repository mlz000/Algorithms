#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N=50;
int n,h;
long long dp[N][N];
int main()
{
	scanf("%d%d",&n,&h);
	for(int k=1;k<=n;++k)
	{
		dp[0][k-1]=1;
		for(int i=1;i<=n;++i)
			for(int j=0;j<i;++j)
				dp[i][k]+=dp[j][k-1]*dp[i-1-j][k-1];
	}
	printf("%I64d",dp[n][n]-dp[n][h-1]);
	return 0;
}
