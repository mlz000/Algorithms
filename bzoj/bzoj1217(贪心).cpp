#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=1005;
int n,tot,head[N],fa[N],dep[N],id[N],next[N<<1],to[N<<1];
bool v[N];
struct data{
	int dep,id;
}a[N];
bool operator <(const data &x,const data &y){
	return x.dep>y.dep;
}
void add(int u,int v){
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
void dfs(int x,int f){
	a[x].dep=a[f].dep+1,a[x].id=x;
	for(int e=head[x];e;e=next[e]){
		if(to[e]!=f){
			fa[to[e]]=x;
			dfs(to[e],x);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2,x;i<=n;++i){
		scanf("%d",&x);
		add(i,x);
		add(x,i);
	}
	dfs(1,0);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		if(!v[a[i].id]){
			++ans;
			v[fa[fa[a[i].id]]]=true;
			for(int e=head[fa[fa[a[i].id]]];e;e=next[e]){
				v[to[e]]=true;
				for(int ee=head[to[e]];ee;ee=next[ee])	v[to[ee]]=true;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
