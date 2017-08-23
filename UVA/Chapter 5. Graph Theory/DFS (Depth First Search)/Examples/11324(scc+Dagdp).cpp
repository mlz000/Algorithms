#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int N=1005,M=50005;
stack<int>s;
vector<int>g[N];
int T,n,m,a,b,x,y,ans,tot,id,scc,w[N],dp[N],head[N],to[M],next[M],dfn[N],low[N],belong[N];
void add(int u,int v){
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
void init(){
	scc=id=tot=x=y=0;
	while(s.size())	s.pop();
	memset(belong,0,sizeof(belong));
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(next,0,sizeof(next));
	memset(w,0,sizeof(w));
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		add(a,b);
	}
}
void tarjan(int u){
	dfn[u]=low[u]=++id;
	s.push(u);
	for(int i=head[u];i;i=next[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!belong[v])	low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		scc++;
		for(;;){
			int tmp=s.top();
			s.pop();
			belong[tmp]=scc;
			if(tmp==u)	break;
		}
	}
}
int dfs(int u){
	if(!g[u].size())	return w[u];
	if(dp[u])	return dp[u];
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		dp[u]=max(dp[u],w[u]+dfs(v));
	}
	return dp[u];
}
void work(){
	for(int i=1;i<=n;++i)
		if(!dfn[i])	tarjan(i);
	for(int i=1;i<=scc;++i)	g[i].clear();
	for(int i=1;i<=n;++i){
		w[belong[i]]++;
		for(int e=head[i];e;e=next[e]){
			int v=to[e];
			if(belong[i]!=belong[v])	g[belong[i]].push_back(belong[v]);
		}
	}
	int ans=0;
	for(int i=1;i<=scc;++i)	ans=max(ans,dfs(i));
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	return 0;
}
