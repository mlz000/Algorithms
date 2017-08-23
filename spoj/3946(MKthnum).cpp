#include<cstdio>//可持久化线段树
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100005;
int tot,a[N],b[N],l[N*20],r[N*20],d[N*20],root[N*20];
void insert(int x,int &y,int L,int R,int w)
{
	d[y=++tot]=d[x]+1;
	int mid=(L+R)>>1;
	if(L==R)	return ;
	if(w<=mid)
	{
		r[y]=r[x];
		insert(l[x],l[y],L,mid,w);
	}
	else 
	{
		l[y]=l[x];
		insert(r[x],r[y],mid+1,R,w);
	}
}
int ask(int x,int y,int L,int R,int w)
{
	if(L==R)	return L;
	int mid=(L+R)>>1;
	if(w<=d[l[y]]-d[l[x]])	return ask(l[x],l[y],L,mid,w);
	else return ask(r[x],r[y],mid+1,R,w-d[l[y]]+d[l[x]]);
}
int main()
{
	int n,q,m;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i)	insert(root[i-1],root[i],1,m,lower_bound(b+1,b+n+1,a[i])-b);
	while(q--)
	{
		int ql,qr,k;
		scanf("%d%d%d",&ql,&qr,&k);
		printf("%d\n",b[ask(root[ql-1],root[qr],1,m,k)]);
	}
	return 0;
}
