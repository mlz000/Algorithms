#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10005;
struct data
{
	int u,v,f,s;
}a[N*20];
int n,m,k,f[N];
int get(int x)
{
	if(f[x]==x)	return f[x];
	else return f[x]=get(f[x]);
}
bool check(int X)
{
	int tot=0;
	for(int i=1;i<=n;++i)	f[i]=i;
 	for(int i=1;i<=m;++i)
	if(a[i].f<=X)
	{
		int x=get(a[i].u);int y=get(a[i].v);
		if(x!=y)	f[x]=y,++tot;
	}
	if(tot<k)	return false;
	for(int i=1;i<=m;++i)
		if(a[i].s<=X)
		{
			int x=get(a[i].u);int y=get(a[i].v);
			if(x!=y) 	f[x]=y,++tot;
		}
	return (tot==n-1);
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	int l=1;int r=30010;
	for(int i=1;i<m;++i)	scanf("%d%d%d%d",&a[i].u,&a[i].v,&a[i].f,&a[i].s);
	while(l<=r)
	{
		if(l==r) break;
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}
