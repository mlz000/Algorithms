#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int N=10005,M=100005;
int c[N],f[M][3];
vector<int> g[M];
void dp(int i,int fa)
{
	if(c[i]==1)
	{
		f[i][0]=1;
		f[i][1]=1;
		f[i][2]=0;
		return ;
	}
	if(c[i]==2)
	{
		f[i][0]=1;
		f[i][1]=0;
		f[i][2]=1;
		return ;
	}
	int tmp1=0,tmp2=0,tmp3=0;
	for(int j=0;j<g[i].size();++j)
	{
		int v=g[i][j];
		if(v==fa)	continue;
		dp(v,i);
		tmp1+=f[v][0];
		tmp2+=min(f[v][0],f[v][1]);
		tmp3+=min(f[v][0],f[v][2]);
	}
	f[i][0]=min(tmp1,min(tmp2+1,tmp3+1));
	f[i][1]=min(tmp2,tmp3+1);
	f[i][2]=min(tmp2+1,tmp3);
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)	scanf("%d",&c[i]),c[i]++;
	for(int i=1,x,y;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dp(n+1,0);
	printf("%d\n",f[n+1][0]);
	return 0;
}
