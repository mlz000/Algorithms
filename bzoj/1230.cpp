
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100000;
struct data
{
     int add;
     int l;
     int r;
}tree[4*N];
void build(int root,int l,int r);
void updata(int root,int l,int r);
int main()
{
	int n,m;
	int a,b,c;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(i=1;i<=m;++i)
	 {
	   scanf("%d%d%d",&a,&b,&c);
	   if(a==0) updata(1,a,b);
	 }
}
void build(int root,int l,int r)
{
     tree[root].add=0;
     tree[root].l=l;
     tree[root].r=r;
     int mid=(l+r)>>1;
     if(l<r)
     {
		 build(root<<1,l,mid);
         build((root<<1)+1,mid+1,r);
     }
}
void updata(int root,int l,int r)
{
         if(tree[root].add)  //已操作过
         {
			 tree[root<<1].add=!tree[root<<1].add;
			 tree[(root<<1)+1].add=!tree[root].add;
			 tree[root].add=0;
		 }
		 

}
