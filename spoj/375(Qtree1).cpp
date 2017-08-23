#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;
#define mid ((l+r)>>1)
#define lr root<<1
#define rr (lr)|1
const int N=20005;
int n,tot,pre[N],son[N],head[N],next[N],to[N],dep[N],top[N],q[N],size[N],id[N],d[N][3],MAX[N];
bool v[N];
void add(int u,int v,int w)
{
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
inline void updata(int root)	{MAX[root]=max(MAX[lr],MAX[rr]);}
void build(int root,int l,int r,int id,int w)
{
	if(l==r)	{MAX[root]=w;return ;}
	if(id<=mid) build(lr,l,mid,id,w);
	else build(rr,mid+1,r,id,w);
	updata(root);
}
int get(int root,int l,int r,int a,int b,int now)
{
	if(a<=l && b>=r)	return max(MAX[root],now);
	int tmp1=INT_MIN,tmp2=INT_MIN;
	if(a<=mid)	tmp1=get(lr,l,mid,a,b,now);
	if(b>mid)	tmp2=get(rr,mid+1,r,a,b,now);
	return max(tmp1,tmp2);
}	
int ask(int root,int l,int r,int a,int b)
{
	int tmp=INT_MIN;
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]])	swap(a,b);
		tmp=max(tmp,get(1,1,n,id[top[a]],id[a],tmp));
		a=pre[top[a]];				
	}
	if(dep[a]>dep[b])	swap(a,b);
	tmp=max(tmp,get(1,1,n,id[son[a]],id[b],tmp));
	return tmp;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		memset(son,0,sizeof(son));
		memset(dep,0,sizeof(dep));
		memset(size,0,sizeof(size));
		memset(head,0,sizeof(head));
		memset(MAX,0xc3,sizeof(MAX));
		memset(q,0,sizeof(q));
		memset(next,0,sizeof(next));
		memset(to,0,sizeof(to));
		memset(pre,0,sizeof(pre));
		memset(top,0,sizeof(top));
		memset(v,false,sizeof(v));
		scanf("%d",&n);
		for(int i=1;i<n;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
			d[i][0]=a;
			d[i][1]=b;
			d[i][2]=c;
		}
		v[dep[1]=q[0]=1]=true;
		int r=0;
		for(int l=0;l<=r;++l)
		 for(int k=head[q[l]];k;k=next[k])
		 {
			if(!v[to[k]])
			{
				v[to[k]]=true;
				dep[q[++r]=to[k]]=dep[q[l]]+1;
				pre[q[r]]=q[l];
			}
		 }
		for(int i=r;i>=0;--i)
		{
			size[pre[q[i]]]+=++size[q[i]];
			if(size[q[i]]>size[son[pre[q[i]]]])
			son[pre[q[i]]]=q[i];
		}
		tot=0;
		for(int l=0;l<=r;++l)
		{
			if(!top[q[l]])
			{
				for(int k=q[l];k;k=son[k])
				{
					top[k]=q[l];
					id[k]=++tot;
				}
			}
		}
		for(int i=1;i<n;++i)
		{
			if(dep[d[i][0]]<dep[d[i][1]])	swap(d[i][0],d[i][1]);
			build(1,1,n,id[d[i][0]],d[i][2]);
		}
		char s[10];
		while(scanf("%s",s)&&s[0]!='D')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(s[0]=='C')	build(1,1,n,id[d[x][0]],y);
			else if(s[0]=='Q')	printf("%d\n",ask(1,1,n,x,y));
		}
	}
	return 0;
}
