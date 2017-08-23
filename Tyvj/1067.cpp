#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std; 
int a[101],f[101][3];
int main()
{
    int i,j,n,MAX=-1;;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    scanf("%d",&a[i]);
    f[1][1]=1;
    f[n][2]=1;
       for(i=2;i<=n;i++)
     {
       f[i][1]=1;
       for(j=1;j<=i-1;j++)
       {
        if(a[j]<a[i]&&f[i][1]<f[j][1]+1) f[i][1]=f[j][1]+1;
       }               
     }
     for(i=n-1;i>=1;i--)
     {
        f[i][2]=1;
        for(j=n;j>=i-1;j--)
        {
         if(a[j]<a[i]&&f[i][2]<f[j][2]+1) f[i][2]=f[j][2]+1;
        }
     }
     for(i=1;i<=n;i++)
     {
      if(f[i][1]+f[i][2]>MAX) MAX=f[i][1]+f[i][2]-1;
     }
    printf("%d",n-MAX);
    //system("pause");
    return 0;
}
