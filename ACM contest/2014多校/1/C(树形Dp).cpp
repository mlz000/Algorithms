#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=205,M=10007;
int zx1,zx2,mi,n,tot,to[N<<1],next[N<<1],head[N],sum[N],dp[N][N],tmp[N];
void add(int u,int v){
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
void dfs(int u,int f){
	int mx=0;
	sum[u]=1;
	for(int i=head[u];~i;i=next[i]){
		int v=to[i];
		if(v==f)	continue;
		dfs(v,u);
		mx=max(mx,sum[v]);
		sum[u]+=sum[v];
	}
	mx=max(mx,n-sum[u]);
	if(mx<mi)	mi=mx,zx1=u,zx2=-1;
	else if(mx==mi)	zx2=u;
}
void calc(int u,int f){
	dp[u][1]=1;
	sum[u]=1;
	for(int i=head[u];~i;i=next[i]){
		int v=to[i];
		if(v==f)	continue;
		if(zx2 && (v==zx1 || v==zx2))	continue;
		calc(v,u);
		memcpy(tmp,dp[u],sizeof(dp[u]));
		memset(dp[u],0,sizeof(dp[u]));
		for(int j=0;j<=sum[u];++j)
			for(int k=0;k<=sum[v];++k)
				dp[u][j+k]=(dp[u][j+k]+tmp[j]*dp[v][k])%M;
		sum[u]+=sum[v];
	}
	dp[u][0]=1;
}
int work(int u,int num,int cnt){
	memset(dp[u],0,sizeof(dp[u]));
	dp[u][1]=1;
	for(int i=head[u];~i;i=next[i]){
		int v=to[i];
		if(v==zx1 || v==zx2)	continue;
		memcpy(tmp,dp[u],sizeof(dp[u]));
		memset(dp[u],0,sizeof(dp[u]));
		for(int j=1;j<=num;++j)
			for(int k=0;k<=sum[v] && k+j<=num && k+k<cnt;++k)
				dp[u][j+k]=(dp[u][j+k]+tmp[j]*dp[v][k])%M;
	}
	return dp[u][num];
}
int main(){
	int T,x,y;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		zx1=zx2=-1,tot=0,mi=1000;
		printf("Case %d: ",tt);
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			add(x,y),add(y,x);
		}
		dfs(1,0);
		int ans=0;
		if(zx2==-1){
			calc(zx1,0);
			for(int i=1;i<=n;++i)	ans=(ans+work(zx1,i,i))%M;
		}
		else{
			calc(zx1,0),calc(zx2,0);
			for(int i=1;i+i<=n;++i)
				ans=(ans+work(zx1,i,i+i)*work(zx2,i,i+i))%M;
		}
		printf("%d\n",ans);
	}
	return 0;
}
