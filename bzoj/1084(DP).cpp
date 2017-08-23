#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=105,M=3;
int a[N][M],sum[N][M],f[N][N][15],b[N];
int main()
{     
      int i,j,l,n,m,k,p;
      scanf("%d%d%d",&n,&m,&k);
      for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)  scanf("%d",&a[i][j]),sum[i][j]=sum[i-1][j]+a[i][j];
      if(m==1)
      {
        for(i=1;i<=n;i++)    
         for(l=1;l<=k;l++)   
         {
           f[i][l][0]=f[i-1][l][0]; 
           for(j=0;j<i;j++)  f[i][l][0]=max(f[i][l][0],f[j][l-1][0]+sum[i][1]-sum[j][1]);
         }  
        printf("%d",f[n][k][0]);
      }
      else
      {
        for(i=1;i<=n;++i)
         for(j=1;j<=n;++j)
         {
            for(l=1;l<=k;++l)
            {
               f[i][j][l]=max(f[i-1][j][l],f[i][j-1][l]); 
               for(p=0;p<i;++p)     f[i][j][l]=max(f[i][j][l],f[p][j][l-1]+sum[i][1]-sum[p][1]);
               for(p=0;p<j;++p)     f[i][j][l]=max(f[i][j][l],f[i][p][l-1]+sum[j][2]-sum[p][2]);
               if(i==j) for(p=0;p<i;++p)  f[i][j][l]=max(f[i][j][l],f[p][p][l-1]+sum[i][1]-sum[p][1]+sum[j][2]-sum[p][2]);
            }
         }       
         printf("%d",f[n][n][k]);
      }
      return 0;
}
