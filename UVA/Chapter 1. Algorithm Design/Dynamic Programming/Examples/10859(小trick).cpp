#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//trick:让a最小同时b最小转化为x=Ma+b最小，M为大整数
const int N=1005,M=2000;
int T,n,m,a,b,f[N][2];
bool v[N];
vector<int>g[N];
void dfs(int u){
	v[u]=true;
	f[u][1]=M;
	f[u][0]=0;
	for(int i=0;i<g[u].size();++i){
		int to=g[u][i];
		if(v[to])	continue;
		dfs(to);
		f[u][0]+=f[to][1]+1;
		f[u][1]+=min(f[to][0]+1,f[to][1]);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)	g[i].clear();
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans=0;
		memset(v,0,sizeof(v));
		for(int i=0;i<n;++i){
			if(!v[i]){
				dfs(i);
				ans+=min(f[i][0],f[i][1]);
			}
		}
		printf("%d %d %d\n",ans/M,m-(ans%M),ans%M);
	}
	return 0;
}
