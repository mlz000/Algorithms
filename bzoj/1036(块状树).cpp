#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 30005
vector<int>e[N],g[N];
int L,dep[N],fa[N],sum[N],ma[N],own[N],w[N],sz[N];
void build(int x,int f,int d){
	dep[x]=d,fa[x]=f;
	int t=own[x];
	for(int i=0,v;i<g[x].size();++i){
		v=g[x][i];
		if(v!=f){
			if(sz[t]<L)	e[x].pb(v),++sz[t],own[v]=t;
			build(v,x,d+1);
		}
	}
}
void dfs(int x,int s,int m){
	s+=w[x],sum[x]=s,ma[x]=m=max(m,w[x]);
	for(int i=0;i<e[x].size();++i)	dfs(e[x][i],s,m);
}
void change(int x,int t){
	w[x]=t;
	if(x==own[x])	dfs(x,0,-50000);
	else dfs(x,sum[fa[x]],ma[fa[x]]);
}
void query(int x,int y,int &a,int &b){
	a=0,b=-50000;
	while(x!=y){
		if(dep[x]<dep[y])	swap(x,y);
		if(own[x]==own[y])	a+=w[x],b=b>w[x]?b:w[x],x=fa[x];
		else{
			if(dep[own[x]]<dep[own[y]])	swap(x,y);
			a+=sum[x],b=b>ma[x]?b:ma[x],x=fa[own[x]];
		}
	}
	a+=w[x],b=b>w[x]?b:w[x];
}
int main(){
	int n,q;
	scanf("%d",&n);
	L=sqrt(n)+1;
	for(int i=1,a,b;i<n;++i){
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=1;i<=n;++i)	scanf("%d",&w[i]),own[i]=i;
	build(1,0,0);
	for(int i=1;i<=n;++i)	if(own[i]==i)	dfs(i,0,-50000);
	scanf("%d",&q);
	int a,b;
	while(q--){
		char s[10];
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='C')	change(x,y);
		else{
			query(x,y,a,b);
			if(s[1]=='S')	printf("%d\n",a);
			else printf("%d\n",b);
		}
	}
	return 0;
}
