#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
const int N=105;
int n,w[N][N],f[N][N];
bool v[N];
struct data
{
	int l,r,w;
}tree[N];
void dfs(int root)
{
	v[root]=true;
	for(int i=1;i<=n;++i)
	{
		if(!v[i] && w[root][i])
		{
				if(!tree[root].l)	tree[root].l=i;
				else tree[root].r=i;
				tree[i].w=w[root][i];
				dfs(i);
		}
	}
}
int dp(int root,int num)
{
	if(f[root][num])	return f[root][num];
	if(root==0||num==0)	return f[root][num]=0;
	for(int i=0;i<num;++i)
	{
			int lans=dp(tree[root].l,i);
			int rans=dp(tree[root].r,num-i-1);
			if(f[root][num]<lans+rans)	f[root][num]=lans+rans;
	}
	f[root][num]+=tree[root].w;
	return f[root][num];
}
int main()
{
	int i,q;
	int x,y,z;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		w[x][y]=w[y][x]=z;		
	}
	dfs(1);
	memset(v,false,sizeof(v));
	int ans=dp(1,q+1);
	printf("%d",ans);
	return 0;
}
