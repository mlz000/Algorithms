#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20005;
long long inf=(1ll<<60);
struct data	{long long x,y;}a[N];
int n,vis[N];
void find(long long &MINX,long long &MAXX,long long &MINY,long long &MAXY)
{
	MINX=inf,MINY=inf,MAXX=-inf,MAXY=-inf;
	for(int i=1;i<=n;++i)
    if(!vis[i])
	{
        MAXX=max(MAXX, a[i].x);
        MAXY=max(MAXY, a[i].y);
        MINX=min(MINX, a[i].x);
        MINY=min(MINY, a[i].y);
   	}
}
bool dfs(long long L,int dep)
{
	long long MINX,MAXX,MINY,MAXY;
	find(MINX,MAXX,MINY,MAXY);
	if(MAXX==-inf) return true;
	if(dep==3)
	{
		return (MAXX-MINX<=L && MAXY-MINY<=L);
	}
	for(int i=1;i<=n;++i)	
		if(!vis[i])
		{
			if(a[i].x>=MAXX-L && a[i].x<=MAXX && a[i].y>=MAXY-L && a[i].y<=MAXY) vis[i]=dep;
		}
	if(dfs(L,dep+1)) return true;
	for(int i=1;i<=n;++i)
		if(vis[i]==dep) vis[i]=0;
	for(int i=1;i<=n;++i)	
		if(!vis[i])
		{
			if(a[i].x>=MAXX-L && a[i].x<=MAXX && a[i].y>=MINY && a[i].y<=MINY+L) vis[i]=dep;
		}
	if(dfs(L,dep+1)) return true;
	for(int i=1;i<=n;++i)
		if(vis[i]==dep) vis[i]=0;
	for(int i=1;i<=n;++i)	
		if(!vis[i])
		{
			if(a[i].x>=MINX && a[i].x<=MINX+L && a[i].y>=MINY && a[i].y<=MINY+L) vis[i]=dep;
		}	
	if(dfs(L,dep+1)) return true;
	for(int i=1;i<=n;++i)
		if(vis[i]==dep) vis[i]=0;
	for(int i=1;i<=n;++i)	
		if(!vis[i])
		{
			if(a[i].x>=MINX && a[i].x<=MINX+L && a[i].y>=MAXY-L && a[i].y<=MAXY) vis[i]=dep;
		}
	if(dfs(L,dep+1)) return true;
	for(int i=1;i<=n;++i)
		if(vis[i]==dep) vis[i]=0;
	return false;
}
bool check(long long L)
{
	memset(vis,0,sizeof(vis));
	return dfs(L,1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%lld%lld",&a[i].x,&a[i].y);
	long long MINX,MAXX,MINY,MAXY;
	find(MINX,MAXX,MINY,MAXY);
	long long l=0ll;
	long long r=max(MAXX-MINX,MAXY-MINY);
	while(l<=r)
	{
		if(l==r)	break;
		int mid=(l+r)>>1;
		if(check(mid))	r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}

