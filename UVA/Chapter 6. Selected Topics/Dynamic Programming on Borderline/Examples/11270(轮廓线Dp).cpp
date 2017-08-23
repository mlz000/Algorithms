#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=11;
long long dp[2][1<<N],ans[105][105];
int n,m,cur;
void calc(int a,int b){
	if(b&(1<<m))	dp[cur][b^(1<<m)]+=dp[cur^1][a];
}
long long solve(){
	memset(dp,0,sizeof(dp));
	dp[cur][(1<<m)-1]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cur^=1;
			memset(dp[cur],0,sizeof(dp[cur]));
			for(int k=0;k<(1<<m);++k){
				calc(k,k<<1);//²»·Å
				if(i && !(k&(1<<(m-1))))	calc(k,(k<<1)^(1<<m)^1);//Êú·Å
				if(j && !(k&1))	calc(k,(k<<1)|3);
			}
		}
	return dp[cur][(1<<m)-1];
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		if(n<m)	swap(n,m);
		if(!ans[n][m] && n*m%2==0)	ans[n][m]=solve();
		printf("%lld\n",ans[n][m]);
	}
	return 0;
}
	
