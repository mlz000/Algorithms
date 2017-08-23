#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std; 
int a[5001],f[5001];
int main()
{
     int i,j,n;
     scanf("%d",&n);
     for(i=1;i<=n;++i)
     scanf("%d",&a[i]);
     f[1]=1;
     for(i=2;i<=n;i++)
     {
       f[i]=1;
       for(j=1;j<=i-1;j++)
       {
        if(a[j]<=a[i]&&f[i]<f[j]+1) f[i]=f[j]+1;
       }               
     }
     for(i=1;i<=n;++i)
     {
      if(f[0]<f[i]) f[0]=f[i];
     }
     printf("%d",f[0]);
     system("pause");
     return 0;
}
