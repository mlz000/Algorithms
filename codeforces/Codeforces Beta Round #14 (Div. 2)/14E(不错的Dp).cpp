#include <cstring>	//实际为2*t-1个拐点，第一个拐点一定是峰
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=25;
int dp[N][5][N];
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	dp[1][1][0]=1;
	dp[1][2][0]=1;
	dp[1][3][0]=1;
	for(int i=2;i<=n;++i)
		for(int j=1;j<=4;++j)
			for(int k=0;k<=20;++k)
				for(int l=1;l<=4;++l){
					if((i==2 && j>l) ||  (i!=2 && j!=l)){
						if(((k&1) && j>l) || ((!(k&1)) && j<l))	dp[i][j][k+1] += dp[i-1][l][k];
						else dp[i][j][k]+=dp[i-1][l][k];
					}
				}
	int ans=0;
	for(int j=1;j<=4;++j)	ans+=dp[n][j][2*t-1];
	printf("%d\n",ans);
	return 0;
}
