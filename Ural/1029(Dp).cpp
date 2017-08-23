#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int M=150,N=550,INF=0x7fffffff-1;
int a[M][N],ans[M*N];
long long f[M][N];
struct data	{int l,r;}pre[M][N];
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	 for(int j=1;j<=n;++j)
	 {
		 scanf("%d",&a[i][j]);
		 f[i][j]=INF;
	 }
	for(int j=1;j<=n;++j)	f[1][j]=a[1][j];
	for(int i=2;i<=m;++i)
	{
	 for(int j=1;j<=n;++j)
	 {
	 	if(f[i-1][j]!=INF)	
		{
			if(f[i][j]>f[i-1][j]+a[i][j])
			{
				f[i][j]=f[i-1][j]+a[i][j];
				pre[i][j].l=i-1;
				pre[i][j].r=j;
			}
		}
		if(j>1 && f[i][j-1]!=INF)
	    {
			 if(f[i][j]>f[i][j-1]+a[i][j])
			 {
				 f[i][j]=f[i][j-1]+a[i][j];
				 pre[i][j].l=i;
				 pre[i][j].r=j-1;
			 }
	    }
	 }
	 for(int j=n-1;j>=1;--j)
	 {
		 if(f[i][j+1]!=INF)
		 {
			 if(f[i][j]>f[i][j+1]+a[i][j])
			 {
				 f[i][j]=f[i][j+1]+a[i][j];
				 pre[i][j].l=i;
				 pre[i][j].r=j+1;
			 }
		 }
	 }
	}
	int tr=1;
	for(int j=2;j<=n;++j)
	 if(f[m][j]<f[m][tr])	tr=j;
	int tl=m;
	int tot=0;
	while(tl && tr)
	{
		ans[++tot]=tr;
		int t1=pre[tl][tr].l;
		int t2=pre[tl][tr].r;
		tl=t1;
		tr=t2;
	}
	for(int i=tot;i>=1;--i)	printf("%d ",ans[i]);
	return 0;
}
