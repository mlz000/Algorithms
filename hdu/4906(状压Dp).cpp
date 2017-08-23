#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=25,M=1000000007;
long long dp[1<<21];
void add(long long &x,int y){
	x+=y;
	if(x>=M)	x-=M;
}
int main(){
	int T,n,k,l;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		dp[0]=1ll;
		scanf("%d%d%d",&n,&k,&l);
		int ex=0;
		if(l>k){
			ex=l-k;
			l=k;
		}
		for(int i=0;i<n;++i)
			for(int j=(1<<k)-1;j>=0;--j){
				int now=dp[j],next;
				if(!now)	continue;
				for(int p=1;p<=l;++p){
					next=j|((j<<p)&((1<<k)-1))|(1<<(p-1));
					add(dp[next],now);
				}
				add(dp[j],1ll*ex*now%M);
			}
		long long ans=0ll;
		for(int i=0;i<(1<<k);++i)
			if(i&(1<<(k-1)))	add(ans,dp[i]);
		printf("%I64d\n",ans);
	}
	return 0;
}
