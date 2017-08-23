#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=15;
double g[N][N],a[N][N];
double eps=1e-6;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n+1;++i) 	
     for(j=1;j<=n;++j)
     scanf("%lf",&g[i][j]);
    for(i=1;i<=n;++i)
		for(j=1;j<=n;++j) 
		{
			a[i][j]=(g[i+1][j]-g[i][j])*2;
			a[i][n+1]+=g[i+1][j]*g[i+1][j]-g[i][j]*g[i][j];
		}
	for(i=1;i<=n;++i)
	{
		k=i;
		while(fabs(a[k][i])<=eps)  ++k;
		if(k!=i) for(j=1;j<=n+1;++j)  swap(a[i][j],a[k][j]);
		for(j=n+1;j>=i;--j)	a[i][j]/=a[i][i];
		for(j=1;j<=n;++j)
		{
			if(j!=i)
			for(k=n+1;k>=i;--k)	a[j][k]-=a[j][i]*a[i][k]; 
		}
	}	
	for(i=1;i<=n-1;++i)  printf("%.3lf ",a[i][n+1]);
    printf("%.3lf",a[n][n+1]);
    return 0;
}
