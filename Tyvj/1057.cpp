#include<cstdio>
#include<algorithm>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=32005,M=65;
int s[M];//son
struct data 
{
     int l;
     int r;
     int v;
     int w;
}tree[M];
int n,m;
int f[M][N];
int dp(int x,int y)
{
    int j;
    if(f[x][y]!=-1) return f[x][y]; 
    if(x==0 || y<=0) return 0;
   if(tree[x].l==0) //no son
   {
	if(y<tree[x].w)  f[x][y]=dp(tree[x].r,y);
    if(y>=tree[x].w) 
     {
	   f[x][y]=max(dp(tree[x].r,y),tree[x].w+dp(tree[x].r,y-tree[x].v));
       return f[x][y];
	 }
   }
    int tmp=dp(tree[x].r,y);
    for(j=tree[x].v;j<=y;++j)
     {
	   int tmp2=dp(tree[x].l,j-tree[x].v)+dp(tree[x].r,y-j)+tree[x].w;
	   tmp=max(tmp,tmp2);
	 }
	 f[x][y]=tmp;
	 return f[x][y];
}
int main()
{
	int i,v,p,q;
	scanf("%d%d",&n,&m);
	memset(tree,0,sizeof(tree));
	memset(f,-1,sizeof(f));
	tree[0].w=0;
	n=n/10;
	for(i=1;i<=m;++i)
	{
	     scanf("%d%d%d",&v,&p,&q);       
	     v=v/10;
	     tree[i].v=v;
	     tree[i].w=v*p;
	     if(s[q]==0) tree[q].l=i;
	     else tree[s[q]].r=i;
	     s[q]=i;
	}    
	printf("%d",dp(tree[0].l,n)*10);
    return 0;
}
