#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N=20005,M=50005;
stack<int>s;
int T,n,m,a,b,x,y,ans,tot,id,scc,head[N],to[M],next[M],dfn[N],low[N],belong[N],in[N],out[N];
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
void work(){
	for(int i=1;i<=n;++i)
		if(!dfn[i])	tarjan(i);
	for(int i=1;i<=scc;++i)	in[i]=out[i]=0;
	for(int i=1;i<=n;++i)
		for(int e=head[i];e;e=next[e]){
			int v=to[e];
			if(belong[i]!=belong[v])	out[belong[i]]=in[belong[v]]=1;
		}
	for(int i=1;i<=scc;++i){
		if(!in[i])	x++;
		if(!out[i])	y++;
	}
	ans=max(x,y);
	if(scc==1)	ans=0;
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
