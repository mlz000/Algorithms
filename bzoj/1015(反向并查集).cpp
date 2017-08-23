#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005,M=200005;
int tot,q[N],ans[N],f[N],to[N],head[N],next[N];
bool v[N];
void add(int u,int v) {to[++tot]=v;next[tot]=head[u];head[u]=tot;}
int find(int x)
{
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a+1,b+1);
		add(b+1,a+1);
	}
	int p;
	scanf("%d",&p);
	for(i=1;i<=p;++i) {scanf("%d",&q[i]);q[i]++;v[q[i]]=true;}
	for(i=1;i<=n;++i)	f[i]=i;
	int sum=n-p;
	for(i=1;i<=n;++i)
	{
	 int fi=find(i);
	 if(!v[i])
	 for(j=head[i];j;j=next[j])
	  if(!v[to[j]])	
	  {
		int fj=find(to[j]);
		if(fi!=fj)
		{
			--sum;
			f[fj]=fi;
		}
	  }
    }
    ans[p+1]=sum;
    for(i=p;i>=1;--i)
    {
		++sum;
		int x=q[i];
		int fx=find(x);
		for(j=head[x];j;j=next[j])
		if(!v[to[j]])
		{
			int fj=find(to[j]);
			if(fx!=fj)
			{
				--sum;
				f[fj]=fx;
			}
		}
		ans[i]=sum;
		v[x]=false;
	}
    for(i=1;i<=p+1;++i)	printf("%d\n",ans[i]);
    return 0;
}
