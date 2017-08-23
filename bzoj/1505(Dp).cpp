#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define sqr(x)	((x)*(x))
const int N=105;
double f[N][N][N],s[N][N],S[N];
int main()
{
	double k1,k2;int m,n;
	scanf("%lf%lf%d%d",&k1,&k2,&m,&n);
	for(int i=0;i<=100;++i)
		for(int j=0;j<=m;++j)
			for(int k=0;k<=n;++k)	
				f[i][j][k]=100000000;
	for(int i=0;i<=100;++i)	
		for(int j=0;j<=n;++j)
			s[i][j]=10000000;
	f[0][0][0]=s[0][0]=0;
	for(int i=1;i<=100;++i)	S[i]=k1*sqr(i);
	for(int i=1;i<=100;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=i;++k)
			s[i][j]=min(s[i][j],s[i-k][j-1]+k2*sqr(k));
	for(int i=1;i<=100;++i)
		for(int j=1;j<=min(i,m);++j)
			for(int k=1;k<=min(i,n);++k)
				for(int l=1;l<=i;++l)
					for(int p=1;p<=min(l,k);++p)
						f[i][j][k]=min(f[i][j][k],f[i-l][j-1][k-p]+S[l]+s[l][p]);
	printf("%.1lf",f[100][m][n]);
	return 0;
}
