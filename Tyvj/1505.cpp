#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[52][52],sum[52][52],f[52][52][502];
int main()
{
      int i,j,k,n,m,MAX;
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
       for(j=1;j<=n+1-i;j++)
            scanf("%d",&a[i][j]);
       for(i=1;i<=n;++i)
          for(j=1;j<=n+1-i;j++)
            sum[i][j]=sum[i-1][j]+a[i][j];
        for(j=1;j<=n;j++)
      {
         for(k=1;k<=m;k++)   
        {
            f[0][j][k]=max(f[0][j-1][k],f[1][j-1][k]);
        } 
         for(i=1;i<=n+1-j;i++)
          for(k=i;k<=m;k++)
         {
           f[i][j][k]=max(f[i-1][j][k-1]+a[i][j],f[i+1][j-1][k-i]+sum[i][j]);
         }
      }
        MAX=max(f[1][n][m],f[0][n][m]); 
        printf("%d",MAX);
        //system("pause");
        return 0;
} 
