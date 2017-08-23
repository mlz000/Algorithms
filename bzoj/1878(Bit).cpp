#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,pre[N],last[1000005];
long long c[N],ans[N];
struct data {int l,r,p;}q[N];
bool cmp(const data x,const data y)
{
	return x.r<y.r;
}
void add(int x,int k)
{
	for(;x<=n;x+=x&-x)
	  c[x]+=k;	
}
long long ask(int x)
{
	long long tmp=0ll;
	for(;x;x-=x&-x)
	 tmp+=c[x];
	return tmp;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		pre[i]=last[x];
		last[x]=i;
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i)	{scanf("%d%d",&q[i].l,&q[i].r);q[i].p=i;}
	sort(&q[1],&q[m+1],cmp);
	int now=0;
	for(i=1;i<=m;++i)
	{
		while(now<q[i].r)
		{
			++now;
			add(pre[now]+1,1);
			if(now!=n) add(now+1,-1);
		}
		ans[q[i].p]=ask(q[i].l);
	}
	for(i=1;i<=m;++i)	printf("%lld\n",ans[i]);
	return 0;
}
