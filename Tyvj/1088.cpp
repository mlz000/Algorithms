#include<stdio.h>
#include<stdlib.h>
int i,j,n,MAX,a[2001],f[2001][2001]; 
main()
{
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
     f[1][1]=a[1];
     f[1][0]=a[n];
     for (i=2;i<=n;i++)
     {
         for (j=0;j<=i;j++)
         {
             if ((j>0)&&(f[i-1][j-1])&&(f[i][j]<f[i-1][j-1]+a[j]*i))
             f[i][j]=f[i-1][j-1]+a[j]*i;
             if ((j<i)&&f[i-1][j]&&f[i][j]<f[i-1][j]+a[n-(i-j-1)]*i)
             f[i][j]=f[i-1][j]+a[n-(i-j-1)]*i;
         }
     }
      for(i=1;i<=n;i++)
      {
           if(MAX<f[n][i]) MAX=f[n][i];  
      }
      printf("%d",MAX);
}
