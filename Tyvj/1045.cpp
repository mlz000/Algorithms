#include<stdio.h>
#include<algorithm> 
#include<stdlib.h>
using namespace std;
int a[20],sum[20],f[20][20];
int main()
{
   int i,j,l,n,k;
   scanf("%d%d",&n,&k);
   for(i=1;i<=n;++i)
   {
     scanf("%d",&a[i]);
     sum[i]=sum[i-1]+a[i];
   }
   f[1][0]=a[1];
   for(i=1;i<=n;i++)
    f[i][0]=sum[i];
   for(j=1;j<=k;j++)
    for(i=j+1;i<=n;i++)
     for(l=j;l<=i;l++)
    {
       f[i][j]=max(f[i][j],f[l][j-1]*(sum[i]-sum[l]));
    }
    printf("%d",f[n][k]);
   // system("pause");
    return 0;
}
