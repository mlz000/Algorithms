#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
using namespace std;
const int N=1005,M=1000005;
bool ma[N][N],iscut[N],ans[N];
int n,m,a,b,scc,id,tot,cnt,dfn[N],low[N],to[M<<1],next[M<<1],head[N],color[N];
struct edge{int u,v;};
stack<edge> s;
vector<int> g[N];
map<int,int> block;
void add(int u,int v){
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
void init(){
	block.clear();
	id=tot=cnt=scc=0;
	memset(color,0,sizeof(color));
	memset(iscut,0,sizeof(iscut));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(ma,true,sizeof(ma));
	memset(ans,false,sizeof(ans));
}
bool dfs(int u,int f){
	color[u]=f;
	for(int i=head[u];i;i=next[i]){
		int v=to[i];
		if(block[v]==scc){
			if(color[v]==color[u])	return false;
			if(!color[v] && !dfs(v,3-color[u]))	return false;
		}
	}
	return true;
}
void Tarjan(int u,int fa){
	dfn[u]=low[u]=++id;
	int son=0;
	for(int i=head[u];i;i=next[i]){
		int v=to[i];
		edge e=(edge){u,v};
		if(!dfn[v]){
			s.push(e);
			son++;
			Tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				iscut[u]=true;	
				scc++;
				g[scc].clear();
				for(;;){
					edge t=s.top();
					s.pop();
					if(block[t.u]!=scc)	g[scc].push_back(t.u),block[t.u]=scc;
					if(block[t.v]!=scc)	g[scc].push_back(t.v),block[t.v]=scc;
					if(t.u==u && t.v==v)	break;
				}
				memset(color,0,sizeof(color));
				if(g[scc].size()>=3 && !dfs(u,1)){
					for(int i=0;i<g[scc].size();++i)	ans[g[scc][i]]=true;
				}
			}
		}
		else if(dfn[v]<dfn[u] && v!=fa)	s.push(e),low[u]=min(low[u],dfn[v]);
	}
	if(fa==-1 && son==1)	iscut[u]=false;
}
int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		while(m--)	scanf("%d%d",&a,&b),ma[a][b]=ma[b][a]=false;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(ma[i][j])	add(i,j),add(j,i);
		for(int i=1;i<=n;++i)
			if(!dfn[i])	Tarjan(i,-1);
		for(int i=1;i<=n;++i)	if(!ans[i])	cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
