#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MID(x,y) ((x+y)>>1)  
#define L(x) ( x << 1 )  
#define R(x) ( x << 1 | 1 )  
const int N=10005;
int n,x[N*2],co[N<<1];
struct data	{int l,r,col;}a[N],tree[N*4];
void build_tree(int root,int l,int r)
{
	tree[root].l=l,tree[root].r=r,tree[root].col=1;
	if(l==r-1)	return;
	int mid=MID(l,r);
	build_tree(L(root),l,mid);
	build_tree(R(root),mid,r);
}
void updata(int root,int l,int r,int col)
{
	if(tree[root].l==l && tree[root].r==r)
	{
		tree[root].col=col;
		return ;
	}
	if(tree[root].col>=0 && tree[root].col!=col)
	{
		tree[L(root)].col=tree[R(root)].col=tree[root].col;
		tree[root].col=-1;
	}
	int mid=MID(tree[root].l,tree[root].r);
	if(l>=mid)		updata(R(root),l,r,col);
	else if(r<=mid)	updata(L(root),l,r,col);
	else updata(L(root),l,mid,col),updata(R(root),mid,r,col);
}
void ask(int root,int l,int r)
{
	if(tree[root].col>=0)	{for(int i=tree[root].l;i<tree[root].r;++i)	co[i]=tree[root].col;return;}
	int mid=MID(tree[root].l,tree[root].r);
	if(l>=mid)	ask(R(root),l,r);
	else if(r<=mid)	ask(L(root),l,r);
	else ask(L(root),l,mid),ask(R(root),mid,r);
}
void solve(int x[],int cnt)
{
	build_tree(1,0,cnt);
	for(int i=0;i<=n;++i)
	{
		int xx=lower_bound(x,x+cnt,a[i].l)-x;
		int yy=lower_bound(x,x+cnt,a[i].r)-x;
		updata(1,xx,yy,a[i].col);
	}
	ask(1,0,cnt);
	int h,r;
	h=r=0;
	x[cnt]=1000000000;
	co[cnt]=0;
	for(int i=0;i<cnt;++i)
	{
		int hh=x[i];
		while(co[i]==1)	++i;
		int rr=x[i];
		if(rr-hh>r-h)
		{
			r=rr;
			h=hh;
		}
	}
	printf("%d %d\n",h,r);
}
int main()
{
	int i;
	scanf("%d",&n);
	char s[5];
	int cnt=0;
	a[0].l=0,a[0].r=1000000000,a[0].col=1;
	x[cnt++] = a[0].l; x[cnt++] = a[0].r;  
	for(int i=0;i<=N*2;++i)	co[i]=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%s",&a[i].l,&a[i].r,s);
		x[cnt++]=a[i].l;
		x[cnt++]=a[i].r;
		if(s[0]=='w')	a[i].col=1;
	}
	sort(x,x+cnt);
	cnt=unique(x,x+cnt)-x;
	solve(x,cnt);
	return 0;
}
