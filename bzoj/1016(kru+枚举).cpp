#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105,M=10005,MOD=31011;
int f[N],use[M],p[15];
int n,m,MIN;
int ans=1;
struct data {int u,v,w;}edge[M];
int find(int x)
{
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
inline bool cmp(const data p,const data q)	{return p.w<q.w;}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)	scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(&edge[1],&edge[m+1],cmp);
	int tot=1;
	for(int i=1;i<=m;++i)
	{
		if(edge[i].w!=edge[i+1].w) edge[i].w=tot++;
		else edge[i].w=tot;//离散化
	}
}
int kru()
{
	int cnt=n;
	for(int i=1;i<=n;++i)	f[i]=i;
	for(int i=1;i<=m && cnt>1;++i)
	{
		int fu=find(edge[i].u);
		int fv=find(edge[i].v);
		if(fu!=fv)
		{
			f[fv]=fu;
			cnt--;
			use[edge[i].w]++;
			MIN+=edge[i].w;
		}
		if(cnt==1) break;
	}
	if(cnt!=1) {printf("0");return 0;}
	return 1;
}
bool check(int x,int k)
{
	int cnt=n;
	int tmp=edge[x].w*use[edge[x].w];
	for(int i=1;i<=n;++i)	f[i]=i;
	for(int i=x;edge[i].w==edge[x].w;++i)
	{
		if(k&1)
		{
			int fu=find(edge[i].u);
			int fv=find(edge[i].v);
			if(fu!=fv)
			{
				f[fv]=fu;
				cnt--;
			}
		}
		k=k>>1;
	}
	for(int i=1;i<=m && cnt>1;++i)
	{
		if(edge[i].w==edge[x].w) continue;
		int fu=find(edge[i].u);
		int fv=find(edge[i].v);
		if(fu!=fv)
		{
			f[fv]=fu;
			cnt--;
			tmp+=edge[i].w;
		}
		if(cnt==1) break;
	}
	return (cnt==1 && tmp==MIN);
}
void solve()
{
	p[0]=1;
	int tot;
	for(int i=1;i<=10;++i)	p[i]=p[i-1]<<1;
	for(int i=1;i<=m;)
	{
		int j=i+1;
		while(edge[i].w==edge[j].w)	j++;
		if(use[edge[i].w])
		{
		    tot=0;
			for(int k=0;k<p[j-i];++k)  if(__builtin_popcount(k)==use[edge[i].w] && check(i,k)) tot++;
     		ans=ans*tot%MOD;
		}
		i=j;
	}
}
int main()
{
//	freopen("1.in","r",stdin);
	init();
	if(!kru()) return 0; 
	solve();
	printf("%d",ans);
    return 0;
}
