#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int a[N],sum[N][N];
long long f[N][N];
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
     {
        scanf("%d",&a[i]);
         sum[i][i]=a[i];
     }
      for(i=1;i<=n-1;++i)
      {
         f[i][i+1]=a[i]+a[i+1];
      }
    for(i=1;i<=n;++i)
     for(j=i+1;j<=n;++j)
      sum[i][j]=sum[i][j-1]+a[j];
    for(i=n-1;i>=1;--i)
     for(j=i+1;j<=n;++j)
      {
        f[i][j]=0xfffffff;
        for(k=i;k<=j-1;++k)
        f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[i][j]);
      }
     printf("%lld\n",f[1][n]);
     system("pause");
     return 0;
}
