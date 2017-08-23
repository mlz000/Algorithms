#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int n,m,l[N];
bool map[N][N],v[N];
void floyd()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(map[i][k] && map[k][j])	map[i][j]=true;
}
bool can(int u)
{
	for(int i=1;i<=n;++i)
		if(!v[i] && map[u][i])
		{
			v[i]=true;
			if(!l[i] || can(l[i]))
			{
				l[i]=u;
				return true;
			}
		}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		map[u][v]=true;
	}
	floyd();
	int sum=0;
	for(int i=1;i<=n;++i)
	{
	    memset(v,false,sizeof(v));
		if(can(i))	++sum;
	}
	printf("%d\n",n-sum);
	return 0;
}
