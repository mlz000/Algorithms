#include<cstdio>   //树形DP 多叉转二叉，左孩子右兄弟 
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
const int N=505;
int f[N]; //f[i]=j i的孩纸是j 
int a[N];
int dp[N][N];
int n,m;
struct data
{
    int l;
    int r;
    int w;
}tree[N*2];
int dfs(int node,int num)
{
	  if(dp[node][num]!=-1) return dp[node][num];
      if(node==0 || num==0) return 0;
    dp[node][num]=dfs(tree[node].r,num);
    int k;
    for(k=1;k<=num;++k)
     {
		int t=dfs(tree[node].l,k-1)+dfs(tree[node].r,num-k)+tree[node].w;
        if(t>dp[node][num]) dp[node][num]=t;
	 }  
     return dp[node][num];
}
int main()
{
	  int i,j,tmp;
	  memset(tree,0,sizeof(tree));
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
       {
		 scanf("%d%d",&tmp,&tree[i].w);
		 if(f[tmp]==0) tree[tmp].l=i;
		 else tree[f[tmp]].r=i;
		 f[tmp]=i;
	   }
	   memset(dp,-1,sizeof(dp));
	   int ans=dfs(tree[0].l,m);
       printf("%d",ans);
    // system("pause");
       return 0;

}
