#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=305*2,M=N*N;
int tot,edge[N][2],pos[N],l[N],head[N],to[M],next[M];
bool v[N];
int n,m;
void add(int u,int v)
{
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}	
void make()
{
	for(int i=1;i<=m;++i)
	{
		if(edge[i][1]-edge[i][0]!=1 && edge[i][1]-edge[i][0]!=n-1)
		for(int j=1;j<=m;++j)
		{
			if(i!=j && edge[j][1]-edge[j][0]!=1 && edge[j][1]-edge[j][0]!=n-1)
				if((edge[i][1]-edge[j][0])*(edge[i][1]-edge[j][1])<0)
					if((edge[j][0]-edge[i][0])*(edge[j][0]-edge[i][1])<0)
						add(i,j),add(j,i);
		}
	}
}
void read(int &x)
{
	x=0;
	char c;
  	for(c=getchar();c<'0'||c>'9';c=getchar()); 
    for(;c>='0' && c<='9';x=x*10+c-'0',c=getchar()); 
}
void init()
{
	read(n),read(m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		read(a),read(b);
		if(m<=3*n-6)	edge[i][0]=a,edge[i][1]=b;
	}
	for(int i=1;i<=n;++i)
	{
		int a;
		read(a);
		pos[a]=i;
	}
}
bool dfs(int u)
{
	v[u]=true;
	for(int i=head[u];i;i=next[i])
	{
		int p=to[i];
		if(v[p] && l[u]==l[p])	return false;
		if(!v[p])	
		{
			l[p]=l[u]^1;
			if(!dfs(p))	return false;
		}
	}
	return true;
}
void solve()
{
	if(m>3*n-6)	{printf("NO\n");return ;}
	for(int i=1;i<=m;++i)
	{
		edge[i][0]=pos[edge[i][0]],edge[i][1]=pos[edge[i][1]];
		if(edge[i][0]>edge[i][1])	swap(edge[i][0],edge[i][1]);
	}
	tot=0;
	memset(head,0,sizeof(head));
	memset(v,false,sizeof(v));
	make();	
	for(int i=1;i<=m;++i)
	{
		if((!v[i]) && (!dfs(i)))	{printf("NO\n");return ;}
	}
	printf("YES\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		solve();
	}
	return 0;
}
