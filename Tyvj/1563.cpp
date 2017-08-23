#include<stdio.h>
#include<string.h>
#include<stdlib.h>
inline int min(int a, int b, int c)
{
    int t=a<b?a:b;
    return c<t?c:t;
}
int a[1501][1501];
int h[1501][1501],z[1501][1501],f[1501][1501];
int main()
{
    int i,j,n,m,max=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
       {
          scanf("%d",&a[i][j]);
       }
       for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
          h[i][j]=1;
          z[i][j]=1;
          f[i][j]=1;
        }
    for(i=1;i<n;i++)
      for(j=1;j<m;j++)   
    {
            if(a[i][j]!=a[i][j+1]) h[i][j+1]=h[i][j]+1;
            else h[i][j+1]=1;
            if(a[i][j]!=a[i+1][j]) z[i+1][j]=z[i][j]+1;
            else z[i+1][j]=1;
           if((a[i][j]==a[i+1][j+1]))
             f[i+1][j+1]=min(f[i][j]+1,h[i+1][j+1],z[i+1][j+1]);   
             if(f[i][j]>=max) max=f[i][j];       
    }
     printf("%d",max);
     system("pause");
     return 0;
}
       
