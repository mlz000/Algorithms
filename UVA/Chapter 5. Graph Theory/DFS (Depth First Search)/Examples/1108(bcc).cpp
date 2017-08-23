#include <cstdio>//Ã¶¾Ù¸ù Í¼Æ¥Åä
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
using namespace std;
const int N=50005<<1;
struct edge{int u,v;};
stack<edge>s;
vector<int>bcc[N];
map<int,int>block;
int ca,n,m,a,b,scc,id,tot,head[N],to[N],next[N],dfn[N],low[N];
bool iscut[N];
void add(int u,int v){
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
void init(){
	scc=id=tot=0;
	block.clear();
	memset(iscut,0,sizeof(iscut));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		n=max(n,max(a,b));
		add(a,b),add(b,a);
	}
}
void tarjan(int u,int fa){
	dfn[u]=low[u]=++id;
	int son=0;
	for(int i=head[u];i;i=next[i]){
		int v=to[i];
		edge e=(edge){u,v};
		if(!dfn[v]){
			s.push(e);
			son++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				iscut[u]=true;
				scc++;
				bcc[scc].clear();
				for(;;){
					edge t=s.top();
					s.pop();
					if(block[t.u]!=scc)	bcc[scc].push_back(t.u),block[t.u]=scc;
					if(block[t.v]!=scc)	bcc[scc].push_back(t.v),block[t.v]=scc;
					if(t.u==u && t.v==v)	break;
				}
			}
		}
		else if(dfn[v]<dfn[u] && v!=fa)	s.push(e),low[u]=min(low[u],dfn[v]);
	}
	if(fa<0 && son==1)	iscut[u]=false;
}
int main(){
	while(scanf("%d",&m)&&m){
		ca++;
		printf("Case %d: ",ca);
		init();
		for(int i=1;i<=n;++i)
			if(!dfn[i])	tarjan(i,-1);
		long long ans1=0ll,ans2=1ll;
		for(int i=1;i<=scc;++i){
			int cnt=0;
			for(int j=0;j<bcc[i].size();++j)
				if(iscut[bcc[i][j]])	cnt++;
			if(cnt==1)	ans1++,ans2*=(long long)(bcc[i].size()-cnt);
		}
		if(scc==1)	ans1=2,ans2=bcc[1].size()*(bcc[1].size()-1)/2;
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}
