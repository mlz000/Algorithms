#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int N=350,M=N*N,inf=1000000;
int n,m,S,T,tot,head[N],h[N],d[N],dis[N],pre[N],v[N],c[M],st[M],to[M],next[M];
void add(int u,int v,int w)
{
	c[tot]=w;
	st[tot]=u;
	to[tot]=v;
	next[tot]=head[u];
	head[u]=tot++;
}
int Isap()
{
	int flow=0;
	for(int i=0;i<n;++i)	d[i]=head[i];
	int i=S;v[0]=n;
	int aug=inf;
	while(dis[S]<n)
	{
		bool flag=false;
		h[i]=aug;
		for(int t=d[i];t!=-1;t=next[t])
		{
			int j=to[t];
			if(c[t]>0 && dis[j]+1==dis[i])
			{
				flag=true;
				pre[j]=t;
				d[i]=t;
				if(c[t]<aug)	aug=c[t];
				i=j;
				if(i==T)
				{
					flow+=aug;
					while(i!=S)
					{
						c[pre[i]]-=aug;
						c[pre[i]^1]+=aug;
						i=st[pre[i]];
					}
					aug=inf;
				}
				break;
			}
		}
		if(flag)	continue;
		int MIN=n-1;
		for(int t=head[i];t!=-1;t=next[t])
		{
			if(c[t]>0 && dis[to[t]]<MIN)
			{
				MIN=dis[to[t]];
				d[i]=t;
			}
		}
		v[dis[i]]--;
		if(v[dis[i]]==0)	break;
		dis[i]=MIN+1;
		v[dis[i]]++;
		if(i!=S)
		{
			i=st[pre[i]];
			aug=h[i];
		}
	}
	return flow;
}
int main()
{
	scanf("%d%d",&n,&m);
	S=0,T=n+1;
	memset(head,-1,sizeof(head));
	for(int i=1,x;i<=n;++i)	
	{
		scanf("%d",&x);
		if(x)	add(S,i,1),add(i,S,0);
		else add(i,T,1),add(T,i,0);
	}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	n=n+2;
	printf("%d\n",Isap());
	return 0;
}
