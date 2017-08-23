#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10010,LOG=20;
int a,b,c,n,T,tot,head[N],to[N<<1],next[N<<1],w[N<<1],dep[N],dis[N],p[N][LOG];
char s[LOG];
void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	next[tot]=head[u];
	head[u]=tot;
}
void dfs(int u,int fa,int d){
	dep[u]=dep[fa]+1;
	dis[u]=d;
	p[u][0]=fa;
	for(int i=1;i<LOG;++i)	p[u][i]=p[p[u][i-1]][i-1];
	for(int i=head[u];i;i=next[i]){
		if(to[i]==fa)	continue;
		dfs(to[i],u,d+w[i]);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y])	swap(x,y);
	if(dep[x]<dep[y]){
		int delta=dep[y]-dep[x];
		for(int i=0;i<LOG;++i){
			if(delta>>i&1)	y=p[y][i];
		}
	}
	if(x!=y){
		for(int i=LOG-1;i>=0;--i){
			if(p[x][i]!=p[y][i]){
				x=p[x][i];
				y=p[y][i];
			}
		}
		x=p[x][0];
		y=p[y][0];
	}
	return x;
}
int calc(int x,int k){
	for(int i=0;i<LOG;++i){
		if(k>>i&1)	x=p[x][i];
	}
	return x;
}
int work(int x,int y,int k){
	int z=lca(x,y);
	if(dep[x]-dep[z]+1>=k)	return calc(x,k-1);
	else{
		k-=dep[x]-dep[z];
		k=dep[y]-dep[z]-k+1;
		return calc(y,k);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(p,0,sizeof(p));
		memset(dep,0,sizeof(dep));
		memset(head,0,sizeof(head));
		tot=0;
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		dfs(1,1,0);
		while(scanf("%s",s)&&s[1]!='O'){
			if(s[1]=='I'){
				scanf("%d%d",&a,&b);
				printf("%d\n",dis[a]+dis[b]-2*dis[lca(a,b)]);
			}
			else{
				scanf("%d%d%d",&a,&b,&c);
				printf("%d\n",work(a,b,c));
			}
		}
	}
	return 0;
}



