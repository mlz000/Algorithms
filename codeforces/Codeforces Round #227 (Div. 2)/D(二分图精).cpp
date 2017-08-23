#include <cstdio>//枚举根 图匹配
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=505;
int n,m,u,v,in[N],out[N],l[N];
bool g[N][N],vis[N];
bool can(int u,int root){
	for(int i=1;i<=n;++i){
		if(i==root)	continue;
		if(!vis[i] && g[u][i]){
			vis[i]=true;
			if(!l[i] || can(l[i],root)){
				l[i]=u;
				return true;
			}
		}
	}
	return false;
}
int work(int root){
	int s=in[root]+out[root]-g[root][root];
	int tmp=2*n-1-s;
	memset(l,0,sizeof(l));
	int f=0;
	for(int i=1;i<=n;++i){
		if(i==root)	continue;
		memset(vis,0,sizeof(vis));
		if(can(i,root))	f++;
	}
	tmp+=n-1-f;//加边数
	tmp+=m-s-f;//删边数
	return tmp;
}
int main(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)	scanf("%d%d",&u,&v),g[u][v]=true,in[v]++,out[u]++;
		int ans=1<<30;
		for(int i=1;i<=n;++i)	{
			ans=min(ans,work(i));
		}
		printf("%d\n",ans);
		return 0;
}
