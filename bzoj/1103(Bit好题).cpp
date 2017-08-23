#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=250005;
int l[N],r[N],fa[N],head[N],to[N*2],next[N*2],c[N*2];
int n,tot=0;
void addedge(int u,int v)
{
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
void add(int i,int x)
{
	for(;i<=n*2;i+=i&-i)	c[i]+=x;		
}
void dfs(int cur)
{
	++tot,l[cur]=tot,add(tot,1);
	for(int i=head[cur];i;i=next[i])
	{
		int v=to[i];
		if(fa[cur]!=v)
		{
			fa[v]=cur;
			dfs(v);
		}
	}
	++tot,r[cur]=tot,add(tot,-1);
}
int get(int i)
{
	int tmp=0;
	for(;i;i-=i&-i)	tmp+=c[i];
	return tmp;
}
int main()
{
	int m;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	scanf("%d",&m);
	tot=0;
	dfs(1);
	m+=n-1;
	while(m--)
	{
		char s[5];int a,b;
		scanf("%s%d",s,&a);
		if(s[0]=='A')
		{
			scanf("%d",&b);
			if(fa[a]==b)	swap(a,b);
			add(l[b],-1);
			add(r[b],1);
		}
		else printf("%d\n",get(l[a])-1);
	}
	return 0;
}
