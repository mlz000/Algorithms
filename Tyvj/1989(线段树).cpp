#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue> 
#include<cstring>
using namespace std;
const int N=500010;
long long a[N],sum[N];
struct data
{
   int l;
   int r;
   long long add;
   long long sum;
}node[N*4];
void build_tree(int root,int l,int r);
void add(int root,int l,int r,long long plus);
void calc(int root,int p,int i); 
int main()
{
	int i,n,q1,q2;
	scanf("%d%d%d",&n,&q1,&q2);
	for(i=1;i<=n;++i)
	  scanf("%I64d",&a[i]);
	build_tree(1,1,n);
	int aa,bb,t;
	for(i=1;i<=q1;++i)
	{
	   scanf("%d%d%d",&aa,&bb,&t);
	   add(1,aa,bb,t);
	}  
	for(i=1;i<=q2;++i)
	{
	  int p;
	  scanf("%d",&p);
	  calc(1,p,i);
	}
	for(i=1;i<=q2;++i)
	 printf("%I64d\n",sum[i]);
//	system("pause");
	return 0;
} 
void build_tree(int root ,int l,int r)
{
    node[root].l=l;
    node[root].r=r;
	node[root].add=0;
	if(l==r) 
	{
		node[root].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;  		
    build_tree(root*2,l,mid);
	build_tree(root*2+1,mid+1,r); 
    node[root].sum=node[root*2].sum+node[root*2+1].sum;
}
void add(int root,int l,int r,long long plus)
{
    if(node[root].l==l && node[root].r==r)//ÂúÇø¼ä
	 {node[root].add+=plus;return;}
	node[root].sum+=(r-l+1)*plus;
	int mid=(node[root].l+node[root].r)>>1;
	if(r<=mid) add(root*2,l,r,plus);
	else if(l>mid) add(root*2+1,l,r,plus);
	else 
	{
	  add(root*2,l,mid,plus);
	  add(root*2+1,mid+1,r,plus);
	}  
} 
void calc(int root,int p,int i)
{     
     if(node[root].add!=0)
     {
	     node[root].sum+=(node[root].r-node[root].l+1)*node[root].add;
	     node[root*2].add+=node[root].add;
	     node[root*2+1].add+=node[root].add;
	     node[root].add=0;
	 }
	 if(node[root].l==node[root].r && node[root].l==p) {sum[i]=node[root].sum;return;}
     int mid=(node[root].l+node[root].r)>>1;
	 if(p<=mid) calc(root*2,p,i);
	 if(p>mid) calc(root*2+1,p,i); 
}

