#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=300005;
int root,f[N],s[N],best,n,m,q;
vector<int>g[N];
int find(int x)	{return f[x]==x?f[x]:find(f[x]);}
void dfs(int fa,int x,int pre,int d){
	f[x]=fa;
	if(d>best)	best=d,root=x;
	for(int i=0;i<g[x].size();++i){
		if(g[x][i]==pre)	continue;
		dfs(fa,g[x][i],x,d+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)	f[i]=i;
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
		if(f[i]==i){
			best=-1,dfs(i,i,0,0);
			best=-1,dfs(i,root,0,0);
			s[i]=best;
		}
	int op,x,y;
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&x);
			int fx=find(x);
			printf("%d\n",s[fx]);
		}
		else{
			scanf("%d%d",&x,&y);
			int fx=find(x);
			int fy=find(y);
			if(fx==fy)	continue;
			if(s[fx]<s[fy])	swap(fx,fy);
			s[fx]=max(s[fx],(s[fx]+1)/2+(s[fy]+1)/2+1);
			f[fy]=fx;
		}
	}
	return 0;
}
