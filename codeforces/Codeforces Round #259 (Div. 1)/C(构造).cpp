#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>g[N],ans;
bool vis[N];
int x[N];
void Set(int u){x[u]^=1;ans.push_back(u);}
void dfs(int u){
	Set(u);
	vis[u]=1;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(vis[v])	continue;
		dfs(v);
		Set(u);
		if(x[v]){
			Set(v);
			Set(u);
		}
	}
}
int main(){
	int n,m,u,v,r=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]);
		if(x[i])	r=i;
	}
	dfs(r);
	int f=0;
	if(x[r])	x[r]=0,f=1;
	bool ok=true;
	for(int i=1;i<=n;++i)
		if(x[i]){
			ok=false;
			break;
		}
	if(!ok)	puts("-1");
	else{
		printf("%d\n",ans.size()-f);
		for(int i=0;i<ans.size()-f;++i)	printf("%d ",ans[i]);
	}
	return 0;
}
