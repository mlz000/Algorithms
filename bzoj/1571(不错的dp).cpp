#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10005,M=105;
int f[N][M],h[N][M],g[N],u[M];
int main()
{
	int t,s,n,m,l,a,c,d;
	int i,j;
	scanf("%d%d%d",&t,&s,&n);
	++t;
	for(i=1;i<=s;++i)	
	{
		scanf("%d%d%d",&m,&l,&a);
		++m;
		h[m+l][a]=max(h[m+l][a],m);
	}
	for(i=1;i<=M;++i)	u[i]=N;		
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&c,&d);
		for(j=c;j<=100;++j)	u[j]=min(u[j],d);
	} 
	f[0][1]=0;
	for(i=2;i<=M;++i)	f[0][i]=-N;
	for(i=1;i<=t;++i)
	 for(j=1;j<=100;++j)
	 {
		f[i][j]=f[i-1][j];
		if(h[i][j])	f[i][j]=max(f[i][j],g[h[i][j]]);
		if(u[j]<N && i>=u[j])	f[i][j]=max(f[i][j],f[i-u[j]][j]+1);
		g[i]=max(g[i],f[i][j]);
	 }
	printf("%d",g[t]); 
    return 0;
}
