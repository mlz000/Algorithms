#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int f[105],g[105];
bool flag;
int find(int k)
{
	if(f[k]==k)	return k;
	find(f[k]);
	g[k]+=g[f[k]];//g[k]表示k和父亲的差
	return f[k]=f[f[k]];
}
void Union(int x,int y,int w)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		f[fx]=fy;
		g[fx]=g[y]-g[x]-w;
	}
	else if(g[y]-g[x]!=w)	flag=false;
}
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
    	flag=true;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;++i)	f[i]=i,g[i]=0;
		for(int i=1;i<=m;++i)
		{
			int s,t,v;
			scanf("%d%d%d",&s,&t,&v);
			Union(s-1,t,v);
		}
		if(!flag)	printf("false\n");
		else printf("true\n");
	}
	return 0;
}
