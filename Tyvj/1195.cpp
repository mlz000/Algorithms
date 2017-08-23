#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std; 
int a[101],b[101],c[101],f[101][3];
int main()
{
   int i,j,n,m;
   scanf("%d",&n);
   for(i=1;i<=n;++i)
   scanf("%d%d%d",&a[i],&b[i],&c[i]);
   f[1][1]=a[1]+c[1];
   f[1][2]=b[1];
    for(i=2;i<=n;++i)
    {
      f[i][1]=min(f[i-1][1]+a[i],f[i-1][2]+a[i]+c[i]);
      f[i][2]=min(f[i-1][2]+b[i],f[i-1][1]+b[i]+c[i]);
    }
    printf("%d",min(f[n][1],f[n][2]));
    //system("pause");
    return 0;
} 
